#include <iostream>

#include <tinycg.h>
#include <Vec2.hpp>
#include <twoCGAL.h>
#include <threeCGAL.h>
#include <triangle.hpp>
#include <linesegment.hpp>

using namespace std;
using namespace tinyCG;

int main(int argc, char *argv[])
{
//    Vec2f O(1.0, 2.4f);
//    Vec2f E(10.2f, 11.5);
//    float d = 5;
//    Vec2f P;

//    twoCGAL::CalPointFromLineWithDistance_F(O, E, d, P);
//    cout << "计算的点为：" << P.x()<<'\t' << P.y() << '\n';
//    cout << "验算距离是否为"<<d<<"：" <<(P-O).length()<< '\n';

//    Vec3d point(4, 0, 5);
//    Vec3d lineBegin(10, 10, 4);
//    Vec3d lineEnd(20, 30, 0);

//    cout<<threeCGAL::CalDistancePointAndLine(point, lineBegin, lineEnd)<<endl;

    if(1)
    {
        //    Vec3d v0(-42.6683502621587, -13.2488881130934, 20);
        //    Vec3d v1(21.0955400098618, 68.442388754098, 40);
        //    Vec3d v2(93.2023691959784, 7.45947812010957, 70);
            Vec3d v0(-42.6683502621587, -13.2488881130934, 0);
            Vec3d v1(21.0955400098618, 68.442388754098, 0);
            Vec3d v2(93.2023691959784, 7.45947812010957, 0);
            TriangleD triangle(v0, v1, v2);

            Vec3d P(30.3327739633485, 21.5213275420458, -90);
            //Vec3d P(-30.3327739633485, -253321.5213275420458, 0);
            //Vec3d P(93.2023691959784, 7.45947812010957, 0);

            cout<<triangle.PointInTriangle2DSup(P)<<endl;
    }


    if(0)
    {
        LineSegmentD line1(Vec3d(0, 0, 152), Vec3d(100, 100, 520));
        LineSegmentD line2(Vec3d(100, 0, 960), Vec3d(0, 100, 410));
        Vec3d insPoint;
        cout<<LineSegmentD::Intersection2D(line1, line2, insPoint)<<endl;
        cout<<fixed<<insPoint.x()<<'\t'<<insPoint.y()<<'\t'<<insPoint.z()<<endl;
    }
}
