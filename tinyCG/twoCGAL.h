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


    //两矩形是否相交
    static bool RectIntersect(double minx1, double miny1,double maxx1, double maxy1,
        double minx2, double miny2, double maxx2, double maxy2);
};

}

#endif // TWOCGAL_H
