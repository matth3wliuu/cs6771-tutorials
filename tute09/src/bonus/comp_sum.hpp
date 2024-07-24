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

template<typename LHS, typename RHS, typename Result = Zero>
struct my_sum {
	using result = Result;
};

template<>
struct my_sum<Zero, Zero> {
	using result = Zero;
};

template<typename RHS>
struct my_sum<Zero, RHS> {
	using result = RHS;
};

template<typename LHS, typename RHS>
struct my_sum<Succ<LHS>, RHS> {
	using result = my_sum<LHS, Succ<RHS>>::result;
};

#endif /* CD3D07F2_B1A6_47B9_B273_E99F68CF8A70 */
