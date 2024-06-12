#include "invert.h"

auto invert(const std::map<std::string, int>& mp) -> std::map<int, std::string> {
	auto result = std::map<int, std::string>();

	for (const auto& [key, value] : mp) {
		auto result_iter = result.find(value);
		if (result_iter != result.end()) {
			if (result_iter->second.size() < key.size()) {
				result_iter->second = key;
			}
		}
		else {
			result.emplace(value, key);
		}
	}

	return result;
}

// ? What if now we want to be able to invert a map containing arbitrary types for the key and value
// ? How can we deal with the problem of conflicting keys in the result map?

template<typename Key, typename Value>
auto invert_any(const std::map<Key, Value>& mp, const std::function<bool(const Key&, const Key&)>& cmp) -> std::map<Value, Key> {
	auto result = std::map<Value, Key>();

	for (const auto& [key, value] : mp) {
		auto result_iter = result.find(value);
		if (result_iter != result.end()) {
			if (cmp(result_iter->second, key)) {
				result_iter->second = key;
			}
		}
		else {
			result.emplace(value, key);
		}
	}

	return result;
}