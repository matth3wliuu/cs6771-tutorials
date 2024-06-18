#include <iostream>

namespace {
	auto i = 42;
}

namespace comp6771 {
	auto i = 6771;

	auto foo(int) -> void {
		std::cout << "comp6771::foo(int)" << std::endl;
	}
} // namespace comp6771

namespace comp6772 {
	auto foo(int) -> void {
		std::cout << "comp6772::foo(int)" << std::endl;
	}

	auto foo(char) -> void {
		std::cout << "comp6772::foo(char)" << std::endl;
	}
} // namespace comp6772

namespace comp6773 {
	struct uchar {
		unsigned char c;
	};

	auto bar(uchar) -> void {
		std::cout << "comp6773::bar(comp6773::uchar)" << std::endl;
	}
} // namespace comp6773

int main() {
	std::cout << i << std::endl;
	{
		int i = 0;
		std::cout << i << std::endl;

		using ::i;
		std::cout << i << std::endl;
	}

	comp6771::foo(i);
	comp6772::foo(i);

	using namespace comp6771;
	using namespace comp6772;

	foo(i);

	foo('c');

	auto uc = comp6773::uchar{'c'};
	bar(uc);
}
