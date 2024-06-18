#include <iostream>
#include <list>

struct object {
	object() {
		std::cout << "ctor ";
	}

	object(const object&) {
		std::cout << "copy-ctor ";
	}

	~object() {
		std::cout << "dtor ";
	}
};

auto main() -> int {
	{
		/*
		 * Part 1
		 * output:
		 */
		std::cout << "Pointer: ";
		std::list<object*> l;
		object x;
		l.push_back(&x);
	}

	{
		/*
		 * Part 2
		 * output:
		 */
		std::cout << "\nValue: ";
		std::list<object> l;
		object x;
		l.push_back(x);
	}

	std::cout << std::endl;
}