#include "invert.h"

auto invert([[maybe_unused]] const std::map<std::string, int>& mp) -> std::map<int, std::string> {
	return {};
}

// ? What if now we want to be able to invert a map containing arbitrary types for the key and value
// ? How can we deal with the problem of conflicting keys in the result map?
