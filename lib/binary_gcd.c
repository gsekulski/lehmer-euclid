/*
 * binary_gcd.c
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

#include "lehmer-euclid.h"
#include <limits.h>

/*
 * Binary GCD (Stein's algorithm) -- ported Rust's version from uutils:
 *     https://en.wikipedia.org/wiki/Binary_GCD_algorithm
 * */

u64 binary_gcd(u64 u, u64 v)
{
    if (u == 0) {
        return v; 
    } else if (v == 0) {
        return u;
    }

    int i = trailing_zeroes(u);
    u >>= i;
    int j = trailing_zeroes(v);
    v >>= j; 
    int k = min_int(i, j);

    while (1) {
        if (u > v) {
            swap_u64(&u, &v);
        }
        v -= u;
        if (v == 0) {
            return u << k;
        }
        v >>= trailing_zeroes(v);
    }
}
