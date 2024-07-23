#ifndef CD3D07F2_B1A6_47B9_B273_E99F68CF8A70
#define CD3D07F2_B1A6_47B9_B273_E99F68CF8A70

/*
 * Given an empty struct `Zero` and a templated empty struct `Succ` (stands for successor),
 * implement `my_sum` such that it can compute the sum at compile time.
 *
 * Example:
 * - static_assert(std::is_same_v<MySum<One, Two>, Succ<Succ<Succ<Zero>>>>) should compile
 *   where:
 *      - using One = Succ<Zero>;
 *      - using Two = Succ<One>;
 */

template<typename T>
struct Succ {};

struct Zero {};

using One = Succ<Zero>;
using Two = Succ<One>;

#endif /* CD3D07F2_B1A6_47B9_B273_E99F68CF8A70 */
