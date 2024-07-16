#ifndef COMP6771_ORDER_H
#define COMP6771_ORDER_H

#include <iostream>

struct A {
	A() {
		std::cout << "A";
	}
	~A() {
		std::cout << "~A";
	}
};

/*
 * If subclass inheritances another class X which declares A as a virtual base: AB
 * Else: AAB
 */
struct B : public virtual A {
	B() {
		std::cout << "B";
	}
	~B() {
		std::cout << "~B";
	}

	A a;
};

struct C : public virtual A {
	C() {
		std::cout << "C";
	}
	~C() {
		std::cout << "~C";
	}

	B b;
};

struct D
: public C
, public B {
	D() {
		std::cout << "D";
	}
	~D() {
		std::cout << "~D";
	}

	C c;
	A a;
};

/*
     A              A    A
   B   B    -->     B    B
     D                 D
*/

#endif // COMP6771_ORDER_H
