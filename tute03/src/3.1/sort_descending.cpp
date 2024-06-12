#include "sort_descending.h"

#include <functional>
#include <ranges>

auto sort_descending(std::vector<int>& numbers) -> void {
	std::sort(numbers.begin(), numbers.end(), std::greater<int>());

	// ! beware that ranges may or may not compile on CSE
	std::ranges::sort(numbers, std::greater<int>());
}
