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
		 * output: ctor dtor
		 */
		std::cout << "Pointer: ";
		std::list<object*> l;
		object x; // this prints ctor because we are calling default constructor
		l.push_back(&x);

		// When this scope ends, C++ will call the destructor of x
		// C
	}

	{
		/*
		 * Part 2
		 * output: ctor copy-ctor dtor dtor
		 */
		std::cout << "\nValue: ";
		std::list<object> l;
		object x; // ctor
		l.push_back(x); // this will do a copy construction and place it into l

		// dtor of x will called before the dtor of object in l
		// because destruction occurs in reverse order of declaration
	}

	std::cout << std::endl;
}