#include <vector>

auto main() -> int {
	{
		// * Part 4
		// ? What is this doing
		std::vector<int> a{1, 2};
		std::vector<int> c = a;
	}

	{
		// * Part 5
		// ? What is this doing
		std::vector<int> a{1, 2};
		std::vector<int> c;
		c = a;
	}
}