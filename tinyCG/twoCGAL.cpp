#include "twoCGAL.h"
#include <iostream>
#include <algorithm>

using namespace std;

namespace tinyCG
{

twoCGAL::twoCGAL()
{
}

//已知线段上某点与起点的距离，求该点的坐标
//具体实现
template<class T>
void CalPointFromLineWithDistance_T(const Vec2<T>& O, const Vec2<T>& E, T d, Vec2<T>& P)
{
    Vec2<T> D = E - O;
    T t = d / D.length();
    P = O + D*t;
}
void twoCGAL::CalPointFromLineWithDistance_D(const Vec2d & O, const Vec2d & E, double d, Vec2d& P)
{
    CalPointFromLineWithDistance_T<double>(O, E, d, P);
}
void twoCGAL::CalPointFromLineWithDistance_F(const Vec2f & O, const Vec2f & E, float d, Vec2f& P)
{
    CalPointFromLineWithDistance_T<float>(O, E, d, P);
}



//两矩形是否相交
bool twoCGAL::RectIntersect(double minx1, double miny1,double maxx1, double maxy1,
    double minx2, double miny2, double maxx2, double maxy2)
{
    bool flag;
    double minx = std::max(minx1,   minx2);
    double miny = std::max(miny1,   miny2);
    double maxx = std::min(maxx1,   maxx2);
    double maxy = std::min(maxy1,   maxy2);
    if (minx>maxx||miny>maxy)
    {
        flag = false;
    }
    else
    {
        flag =true;
    }

    return flag;
}

}
