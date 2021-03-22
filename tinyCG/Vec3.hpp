#ifndef VEC3_HPP
#define VEC3_HPP

#include <Vec2.hpp>

namespace tinyCG {

template <class T>
class Vec3
{
public:
    //矢量分量
    typedef T value_type;
    value_type _v[3];

    //构造函数
    Vec3() {_v[0]=T(0); _v[1]=T(0); _v[2]=T(0);}
    Vec3(value_type x, value_type y, value_type z) {_v[0]=x; _v[1]=y; _v[2]=z;}
    Vec3(const Vec2<value_type>& v2, value_type zz = 0)
    {
        _v[0] = v2[0];
        _v[1] = v2[1];
        _v[2] = zz;
    }

    //赋值
    inline void set(value_type x, value_type y, value_type z) {_v[0]=x; _v[1]=y; _v[2]=z;}

    //分量相加
    inline const Vec3 operator + (const Vec3& rhs) const
    {
        return Vec3(_v[0]+rhs._v[0], _v[1]+rhs._v[1], _v[2]+rhs._v[2]);
    }

    //分量相加
    inline Vec3& operator += (const Vec3& rhs)
    {
        _v[0] += rhs._v[0];
        _v[1] += rhs._v[1];
        _v[2] += rhs._v[2];
        return *this;
    }

    //分量相减
    inline const Vec3 operator - (const Vec3& rhs) const
    {
        return Vec3d(_v[0]-rhs._v[0], _v[1]-rhs._v[1], _v[2]-rhs._v[2]);
    }

    //分量相减
    inline Vec3& operator -= (const Vec3& rhs)
    {
        _v[0]-=rhs._v[0];
        _v[1]-=rhs._v[1];
        _v[2]-=rhs._v[2];
        return *this;
    }

    //点乘
    inline value_type operator * (const Vec3& rhs) const
    {
        return _v[0]*rhs._v[0]+_v[1]*rhs._v[1]+_v[2]*rhs._v[2];
    }

    //叉乘
    inline const Vec3 operator ^ (const Vec3& rhs) const
    {
        return Vec3d(_v[1]*rhs._v[2]-_v[2]*rhs._v[1],
                     _v[2]*rhs._v[0]-_v[0]*rhs._v[2] ,
                     _v[0]*rhs._v[1]-_v[1]*rhs._v[0]);
    }

    //长度/模
    inline value_type length() const
    {
        return sqrt( _v[0]*_v[0] + _v[1]*_v[1] + _v[2]*_v[2] );
    }

    //长度/模的平方
    inline value_type length2() const
    {
        return _v[0]*_v[0] + _v[1]*_v[1] + _v[2]*_v[2];
    }


    //索引器
    inline value_type& operator [] (int i) { return _v[i]; }
    inline value_type operator [] (int i) const { return _v[i]; }

    //getter and setter
    inline value_type& x() { return _v[0]; }
    inline value_type& y() { return _v[1]; }
    inline value_type& z() { return _v[2]; }

    inline value_type x() const { return _v[0]; }
    inline value_type y() const { return _v[1]; }
    inline value_type z() const { return _v[2]; }
};

typedef Vec3<float> Vec3f;
typedef Vec3<double> Vec3d;


//class Vec3d
//{
//    public:

//        inline operator Vec3f() const { return Vec3f(static_cast<float>(_v[0]),static_cast<float>(_v[1]),static_cast<float>(_v[2]));}


//        inline bool operator == (const Vec3d& v) const { return _v[0]==v._v[0] && _v[1]==v._v[1] && _v[2]==v._v[2]; }

//        inline bool operator != (const Vec3d& v) const { return _v[0]!=v._v[0] || _v[1]!=v._v[1] || _v[2]!=v._v[2]; }

//        inline bool operator <  (const Vec3d& v) const
//        {
//            if (_v[0]<v._v[0]) return true;
//            else if (_v[0]>v._v[0]) return false;
//            else if (_v[1]<v._v[1]) return true;
//            else if (_v[1]>v._v[1]) return false;
//            else return (_v[2]<v._v[2]);
//        }

//        inline value_type* ptr() { return _v; }
//        inline const value_type* ptr() const { return _v; }

//        inline void set( value_type x, value_type y, value_type z)
//        {
//            _v[0]=x; _v[1]=y; _v[2]=z;
//        }

//        inline void set( const Vec3d& rhs)
//        {
//            _v[0]=rhs._v[0]; _v[1]=rhs._v[1]; _v[2]=rhs._v[2];
//        }


//        /** Returns true if all components have values that are not NaN. */
//        inline bool valid() const { return !isNaN(); }
//        /** Returns true if at least one component has value NaN. */
//        inline bool isNaN() const { return osg::isNaN(_v[0]) || osg::isNaN(_v[1]) || osg::isNaN(_v[2]); }



//        /** Multiply by scalar. */
//        inline const Vec3d operator * (value_type rhs) const
//        {
//            return Vec3d(_v[0]*rhs, _v[1]*rhs, _v[2]*rhs);
//        }

//        /** Unary multiply by scalar. */
//        inline Vec3d& operator *= (value_type rhs)
//        {
//            _v[0]*=rhs;
//            _v[1]*=rhs;
//            _v[2]*=rhs;
//            return *this;
//        }

//        /** Divide by scalar. */
//        inline const Vec3d operator / (value_type rhs) const
//        {
//            return Vec3d(_v[0]/rhs, _v[1]/rhs, _v[2]/rhs);
//        }

//        /** Unary divide by scalar. */
//        inline Vec3d& operator /= (value_type rhs)
//        {
//            _v[0]/=rhs;
//            _v[1]/=rhs;
//            _v[2]/=rhs;
//            return *this;
//        }





//        /** Negation operator. Returns the negative of the Vec3d. */
//        inline const Vec3d operator - () const
//        {
//            return Vec3d (-_v[0], -_v[1], -_v[2]);
//        }



//        /** Normalize the vector so that it has length unity.
//          * Returns the previous length of the vector.
//          * If the vector is zero length, it is left unchanged and zero is returned.
//        */
//        inline value_type normalize()
//        {
//            value_type norm = Vec3d::length();
//            if (norm>0.0)
//            {
//                value_type inv = 1.0/norm;
//                _v[0] *= inv;
//                _v[1] *= inv;
//                _v[2] *= inv;
//            }
//            return( norm );
//        }

//};    // end of class Vec3d

///** multiply by vector components.
//inline Vec3d componentMultiply(const Vec3d& lhs, const Vec3d& rhs)
//{
//    return Vec3d(lhs[0]*rhs[0], lhs[1]*rhs[1], lhs[2]*rhs[2]);
//}

///** divide rhs components by rhs vector components.
//inline Vec3d componentDivide(const Vec3d& lhs, const Vec3d& rhs)
//{
//    return Vec3d(lhs[0]/rhs[0], lhs[1]/rhs[1], lhs[2]/rhs[2]);
//}

}    // end of namespace osg

#endif // VEC3_HPP
