#include "./order.h"

#include <iostream>

int main() {
	{
		D d;
		A a;
		B b;

		std::cout << std::endl;
	}
	std::cout << std::endl;
}

/*
Order of construction:
- Virtual base classes in declaration order
- Non-virtual bases in declaration order
- Data members in declaration order
- Constructor for this `this`
*/

/*
Expected output:
- AAABCABAAABCADAAAB

- Easy part:
    - AAABCABAAABCD [ A | AAB ]
    - Constructing `B` must produce 2 A's somehow
    - Constructing `A` must produce just A because it's immediately preceded by `D`
- Pattern for `C`
    - C is always preceded by AAAB
    - But constructing a `B` only gets us 2 `A`, so we need one more somehow
    - [AAABC] [AB] [AAABC] [AD]  ...
    - This leaves 3 choices for `C`
        i)   C composes both `A` and `B`
        ii)  C extends non-virtual `A` and compose `B`
        iii) C extends virtual `A` and compose `B`
- How do we get the AB then?
    - This is tricky because we assume constructing `B` will always give 2 `A`
    - This is when virtual base classes and the diamond problem come in
    - If `D` extends non-virtual `C` and followed by non-virtual `B`
        - We get AAABC from constructing `C`
        - AB from constructing `B` because of virtual inheritance
- Remaining bits:
    - ... [AAABC] [AD] ...
    - This can be achieved by composing `C`, `A` in `D`
- Summary:
    - Don't change `A`
    - `B` extends `A` via public virtual
    - `C` extends `A` via public virtual
    - `D` extends `C` and `B` normally
*/
