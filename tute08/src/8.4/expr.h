#ifndef COMP6771_EXPR_H
#define COMP6771_EXPR_H

#include <memory>

class expr {
public:
	virtual double eval() const = 0; // this is a pure virtual function
	virtual ~expr() = default;
};

class num : public expr {
public:
	explicit num(double val)
	: m_val(val) {}

	auto eval() const -> double override {
		return m_val;
	}

private:
	double m_val;
};

class binary_operator : public expr {
public:
	binary_operator(std::unique_ptr<expr> lhs, std::unique_ptr<expr> rhs)
	: m_lhs(std::move(lhs))
	, m_rhs(std::move(rhs)) {}

protected:
	auto get_left() const -> expr* {
		return m_lhs.get();
	}

	auto get_right() const -> expr* {
		return m_rhs.get();
	}

private:
	std::unique_ptr<expr> m_lhs;
	std::unique_ptr<expr> m_rhs;
};

class multiply : public binary_operator {
	multiply(std::unique_ptr<expr> lhs, std::unique_ptr<expr> rhs)
	: binary_operator(std::move(lhs), std::move(rhs)) {}

	auto eval() const -> double override {
		return get_left()->eval() * get_right()->eval();
	}
};

#endif // COMP6771_EXPR_H
