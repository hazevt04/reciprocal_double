#ifndef __RECIPROCAL_DOUBLE_H__
#define __RECIPROCAL_DOUBLE_H__

#include "my_utils.hpp"

#ifdef __cplusplus
    #include <cstdint>
#else
    #include <stdint.h>
#endif

__inline__ double __attribute__((const)) reciprocal( double x ) {
    union {
        double dbl;
        #ifdef __cplusplus
            std::uint_least64_t ull;
        #else
            uint_least64_t ull;
        #endif
    } u;
    u.dbl = x;
    u.ull = ( 0xbfcdd6a18f6a6f52ULL - u.ull ) >> 1;
                                // pow( x, -0.5 )
    u.dbl *= u.dbl;             // pow( pow(x,-0.5), 2 ) = pow( x, -1 ) = 1.0 / x
    return u.dbl;
}


__inline__ float __attribute__((const)) reciprocal( float x ) {
    union {
        float single;
        #ifdef __cplusplus
            std::uint_least32_t uint;
        #else
            uint_least32_t uint;
        #endif
    } u;
    u.single = x;
    u.uint = ( 0xbe6eb3beU - u.uint ) >> 1;
                                // pow( x, -0.5 )
    u.single *= u.single;       // pow( pow(x,-0.5), 2 ) = pow( x, -1 ) = 1.0 / x
    return u.single;
}

#endif // end of #ifndef __RECIPROCAL_DOUBLE_H__
