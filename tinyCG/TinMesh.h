#ifndef TINMESH_H
#define TINMESH_H

#include "tinyCG_global.h"

#include <Vec3.hpp>
#include <triangleEx.hpp>
#include <LineSegment.hpp>

#include <vector>
#include <set>

namespace tinyCG
{

//通过智能指针使用比较好
class TINYCG_EXPORT TinMesh
{
public:
    TinMesh();

    void Init();

    bool GetZ(double x, double y, double &z);

    //计算线段之后才有线段列表
    void GetLineSegment();
    std::vector<LineSegmentD> lineSegments;

    std::vector<Vec3d> vertexs;
    std::vector<size_t> indices;

    std::vector<TriangleExD> triangles;



protected:
    void InsertLineSegment(size_t id1, size_t id2, std::set<Vec2ul>& lineSegmentIndices);
};

}
#endif // TINMESH_H
