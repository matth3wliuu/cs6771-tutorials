#include "invert.h"

#include <iostream>

auto invert(const std::map<std::string, int>& mp) -> std::map<int, std::string> {
	auto result = std::map<int, std::string>();

	for (const auto& [key, value] : mp) {
		auto result_iter = result.find(value);
		if (result_iter != result.end()) {
			result.emplace(value, key);
		}
		else if (key.size() > result_iter->second.size()) {
			result_iter->second = key;
		}
	}

	return result;
}

template<typename Key, typename Value>
auto invert_any(const std::map<Key, Value>& mp,
                const std::function<bool(const Key& from_mp, const Key& from_result)> predicate)
   -> std::map<Value, Key> {
	auto result = std::map<Value, Key>();

	for (const auto& [key, value] : mp) {
		auto result_iter = result.find(value);
		if (result_iter != result.end()) {
			result.emplace(value, key);
		}
		else if (predicate(key, result_iter->second)) {
			result_iter->second = key;
		}
	}

	return result;
}