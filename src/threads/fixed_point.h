#ifndef __FIXED_POINT_H
#define __FIXED_POINT_H

#include <stdint.h>

// #define P 17
// #define Q 14
#define F 16384 // 2**Q

typedef int myfp;

#define ITOF(n) ((n) * F)
#define FTOI_Z(x) ((x) / F) // rounding toward zero
#define FTOI_N(x) ((x) >= 0 ? ((x) + F / 2) / F : ((x) - F / 2) / F) // rounding to nearest
#define ROUND(x) FTOI_N(x)
#define ADD_FF(x, y) ((x) + (y))
#define ADD_FI(x, n) ((x) + ITOF(n))
#define ADD_II(x, n) (ITOF(x) + ITOF(n))
#define SUB_FF(x, y) ((x) - (y))
#define SUB_FI(x, n) ((x) - ITOF(n))
#define SUB_IF(n, x) (ITOF(n) - (x))
#define SUB_II(x, n) (ITOF(x) - ITOF(n))
#define MUL_FF(x, y) (((int64_t)(x)) * (y) / F)
#define MUL_FI(x, n) ((x) * (n))
#define DIV_FF(x, y) (((int64_t)(x)) * F / (y))
#define DIV_FI(x, n) ((x) / (n))
#define DIV_II(x, n) DIV_FI(ITOF(x), n)

#endif