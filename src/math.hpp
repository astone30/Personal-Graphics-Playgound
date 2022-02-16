
#ifndef MATH_H
#define MATH_H

#include <algorithm>
namespace mathmetic
{
    template <typename T, unsigned int N>
    struct vec
    {
        T val[N];
        
        vec()
        {
            std::fill(val, val + N, static_cast<T>(0));
        }

        vec(T value)
        {
            std::fill(val, val + N, value);
        }

        vec(T x, T y) : vec()
        {
            val[0] = x;
            val[1] = y;
        }

        vec(T x, T y, T z) : vec()
        {
            val[0] = x;
            val[1] = y;
            val[2] = z;
        }

        vec(T x, T y, T z, T w) : vec()
        {
            val[0] = x;
            val[1] = y;
            val[2] = z;
            val[3] = w;
        }
    };

    typedef vec<int, 2>     ivec2;
    typedef vec<float, 2>   fvec2;
    typedef vec<double, 2>  dvec2;

    typedef vec<int, 3>     ivec3;
    typedef vec<float, 3>   fvec3;
    typedef vec<double, 3>  dvec3;

    typedef vec<int, 4>     ivec4;
    typedef vec<float, 4>   fvec4;
    typedef vec<double, 4>  dvec4;
}

#endif