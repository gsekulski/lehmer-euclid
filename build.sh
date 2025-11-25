#!/bin/bash
set -e

gcc -c lib/*.c -Iinclude -O2 -Wall -Wextra
ar rcs liblehmer_euclid.a *.o
rm -f *.o
