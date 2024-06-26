#ifndef COMP6771_RATIONAL_OO_H
#define COMP6771_RATIONAL_OO_H

#include <optional>
#include <stdexcept>

class rational_number {
public:
	static std::optional<rational_number> null;

	static auto make_rational(int numerator, int denominator) -> std::optional<rational_number> {
		if (denominator == 0) {
			return null;
		}

		return rational_number{numerator, denominator};
	}

	explicit operator double() const {
		return static_cast<double>(numerator_) / denominator_;
	};

	auto value() const -> double {
		return static_cast<double>(numerator_) / denominator_;
	}

	auto operator[](char where) const -> const int& {
		switch (where) {
		case '^': return numerator_;
		case 'v': return denominator_;
		default:
			throw std::runtime_error("blha");
			// std::unreachable();
		}
	};

	auto operator[](char where) -> int& {
		switch (where) {
		case '^': return numerator_;
		case 'v': return denominator_;
		default:
			// std::unreachable();
			throw std::runtime_error("herer");
		}
	};

	friend auto operator+(const rational_number& lhs, const rational_number& rhs) -> rational_number {
		const auto ad = lhs.numerator_ * rhs.denominator_;
		const auto bc = lhs.denominator_ * rhs.numerator_;
		const auto bd = lhs.denominator_ * rhs.denominator_;

		return rational_number(ad + bc, bd);
	}

	friend auto operator/(const rational_number& lhs, const rational_number& rhs)
	   -> std::optional<rational_number> {
		auto ad = lhs.numerator_ * rhs.denominator_;
		auto bc = lhs.denominator_ * rhs.numerator_;

		return make_rational(ad, bc);
	}

	friend auto operator==(const rational_number& lhs, const rational_number& rhs) -> bool {
		return lhs.numerator_ == rhs.numerator_ and lhs.denominator_ == rhs.denominator_;
	}

	friend auto operator!=(const rational_number& lhs, const rational_number& rhs) -> bool {
		return not(lhs == rhs);
	}

private:
	rational_number(int numerator, int denominator)
	: numerator_{numerator}
	, denominator_{denominator} {}

	int numerator_;
	int denominator_;
};

#endif // COMP6771_RATIONAL_OO_H
