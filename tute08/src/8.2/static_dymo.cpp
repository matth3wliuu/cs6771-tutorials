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

private:
	int my_door = 4;
};

/*
 ? What does the "static" type of a variable mean:
   - what you declare on the left hand side of the variable
   - compile time type
 ? What does the "dynamic" type of a variable mean:
   - whatever the type of the variable is at "runtime"
 */
int main() {
	banana b;
	door d;
	b = d;

	b.f(); // ? prints: banana
	d.f(); // ? prints: door

	banana& dbref = dynamic_cast<banana&>(d);
	dbref.f(); // ? prints: banana

	door& dref = d;
	dref.f(); // ? prints: door

	banana& bref = dynamic_cast<door&>(b); // ! something is not right here
	bref.f(); //? prints: door

	// ^ this will compile but crash when we run it because we can't down
	// cast a banana to door
}

/*
 * bref:
 *  - static: banana&
 *  - dynamic: door&
 *
 * dref:
 *  - static: door
 *  - dynamic: door
 *
 * dbref:
 *  - static: banana&
 *  - dynamic: banana&
 */