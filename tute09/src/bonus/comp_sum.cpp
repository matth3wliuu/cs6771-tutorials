#include "comp_sum.hpp"
#include <type_traits>

auto main() -> int {
	// using OnePlusZero = my_sum<One, Zero>::result;

	// static_assert(std::is_same_v<OnePlusZero, One>);

	// static_assert(not std::is_same_v<my_sum<One, One>, One>);

	// static_assert(std::is_same_v<my_sum<Two, One>::result, Succ<Succ<One>>>);
}