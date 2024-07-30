#include "function.hpp"
#include <iostream>

auto func(double x, int y, const std::string& z) -> std::string {
	return std::to_string(x) + std::to_string(y) + z;
}

auto main() -> int {
	// auto normal_exmples = []() {
	// 	struct BinarySum {
	// 		auto operator()(int a, int b) -> int {
	// 			return a + b;
	// 		}
	// 	} binary_sum;

	// 	auto fun1 = Function<int(int, int)>(binary_sum);
	// 	std::cout << fun1(1, 2) << std::endl;

	// 	auto fun2 = Function<size_t(const std::string&)>(
	// 	   [](const std::string& str) -> size_t { return str.size(); });
	// 	std::cout << fun2(std::string("hello world")) << std::endl;

	// 	auto temp = []() { std::cout << "hello world" << std::endl; };
	// 	auto fun3 = Function<void()>(std::move(temp));
	// 	fun3();

	// 	auto local_str = std::string("local_str");
	// 	auto fun5 = Function<void()>([&local_str]() { std::cout << local_str << std::endl; });
	// 	fun5();

	// 	auto fun6 = Function(fun1);
	// 	std::cout << fun6(40, 2) << std::endl;
	// };

	// normal_exmples();

	// auto ctad_examples = []() {
	// 	auto func4 = Function(func);
	// 	std::cout << func4(2.0, 1, std::string("matt")) << std::endl;

	// 	auto fun7 = Function([](int, double) -> std::string { return std::string("hello"); });

	// 	std::cout << fun7(5, 4.0) << std::endl;
	// };

	// ctad_examples();
}