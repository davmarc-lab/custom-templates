#pragma once

template <typename T> struct Pair {
  T x, y;
};

template <typename T> struct Tuple {
  T x, y, z;
};

/*
 * Example of bit_mask
 * typedef unsigned int Mask;
 * 
 * enum Mask_ {
 *     first = 1 << 0,
 *     second = 1 << 1,
 *     third = 1 << 2,
 * };
 * 
 * Mask mask = first | second;
*/

