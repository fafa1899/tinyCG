#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Epsilon.h"

#include <Vec3.hpp>
#include <algorithm>
#include <iostream>

namespace tinyCG {

//空间三角形
//按照逆时针顺序插入值并计算法向量
template <class T>
class TriangleEx
{
public:
    Vec3<T>* v0;
    Vec3<T>* v1;
    Vec3<T>* v2;

    Vec3<T> vn;

	Vec3<T> min;
	Vec3<T> max;

    TriangleEx()
    {

    }

    TriangleEx(Vec3<T>* v0, Vec3<T>* v1, Vec3<T>* v2)
    {
        this->v0 = v0;
        this->v1 = v1;
        this->v2 = v2;
        CalNormal(*v0, *v1, *v2, vn);
		CalMinMax();
    }

    void Set(Vec3<T>* v0, Vec3<T>* v1, Vec3<T>* v2)
    {
        this->v0 = v0;
        this->v1 = v1;
        this->v2 = v2;
        CalNormal(*v0, *v1, *v2, vn);
		CalMinMax();
    }

	void CalMinMax()
	{
        min.x() = std::min<T>(std::min<T>(v0->x(), v1->x()), v2->x());
        min.y() = std::min<T>(std::min<T>(v0->y(), v1->y()), v2->y());
        min.z() = std::min<T>(std::min<T>(v0->z(), v1->z()), v2->z());

        max.x() = std::max<T>(std::max<T>(v0->x(), v1->x()), v2->x());
        max.y() = std::max<T>(std::max<T>(v0->y(), v1->y()), v2->y());
        max.z() = std::max<T>(std::max<T>(v0->z(), v1->z()), v2->z());
	}

    //计算三点成面的法向量
    static inline void CalNormal(const Vec3<T>& v1, const Vec3<T>& v2, const Vec3<T>& v3, Vec3<T> &vn)
    {
        //v1(n1,n2,n3);
        //平面方程: na * (x – n1) + nb * (y – n2) + nc * (z – n3) = 0 ;
        double na = (v2.y()-v1.y())*(v3.z()-v1.z())-(v2.z()-v1.z())*(v3.y()-v1.y());
        double nb = (v2.z()-v1.z())*(v3.x()-v1.x())-(v2.x()-v1.x())*(v3.z()-v1.z());
        double nc = (v2.x()-v1.x())*(v3.y()-v1.y())-(v2.y()-v1.y())*(v3.x()-v1.x());

        //平面法向量
        vn.set(na,nb,nc);
    }

    //已知空间三点组成的面求该面上某点的Z值
    void CalPlanePointZ(Vec3<T>& vp)
    {
        if(vn.z() == 0)
        {
            printf("平面平行Z轴!");
        }
        else
        {
            vp.z() = v1->z() - (vn.x() * (vp.x() - v1->x()) + vn.y() * (vp.y() - v1->y())) / vn.z();			//平面的点法式方程求解
        }
    }


    // v1 = Cross(AB, AC)
    // v2 = Cross(AB, AP)
    // 判断矢量v1和v2是否同向
    static bool SameSide(Vec3<T>& A, Vec3<T>& B, Vec3<T>& C, Vec3<T>& P)
    {
        Vec3<T> AB = B - A ;
        Vec3<T> AC = C - A ;
        Vec3<T> AP = P - A ;

        Vec3<T> v1 = AB ^ AC;
        Vec3<T> v2 = AB ^ AP;

        //如果P在AB上
        if(v2.length() < EPSILON6)
        {
            return true;
        }

        printf("%.10lf\t%.10lf\t%.10lf\n", AB.x(), AB.y(), AB.z());
        printf("%.10lf\t%.10lf\t%.10lf\n", AP.x(), AP.y(), AP.z());

        // v1 and v2 should point to the same direction
        return v1 * v2 >= 0;
    }

    // 判断点P是否在空间三角形内
    bool PointInTriangle3D(Vec3<T>& P)
    {
        auto v0p = P - *v0;
        auto v0v1 = *v1 - *v0;
        auto v0v2 = *v2 - *v0;

        double D = v0v1.x() * v0v2.y() - v0v1.y() * v0v2.x();
        if(D == 0.0)
        {
            return false;
        }

        double D1 = v0p.x() * v0v2.y() - v0p.y() * v0v2.x();
        double D2 = v0v1.x() * v0p.y() - v0v1.y() * v0p.x();

        double u = D1/D;
        double v = D2/D;

        //u,v可能趋近于-0
        if(abs(u) > EPSILON9 && u < 0)
        {
            return false;
        }
        if(abs(v) > EPSILON9 && v < 0)
        {
            return false;
        }

        double eps = v0v1.z() * u + v0v2.z() * v - P.z();
        if(u + v - 1 <= EPSILON9 && abs(eps) < EPSILON9)
        {
            return true;
        }

        return false;
    }

    // 判断平面点P是否在平面三角形内
    bool PointInTriangle2D(Vec3<T>& P)
    {

        auto v0p = P - *v0;
        auto v0v1 = *v1 - *v0;
        auto v0v2 = *v2 - *v0;

        double D = v0v1.x() * v0v2.y() - v0v1.y() * v0v2.x();
        if(D == 0.0)
        {
            return false;
        }

        double D1 = v0p.x() * v0v2.y() - v0p.y() * v0v2.x();
        double D2 = v0v1.x() * v0p.y() - v0v1.y() * v0p.x();

        double u = D1/D;
        double v = D2/D;

        //u,v可能趋近于-0
        if(abs(u) > EPSILON9 && u < 0)
        {
            return false;
        }
        if(abs(v) > EPSILON9 && v < 0)
        {
            return false;
        }

        if(u + v - 1 <= EPSILON9)
        {
            return true;
        }

        return false;

//        Vec3<T> A(v0->x(), v0->y(), 0);
//        Vec3<T> B(v1->x(), v1->y(), 0);
//        Vec3<T> C(v2->x(), v2->y(), 0);

//        return SameSide(A, B, C, P) && SameSide(B, C, A, P) && SameSide(C, A, B, P);
    }

};

typedef TriangleEx<float> TriangleExF;
typedef TriangleEx<double> TriangleExD;

}

#endif // TRIANGLE_HPP
