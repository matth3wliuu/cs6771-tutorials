#include <vector>

auto main() -> int {
	{
		// * Part 4
		// ? What is this doing
		std::vector<int> a{1, 2};
		std::vector<int> c = a;

		// copy construction
	}

	{
		// * Part 5
		// ? What is this doing
		std::vector<int> a{1, 2};
		std::vector<int> c;

		/*
		   you want to modify an empty vector
		*/

		c = a;

		// copy assignment
	}
}

/*
   is there any differences between copy construction / copy assignment
   - copy assigment is usally less performant than copy construction
   - default construction takes some non-zero amount of time

*/