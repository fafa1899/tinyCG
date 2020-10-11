#include <iostream>

#include <tinycg.h>
#include <Vec2.hpp>
#include <twoCGAL.h>

using namespace std;
using namespace tinyCG;

int main(int argc, char *argv[])
{
    Vec2f O(1.0, 2.4f);
    Vec2f E(10.2f, 11.5);
    float d = 5;
    Vec2f P;

    twoCGAL::CalPointFromLineWithDistance_F(O, E, d, P);
    cout << "计算的点为：" << P.x()<<'\t' << P.y() << '\n';
    cout << "验算距离是否为"<<d<<"：" <<(P-O).length()<< '\n';
}
