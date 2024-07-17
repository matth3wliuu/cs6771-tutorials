
struct A {
	auto show() -> void;
};

struct B : public virtual A {};

struct C : public virtual A {};

// clang-format off
struct D : public B, public C {
};
// clang-format on

auto main() -> int {
	auto d = D();
	d.show();
}

/*
    A   A         A
    B   C   ->  B   C
      D           D
*/