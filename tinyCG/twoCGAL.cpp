#include "twoCGAL.h"
#include <iostream>

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


}
