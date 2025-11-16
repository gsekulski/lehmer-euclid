/*
 * lehmer_euclid.c -- 
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

/*Arbitrary threshold for switching to Lehmer reduction (e.g. if bit len > 32)*/
#define THRESHOLD 32

static LehmerState lehmer_inner(s64 x, s64 y, s64 u, s64 v, u64 a_hat, u64 b_hat) {
    s64 q;
    u64 a_tmp, b_tmp;
    s64 x_tmp, y_tmp, u_tmp, v_tmp;

    while (true) {
        if (b_hat == 0) break;
        
        /* Lehmer's invariant
         * a, b, c, d -- high-bit components
         */
        if (same_quotient((s64)a_hat + x, (s64)b_hat + v, (s64)a_hat + u, (s64)b_hat + y)) {
            
            q = ((s64)a_hat + x) / ((s64)b_hat + v);

            x_tmp = u;
            y_tmp = v;
            
            u_tmp = x - q * u;
            v_tmp = y - q * v;

            a_tmp = b_hat;
            b_tmp = a_hat - q * b_hat;

            /* reduction failed/overran)*/
            if ((s64)b_tmp < 0) {
                 break; 
            }

            x = x_tmp; y = y_tmp;
            u = u_tmp; v = v_tmp;
            a_hat = a_tmp;
            b_hat = b_tmp;

        } else {
            break;
        }
    }

    LehmerState state = {x, y, u, v, a_hat, b_hat};
    return state;
}

u64 lehmer_gcd_of(u64 a, u64 b) {
    if (a == 0) return b;
    if (b == 0) return a;
    
    if (a < b) { 
        u64 t = a; a = b; b = t; 
    }

    /* Elixir's 'if BitLength.of(a) <= 32 or BitLength.of(b) <= 32 do')*/
    if (bit_length(a) <= THRESHOLD || bit_length(b) <= THRESHOLD) {
        return binary_gcd(a, b);
    }

    int n_bits = THRESHOLD; 
    u64 a_hat = get_top_bits(a, n_bits);
    u64 b_hat = get_top_bits(b, n_bits);
    
    LehmerState state = lehmer_inner(1, 0, 0, 1, a_hat, b_hat);

    s64 x = state.x;
    s64 y = state.y;
    s64 u = state.u;
    s64 v = state.v;
    
    if (u == 0) {
        /*Fall back to standard Euclidean step*/
        return binary_gcd(b, a % b); 
    } else {
        u64 a_prime = (u64)s64_abs(x * (s64)a + y * (s64)b);
        u64 b_prime = (u64)s64_abs(u * (s64)a + v * (s64)b);

        return lehmer_gcd_of(a_prime, b_prime);
    }
}
