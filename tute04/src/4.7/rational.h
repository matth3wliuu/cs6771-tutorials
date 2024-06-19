#ifndef COMP6771_RATIONAL_H
#define COMP6771_RATIONAL_H

#include <optional>

class rational_number {
public:
	static std::optional<rational_number> null;

	static auto make_rational(int32_t num, int32_t denom) -> std::optional<rational_number> {
		if (denom == 0) {
			return null;
		}
		return rational_number(num, denom);
	}

	// ? what is missing in this signature
	auto value() -> double {
		return {};
	}

	// * Note: we will see how to overload operators like (+, /, ...) soon
	friend auto add(const rational_number& lhs, const rational_number& rhs) -> rational_number {
		/*
		   a/b + c/d = (ad + bc) / bd
		*/

		const auto new_num = lhs.m_numerator * rhs.m_denominator + lhs.m_denominator * rhs.m_numerator;
		const auto new_denom = lhs.m_denominator * rhs.m_denominator;

		return {new_num, new_denom};
	}

	friend auto div(const rational_number& lhs, const rational_number& rhs)
	   -> std::optional<rational_number> {
		/*
		   (a/b) / (c/d) = a/b * d/c = ad / bc
		*/

		const auto new_num = lhs.m_numerator * rhs.m_denominator;
		const auto new_denom = lhs.m_denominator * rhs.m_numerator;

		return make_rational(new_num, new_denom);
	}

	// eq(rational_num1, rational_num2)
	// rational_num1 == rational_num2
	friend auto eq(const rational_number& lhs, const rational_number& rhs) -> bool {
		return lhs.m_numerator * rhs.m_denominator == lhs.m_denominator * rhs.m_numerator;
		/*
		   a/b == c/d <=> ad == bc
		*/
	}

	friend auto ne(const rational_number& lhs, const rational_number& rhs) -> bool {
		return not eq(lhs, rhs);
	}

private:
	rational_number(int num, int denom)
	: m_numerator(num)
	, m_denominator(denom) {}

	int m_numerator;
	int m_denominator;

	/*
	    TODO: add constructor and data members
	*/
};

#endif // COMP6771_RATIONAL_H
