#include "./matrix.h"

#include <algorithm>
#include <stdexcept>

matrix::matrix(std::initializer_list<std::initializer_list<int>> il) {
	const auto rows = il.size();
	const auto cols = il.begin()->size();

	const auto same_cols = std::all_of(il.begin() + 1, il.end(), [cols](const auto& inner) {
		return inner.size() == cols;
	});

	if (not same_cols) {
		throw std::logic_error("Columns must be the same size");
	}

	auto result = std::make_unique<int[]>(rows * cols);
	auto* ptr = result.get();

	for (const auto& row : il) {
		for (const auto el : row) {
			*ptr = el;
			++ptr;
		}
	}

	n_rows_ = rows;
	n_cols_ = cols;
	data_ = std::move(result);
}

matrix::matrix(const matrix& other)
: data_(std::make_unique<int[]>(other.n_rows_ * other.n_cols_))
, n_rows_(other.n_rows_)
, n_cols_(other.n_cols_) {
	std::copy(other.data(), other.data() + other.length(), data_.get());
}

matrix::matrix(matrix&& other) noexcept
: data_(std::exchange(other.data_, nullptr))
, n_rows_(std::exchange(other.n_rows_, 0))
, n_cols_(std::exchange(other.n_cols_, 0)) {}

auto matrix::operator=(const matrix& other) -> matrix& {
	if (other != *this) {
		*this = matrix(other);
		// matrix(other) copy construction
		// *this = ... move construction
	}
	return *this;
}

auto matrix::operator=(matrix&& other) noexcept -> matrix& {
	if (other != *this) {
		data_ = std::exchange(other.data_, nullptr);
		n_rows_ = std::exchange(other.n_rows_, 0);
		n_cols_ = std::exchange(other.n_cols_, 0);
	}

	return *this;
}

auto matrix::length() const -> std::size_t {
	return n_rows_ * n_cols_;
}