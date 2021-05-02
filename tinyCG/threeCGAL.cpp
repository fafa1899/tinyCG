#include "threeCGAL.h"

namespace tinyCG
{

threeCGAL::threeCGAL()
{

}

double threeCGAL::CalDistancePointAndLine(Vec3d &point, Vec3d &lineBegin, Vec3d &lineEnd)
{
    //直线方向向量
    Vec3d n = lineEnd -lineBegin;

    //直线上某一点的向量到点的向量
    Vec3d m = point - lineBegin;

    return (n ^ m).length() / n.length();
}

//计算三点成面的法向量
void threeCGAL::CalNormal(const Vec3d& v1, const Vec3d& v2, const Vec3d& v3, Vec3d &vn)
{
    //v1(n1,n2,n3);
    //平面方程: na * (x – n1) + nb * (y – n2) + nc * (z – n3) = 0 ;
    double na = (v2.y()-v1.y())*(v3.z()-v1.z())-(v2.z()-v1.z())*(v3.y()-v1.y());
    double nb = (v2.z()-v1.z())*(v3.x()-v1.x())-(v2.x()-v1.x())*(v3.z()-v1.z());
    double nc = (v2.x()-v1.x())*(v3.y()-v1.y())-(v2.y()-v1.y())*(v3.x()-v1.x());

    //平面法向量
    vn.set(na,nb,nc);
}

}
