
#include <forward_list>
#include <iostream>
#include <list>
#include <vector>

auto main() -> int {
	{
		const std::vector<int> v;
		[[maybe_unused]] auto iter = v.begin();
	}

	{
		const std::vector<int> v;
		[[maybe_unused]] auto iter = v.cbegin();
	}

	{
		const std::vector<int> v;
		// [[maybe_unused]] auto iter = (*v.begin())++;
	}

	{
		std::list<int> li;
		[[maybe_unused]] auto iter = li.cbegin();
	}

	{
		std::forward_list<int> forward_li;
		[[maybe_unused]] auto iter = forward_li.cbegin();
	}

	{
		[[maybe_unused]] auto iter = std::ostream_iterator<int>(std::cout, " ");
	}
}