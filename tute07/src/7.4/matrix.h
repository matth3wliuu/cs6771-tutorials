#ifndef COMP6771_MATRIX_H
#define COMP6771_MATRIX_H

#include <initializer_list>
#include <utility>
class matrix {
public:
	matrix() noexcept = default;

	matrix(std::initializer_list<std::initializer_list<int>> il);

	matrix(const matrix&);

	matrix(matrix&&) noexcept;

	auto operator=(const matrix&) -> matrix&;

	auto operator=(matrix&&) noexcept -> matrix&;

	auto operator()(std::size_t i, std::size_t j) const -> const int&;

	auto operator()(std::size_t i, std::size_t j) -> int&;

	friend auto operator==(const matrix& a, const matrix& b) -> bool;

	auto dimensions() const -> std::pair<std::size_t, std::size_t>;

	auto data() const -> const int*;

private:
	auto length() const -> std::size_t;

	// ! Helper functions to make life easy
	int* begin();
	int* end();
	const int* begin() const;
	const int* end() const;

	// TODO: Add data members
};

#endif // COMP6771_MATRIX_H
