#ifndef COMP6771_RATIONAL_H
#define COMP6771_RATIONAL_H

#include <optional>

class rational_number {
public:
	static auto make_rational(int32_t num, int32_t denom) -> std::optional<rational_number> {
		(void)num;
		(void)denom;
		return {};
	}

	// ? what is missing in this signature
	auto value() -> double {
		return {};
	}

	friend auto add(const rational_number& lhs, const rational_number& rhs) -> rational_number {
		(void)lhs;
		(void)rhs;
		return {};
	}

	friend auto div(const rational_number& lhs, const rational_number& rhs)
	   -> std::optional<rational_number> {
		(void)lhs;
		(void)rhs;
		return {};
	}

	friend auto eq(const rational_number& lhs, const rational_number& rhs) -> bool {
		(void)lhs;
		(void)rhs;
		return {};
	}

	friend auto ne(const rational_number& lhs, const rational_number& rhs) -> bool {
		(void)lhs;
		(void)rhs;
		return {};
	}

private:
	/*
	    TODO: add constructor and data members
	*/
};

#endif // COMP6771_RATIONAL_H
