/*
 * utils.c -- 
 *
 * Copyright (C) 2025 Gratian Sekulski <gratian+github@mail.sekulski.org>
 *
 * lehmer-euclid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * lehmer-euclid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with lehmer-euclid.  If not, see <http://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: AGPL-3.0-or-later
 */

#include "lehmer_euclid.h"
#include <limits.h>
#include <stdbool.h>

void swap_u64(u64 *a, u64 *b)
{
    u64 temp = *a;
    *a = *b;
    *b = temp;
}

int min_int(int a, int b)
{
    return (a < b) ? a : b;
}

int trailing_zeroes(u64 n)
{
    if (n == 0) {
        return sizeof(u64) * CHAR_BIT;
    }
    /*Intristic directly translates to a single instruction like BSF on x86 or CTZ on ARM*/
    #ifdef __GNUC__
        return __builtin_ctzll(n);
    #else
        int count = 0;
        while ((n & 1) == 0) {
            n >>= 1;
            count++;
        }
        return count;
    #endif
}

int bit_length(u64 n) {
    if (n == 0) return 0;
    #ifdef __GNUC__
        return (int)(sizeof(u64) * CHAR_BIT - __builtin_clzll(n));
    #else
        int bits = 0;
        u64 temp = n;
        while (temp > 0) {
            temp >>= 1;
            bits++;
        }
        return bits;
    #endif
}

s64 s64_abs(s64 n)
{
    return (n < 0) ? -n : n; 
}

bool same_quotient(s64 a, s64 b, s64 c, s64 d)
{
    return (a / b) == (c / d);
}

u64 get_top_bits(u64 n, int n_bits)
{
    int shift = bit_length(n) - n_bits;
    if (shift <= 0) return n;
    return n >> shift;
}
