#include "./rational_oo.h"

std::optional<rational_number> rational_number::null;

auto main() -> int {
	const auto const_rn = rational_number::make_rational(1, 1).value();
	auto rn = rational_number::make_rational(1, 2).value();

	// const auto x = lhs.value() + rhs.value();

	const auto& const_num = const_rn['^'];
	auto& num = rn['^'];

	auto fun = [](double x) { (void)x; };

	fun(static_cast<double>(rn));
}