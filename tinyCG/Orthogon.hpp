#ifndef ORTHOGON_HPP
#define ORTHOGON_HPP

#include "tinyCG_global.h"

#include <algorithm>

namespace tinyCG {

//二维矩形
template <class T>
class Orthogon
{
public:

    //矢量分量
    typedef T value_type;
    value_type region[4];

    //构造函数
    Orthogon()
    {
        for(size_t i = 0; i < 4; i++)
        {
            region[i] = 0;
        }
    }

    Orthogon(value_type minX, value_type minY, value_type maxX, value_type maxY)
    {
        region[0] = minX;
        region[1] = minY;
        region[2] = maxX;
        region[3] = maxY;
    }

    //赋值
    inline void Set( value_type minX, value_type minY, value_type maxX, value_type maxY )
    {
        region[0] = minX;
        region[1] = minY;
        region[2] = maxX;
        region[3] = maxY;
    }

    //两矩形是否相交
    static bool Intersect(const Orthogon& orthogon1, const Orthogon& orthogon2)
    {
        bool flag;
        double minx = std::max<T>(orthogon1.minX(), orthogon2.minX());
        double miny = std::max<T>(orthogon1.minY(), orthogon2.minY());
        double maxx = std::min<T>(orthogon1.maxX(), orthogon2.maxX());
        double maxy = std::min<T>(orthogon1.maxY(), orthogon2.maxY());
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

    inline bool IsContainsPoint(T x, T y)
    {
        return (x>=region[0]) && (x<=region[2]) && (y>=region[1]) && (y<=region[3]);
    }

    //getter and setter
    inline value_type minX() const { return region[0]; }
    inline value_type minY() const { return region[1]; }
    inline value_type maxX() const { return region[2]; }
    inline value_type maxY() const { return region[3]; }

    inline value_type& minX() { return region[0]; }
    inline value_type& minY() { return region[1]; }
    inline value_type& maxX() { return region[2]; }
    inline value_type& maxY() { return region[3]; }

};

//#define INSTANTIATE(T) template class TINYCG_EXPORT Orthogon<T>;
//INSTANTIATE(float)
//INSTANTIATE(double)

typedef Orthogon<float> OrthogonF;
typedef Orthogon<double> OrthogonD;

}

#endif // ORTHOGON_HPP
