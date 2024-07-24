#ifndef CB49503F_FFE9_408B_A755_8388DD66AC21
#define CB49503F_FFE9_408B_A755_8388DD66AC21

struct Zero {};

template<typename T>
struct Succ {};

using One = Succ<Zero>;
using Two = Succ<One>;

template<typename LHS, typename RHS, typename T = Zero>
struct my_sum {
	using result = T;
};

template<>
struct my_sum<Zero, Zero> {
	using result = Zero;
};

template<typename RHS>
struct my_sum<Zero, RHS> {
	using result = RHS;
};

template<typename T, typename RHS>
struct my_sum<Succ<T>, RHS> {
	using result = my_sum<T, Succ<RHS>>::result;
};

#endif /* CB49503F_FFE9_408B_A755_8388DD66AC21 */
