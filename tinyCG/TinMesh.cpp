#include "TinMesh.h"

#include <iostream>

using namespace std;

namespace tinyCG
{

TinMesh::TinMesh()
{
}

void TinMesh::Init()
{
//    //交换而不是替换,避免传入的数据超出作用域被释放
//    vertexs.swap(v);
//    indices.swap(i);

    size_t triangleNum = indices.size() / 3;
    triangles.resize(triangleNum);

    for(size_t i = 0; i < triangles.size(); i++)
    {
        triangles[i].Set(&(vertexs[indices[i * 3]]), &(vertexs[indices[i * 3 + 1]]),
                &(vertexs[indices[i * 3 + 2]]));
    }
}

void TinMesh::InsertLineSegment(size_t id1, size_t id2, set<Vec2ul>& lineSegmentIndices)
{
    Vec2ul p00(id1, id2);
//    Vec2ul p01(id2, id1);
//    if(lineSegmentIndices.find(p00) == lineSegmentIndices.end() &&
//            lineSegmentIndices.find(p01) == lineSegmentIndices.end())
//    {
//        lineSegmentIndices.insert(p00);
//    }

    lineSegmentIndices.insert(p00);
}

void TinMesh::GetLineSegment()
{
    size_t triangleNum = indices.size() / 3;

    set<Vec2ul> lineSegmentIndices;
    for(size_t i = 0; i < triangleNum; i++)
    {
        InsertLineSegment(indices[i * 3], indices[i * 3 + 1], lineSegmentIndices);
        InsertLineSegment(indices[i * 3], indices[i * 3 + 2], lineSegmentIndices);
        InsertLineSegment(indices[i * 3 + 1], indices[i * 3 + 2], lineSegmentIndices);
    }

    for(auto item : lineSegmentIndices)
    {
        lineSegments.push_back(LineSegmentD(vertexs[indices[item.x()]], vertexs[indices[item.y()]]));
    }
}

bool TinMesh::GetZ(double x, double y, double &z)
{
    for(size_t i = 0; i < triangles.size(); i++)
    {
        if(x < triangles[i].min.x() || x > triangles[i].max.x() ||
                y < triangles[i].min.y() || y > triangles[i].max.y())
        {
            continue;
        }

        Vec3d p(x, y, 0);
        if(triangles[i].PointInTriangle2D(p))
        {
            triangles[i].CalPlanePointZ(p);
            z = p.z();
            return true;
        }
    }

    return false;
}

}
