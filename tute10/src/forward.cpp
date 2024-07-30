#include <iostream>
#include <string>

/*
 * std::forward "forwards" / preserves the value category ("lvalue-ness" or "rvalue-ness")
 * of a variable received through a function
 *
 * if i receive a rvalue and i pass it to my friend, they will
 * also get a rvalue
 */

auto overloaded_function(std::string&) {
	std::cout << "std::string& version" << std::endl;
}
auto overloaded_function(std::string&&) {
	std::cout << "std::string&& version" << std::endl;
}

/* without forward */
// template <typename T> auto pass_through(T &&param) {
//   overloaded_function(param);
// }

/* with forward */
template<typename T>
auto pass_through(T&& param) {
	overloaded_function(std::forward<T>(param));
}

auto main() -> int {
	auto str = std::string();
	pass_through(str);
	pass_through(std::move(str));
}