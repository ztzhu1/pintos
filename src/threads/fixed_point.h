#ifndef __FIXED_POINT_H
#define __FIXED_POINT_H

#include <stdint.h>

// #define P 17
// #define Q 14
#define F 16384 // 2**Q

typedef int myfloat;

#define INT_TO_FP(n) ((n) * F)
#define FP_TO_INT_Z(x) ((x) / F) // rounding toward zero
#define FP_TO_INT_N(x) ((x) >= 0 ? ((x) + F / 2) / F : ((x) - F / 2) / F) // rounding to nearest
#define ADD_FP_FP(x, y) ((x) + (y))
#define SUB_FP_FP(x, y) ((x) - (y))
#define ADD_FP_INT(x, n) ((x) + INT_TO_FP(n))
#define SUB_FP_INT(x, n) ((x) - INT_TO_FP(n))
#define MUL_FP_FP(x, y) (((int64_t)(x)) * (y) / F)
#define MUL_FP_INT(x, n) ((x) * (n))
#define DIV_FP_FP(x, y) (((int64_t)(x)) * F / (y))
#define DIV_FP_INT(x, n) ((x) / (n))

#endif