#ifndef TWOCGAL_H
#define TWOCGAL_H

#include "tinyCG_global.h"
#include "Vec2.hpp"

//二维计算几何算法

namespace tinyCG
{

class TINYCG_EXPORT twoCGAL
{
public:
    twoCGAL();

    //已知线段上某点与起点的距离，求该点的坐标
    static void CalPointFromLineWithDistance_D(const Vec2d & O, const Vec2d & E, double d, Vec2d& P);
    static void CalPointFromLineWithDistance_F(const Vec2f & O, const Vec2f & E, float d, Vec2f& P);
};

}

#endif // TWOCGAL_H
