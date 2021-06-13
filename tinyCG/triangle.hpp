#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <Vec3.hpp>
#include <algorithm>
#include <iostream>

namespace tinyCG {

//空间三角形
//按照逆时针顺序插入值并计算法向量
template <class T>
class Triangle
{
public:
    Vec3<T> v0;
    Vec3<T> v1;
    Vec3<T> v2;

    Vec3<T> vn;

	Vec3<T> min;
	Vec3<T> max;

    Triangle()
    {

    }

    Triangle(Vec3<T> v0, Vec3<T> v1, Vec3<T> v2)
    {
        this->v0 = v0;
        this->v1 = v1;
        this->v2 = v2;
        CalNormal(v0, v1, v2, vn);
		CalMinMax();
    }

    void Set(Vec3<T> v0, Vec3<T> v1, Vec3<T> v2)
    {
        this->v0 = v0;
        this->v1 = v1;
        this->v2 = v2;
        CalNormal(v0, v1, v2, vn);
		CalMinMax();
    }

	void CalMinMax()
	{
		min.x() = std::min<T>(std::min<T>(v0.x(), v1.x()), v2.x());
		min.y() = std::min<T>(std::min<T>(v0.y(), v1.y()), v2.y());
		min.z() = std::min<T>(std::min<T>(v0.z(), v1.z()), v2.z());

		max.x() = std::max<T>(std::max<T>(v0.x(), v1.x()), v2.x());
		max.y() = std::max<T>(std::max<T>(v0.y(), v1.y()), v2.y());
		max.z() = std::max<T>(std::max<T>(v0.z(), v1.z()), v2.z());
	}

    //计算三点成面的法向量
    static void CalNormal(const Vec3<T>& v1, const Vec3<T>& v2, const Vec3<T>& v3, Vec3<T> &vn)
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
            vp.z() = v1.z() - (vn.x() * (vp.x() - v1.x()) + vn.y() * (vp.y() - v1.y())) / vn.z();			//平面的点法式方程求解
        }
    }


    // v1 = Cross(AB, AC)
    // v2 = Cross(AB, AP)
    // 判断矢量v1和v2是否同向
    bool SameSide(Vec3<T>& A, Vec3<T>& B, Vec3<T>& C, Vec3<T>& P)
    {
        Vec3<T> AB = B - A ;
        Vec3<T> AC = C - A ;
        Vec3<T> AP = P - A ;

        Vec3<T> v1 = AB ^ AC;
        Vec3<T> v2 = AB ^ AP;

        // v1 and v2 should point to the same direction
        return v1*v2 >= 0 ;
        //return v1 * v2 > 0 ;
    }

    // 判断点P是否在空间三角形内
    bool PointInTriangle3D(Vec3<T>& P)
    {
        auto v0p = P - v0;
        auto v0v1 = v1 - v0;
        auto v0v2 = v2 - v0;

        double D = v0v1.x() * v0v2.y() - v0v1.y() * v0v2.x();
        if(D == 0.0)
        {
            return false;
        }

        double D1 = v0p.x() * v0v2.y() - v0p.y() * v0v2.x();
        double D2 = v0v1.x() * v0p.y() - v0v1.y() * v0p.x();

        double u = D1/D;
        double v = D2/D;

        double eps = v0v1.z() * u + v0v2.z() * v - P.z();
        if(u >= 0 && v >= 0 && u + v <= 1 && abs(eps) < 0.000001)
        {
            return true;
        }

        return false;
    }

    // 判断平面点P是否在平面三角形内(同向法)
    bool PointInTriangle2D(Vec3<T>& P)
    {
        Vec3<T> A(v0.x(), v0.y(), 0);
        Vec3<T> B(v1.x(), v1.y(), 0);
        Vec3<T> C(v2.x(), v2.y(), 0);
        return SameSide(A, B, C, P) && SameSide(B, C, A, P) && SameSide(C, A, B, P);
    }

    // 判断平面点P是否在平面三角形内(方程法)
    bool PointInTriangle2DSup(Vec3<T>& P)
    {
        auto v01 = v1 - v0 ;
        auto v02 = v2 - v0 ;
        auto v0p = P - v0 ;

        double dot00 = v01 * v01 ;
        double dot01 = v01 * v02 ;
        double dot02 = v01 * v0p ;
        double dot11 = v02 * v02 ;
        double dot12 = v02 * v0p ;

        double D = (dot00 * dot11 - dot01 * dot01);
        if(D == 0.0)
        {
            return false;
        }
        double inverDeno = 1 / D ;

        double u = (dot11 * dot02 - dot01 * dot12) * inverDeno ;
        if (u < 0 || u > 1)
        {
            return false ;
        }

        double v = (dot00 * dot12 - dot01 * dot02) * inverDeno ;
        if (v < 0 || v > 1)
        {
            return false ;
        }

        return u + v <= 1 ;
    }

};

typedef Triangle<float> TriangleF;
typedef Triangle<double> TriangleD;

}

#endif // TRIANGLE_HPP
