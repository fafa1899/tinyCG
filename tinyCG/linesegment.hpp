#ifndef LINESEGMENT_HPP
#define LINESEGMENT_HPP

#include <Vec3.hpp>

namespace tinyCG {

//ø’º‰÷±œﬂ
template <class T>
class LineSegment
{
public:
    Vec3<T> startPoint;
    Vec3<T> endPoint;

    LineSegment()
    {
    }

    LineSegment(Vec3<T> start, Vec3<T> end)
    {
        startPoint = start;
        endPoint = end;
    }
};

typedef LineSegment<float> LineSegmentF;
typedef LineSegment<double> LineSegmentD;

}
#endif // LINESEGMENT_H
