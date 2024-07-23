#ifndef COMP6771_RING_H
#define COMP6771_RING_H

#include <cstddef>
#include <initializer_list>
#include <iterator>
#include <stdexcept>

/* TODO: fill in here */
class ring {
public:
	template<typename InputIt>
	ring(InputIt first, InputIt last)
	: head_{0}
	, tail_{0}
	, size_{0} {
		if (static_cast<std::size_t>(std::distance(first, last)) > N) {
			throw std::invalid_argument{"Not enough capacity"};
		}
		for (; first != last; ++first) {
			do_push(*first);
		}
	}

	ring(std::initializer_list<T> il)
	: ring(il.begin(), il.end()) {}

	auto push(const T& t) -> void {
		if (size_ < N) {
			do_push(t);
		}
	}

	auto peek() const -> const T& {
		return elems_[head_];
	}

	auto pop() -> void {
		if (size_ > 0) {
			do_pop();
		}
	}

	auto size() const -> std::size_t {
		return size_;
	}

private:
	auto do_push(const T& t) {
		elems_[tail_++] = t;
		tail_ %= N;
		size_++;
	}

	auto do_pop() {
		head_ = ++head_ % N;
		size_--;
	}

	/* TODO: Fill in here */
};

/*
 * What is class template argument deduction (CTAD)
 *
 *
 */

#endif // COMP6771_RING_H
