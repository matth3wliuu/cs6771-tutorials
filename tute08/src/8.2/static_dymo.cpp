#include <iostream>

struct banana {
	virtual void f() {
		std::cout << "banana ";
	}

	auto operator=(const banana&) -> banana& = default;

	virtual ~banana() = default;
};

struct door : banana {
	void f() override {
		std::cout << "door ";
	}
};

/*
 ? What does the "static" type of a variable mean:
 ? What does the "dynamic" type of a variable mean:
 */
int main() {
	banana b;
	door d;
	b = d;

	b.f(); // ? prints:
	d.f(); // ? prints:

	banana& dbref = dynamic_cast<banana&>(d);
	dbref.f(); // ? prints:

	door& dref = d;
	dref.f(); // ? prints:

	banana& bref = dynamic_cast<door&>(b); // ! something is not right here
	bref.f(); //? prints:
}

/*
 * bref:
 *  - static:
 *  - dynamic:
 *
 * dref:
 *  - static:
 *  - dynamic:
 *
 * dbref:
 *  - static:
 *  - dynamic:
 */