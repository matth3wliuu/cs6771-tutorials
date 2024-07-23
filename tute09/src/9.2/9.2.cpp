#include "9.2.hpp"
#include <iostream>

auto main() -> int {
	sunk s;

	constexpr auto str = [&s]() {
		if constexpr (s) {
			return "hello world";
		}
		else {
			return "bye world\n";
		}
	}();

	std::cout << str << std::endl;
}