
#include <forward_list>
#include <iostream>
#include <list>
#include <vector>

auto main() -> int {
	{
		const std::vector<int> v;
		[[maybe_unused]] auto iter = v.begin();

		/*
		   ? Q1: What iterator type and category is `iter`?
		   - a) constant iterator / random-access
		   - b) `const_iterator` / contiguous *
		   - c) constant `const_iterator` / contiguous
		   - d) won't compile
		*/
	}

	{
		const std::vector<int> v;
		[[maybe_unused]] auto iter = v.cbegin();

		/*
		   ? Q2: What iterator type and category is `iter`?
		   - a) `const_iterator` / contiguous
		   - b) constant `const_iterator` / contiguous
		   - c) constant iterator / contiguous
		   - d) won't compile

		*/
	}

	{
		const std::vector<int> v;
		// auto iter = (*v.begin())++;

		/*
		   ? Q3: Why doesn't this compile

		*/
	}

	{
		std::list<int> li;
		[[maybe_unused]] auto iter = li.cbegin();

		/*
		   ? Q4: What iterator type and category is `iter`?
		   - a) constant iterator / bi-directional
		   - b) iterator / forward
		   - c) `const_iterator` / bi-directional
		   - d) won't compile
		*/
	}

	{
		std::forward_list<int> forward_li;
		[[maybe_unused]] auto iter = forward_li.cbegin();

		/*
		   ? Q5: What iterator type and category is `iter`?
		    - a) `const_iterator` / forward
		    - b) constant iterator / forward
		    - c) iterator / bidirectional
		    - d) won't compile
		*/
	}

	{
		[[maybe_unused]] auto iter = std::ostream_iterator<int>(std::cout, " ");

		/*
		   ? Q10: What iterator type and category is `iter`?
		   - a) iterator / output
		   - b) `const_iterator` / output
		   - c) constant iterator / input
		   - d) won't compile
		*/
	}
}