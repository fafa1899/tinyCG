#ifndef LINESEGMENT_HPP
#define LINESEGMENT_HPP

#include <Vec3.hpp>
#include <Orthogon.hpp>

namespace tinyCG {

//空间直线
template <class T>
class LineSegment
{
public:
    Vec3<T> startPoint;
    Vec3<T> endPoint;
    Vec3<T> direction;

    Vec3<T> min;
    Vec3<T> max;

    LineSegment()
    {
    }

    LineSegment(Vec3<T> start, Vec3<T> end)
    {
        startPoint = start;
        endPoint = end;
        direction = end - start;
        CalMinMax();
    }

    inline void Set(Vec3<T> start, Vec3<T> end)
    {
        startPoint = start;
        endPoint = end;
        direction = end - start;
        CalMinMax();
    }

    inline void CalMinMax()
    {
        min.x() = std::min<T>(startPoint.x(), endPoint.x());
        min.y() = std::min<T>(startPoint.y(), endPoint.y());
        min.z() = std::min<T>(startPoint.z(), endPoint.z());

        max.x() = std::max<T>(startPoint.x(), endPoint.x());
        max.y() = std::max<T>(startPoint.y(), endPoint.y());
        max.z() = std::max<T>(startPoint.z(), endPoint.z());
    }

    //两条线段相交
    inline static bool Intersection2D(LineSegment & line1, LineSegment & line2, Vec3<T>& insPoint)
    {
        double D = -line1.direction.x() * line2.direction.y() + line1.direction.y() * line2.direction.x();
        if(D == 0.0)
        {
            return false;
        }

        auto O12 = line2.startPoint - line1.startPoint;
        T D1 = -O12.x() * line2.direction.y() + O12.y() * line2.direction.x();
        T D2 = line1.direction.x() * O12.y() - line1.direction.y() * O12.x();

        T t1 = D1 / D;
        if(t1<0 || t1 > 1)
        {
            return false;
        }

        T t2 = D2 / D;
        if(t2<0 || t2 > 1)
        {
            return false;
        }

        insPoint = line1.startPoint + line1.direction * t1;     //这样计算得到的Z值是不准确的

        return true;
    }

    //线段与矩形相交
    inline bool static IsIntersectsOrthogon2D(LineSegment & line, Orthogon<T> orthogon)
    {
        if (orthogon.IsContainsPoint(line.startPoint.x(), line.startPoint.y()) ||
                orthogon.IsContainsPoint(line.endPoint.x(), line.endPoint.y()))
        {
            return true;
        }

        LineSegment diagonal1(Vec3<T>(orthogon.minX(), orthogon.minY(), 0),
                              Vec3<T>(orthogon.maxX(), orthogon.maxY(), 0));
        LineSegment diagonal2(Vec3<T>(orthogon.minX(), orthogon.maxY(), 0),
                              Vec3<T>(orthogon.maxX(), orthogon.minY(), 0));

        Vec3<T> point(0,0,0);
        return Intersection2D(line, diagonal1, point) || Intersection2D(line, diagonal2, point);
    }
};

typedef LineSegment<float> LineSegmentF;
typedef LineSegment<double> LineSegmentD;

}
#endif // LINESEGMENT_H
