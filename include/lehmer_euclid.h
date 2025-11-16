#ifndef LEHMER_EUCLID_H
#define LEHMER_EUCLID_H

#include <stdbool.h>
#include <stdint.h>

typedef uint64_t u64;
typedef int64_t s64;

typedef struct {
    s64 x, y, u, v; 
    u64 a_hat, b_hat;
} LehmerState;

void swap_u64(u64 *a, u64 *b);
int min_int(int a, int b);
int trailing_zeroes(u64 n);
int bit_length(u64 n);
s64 s64_abs(s64 n);
bool same_quotient(s64 a, s64 b, s64 c, s64 d);
u64 get_top_bits(u64 n, int n_bits);

u64 lehmer_gcd_of(u64 a, u64 b);
u64 binary_gcd(u64 u, u64 v);

#endif
