# Lehmer-Euclid GCD Algorithm

C99 implementation of Lehmer-Euclid GCD algorithm for computing the greatest common divisor (GCD) of two integers.

The Lehmer-Euclid algorithm is an optimized variant of Euclid's algorithm that reduces the number of expensive multi-precision operations by working with the most significant bits. For small numbers (≤32 bits), it uses binary GCD for efficiency. For larger numbers, it applies Lehmer's reduction technique.

**Performance:** O(log² n) time complexity for n-bit numbers with O(log n) space complexity.

**Further Reading:** For a better understanding of the algorithm, see [Parallel Lehmer-Euclid Algorithm (Sedjelmaci, ISSAC 2001)](https://www.csd.uwo.ca/~mmorenom/CS855/Ressources/ParallelLehmerEuclid-Sedjelmaci-ISSAC2001.pdf)

## Usage

```c
#include "lehmer_euclid.h"

int main() {
    u64 a = 1071;
    u64 b = 462;
    u64 gcd = lehmer_gcd_of(a, b);
    // gcd = 21
    return 0;
}
```

## Building

Compile the library and link it with your program:

```bash
./build.sh
```

Or manually:

```bash
gcc -c lib/*.c -Iinclude -O2
ar rcs liblehmer_euclid.a *.o
```

## License

Licensed under the GNU Affero General Public License, Version 3.0 (LICENSE or https://www.gnu.org/licenses/gpl-3.0.txt)

## Contributing

Unless you explicitly state otherwise, any contribution intentionally submitted for inclusion in the work by you, as defined in the GNU Affero General Public License, shall be licensed as above, without any additional terms or conditions.