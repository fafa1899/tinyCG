#ifndef THREECGAL_H
#define THREECGAL_H

#include "tinyCG_global.h"
#include "Vec3.hpp"

//三维计算几何算法

namespace tinyCG
{

class TINYCG_EXPORT threeCGAL
{
public:
    threeCGAL();

    //计算点与直线的距离
    static double CalDistancePointAndLine(Vec3d &point, Vec3d &lineBegin, Vec3d &lineEnd);
};

}

#endif // THREECGAL_H
