#ifndef COMP6771_BOOK_H
#define COMP6771_BOOK_H

#include <cmath>
#include <iomanip>
#include <string>
#include <utility>

class book {
public:
	book(std::string name, std::string author, std::string isbn, double price)
	: name_{std::move(name)}
	, author_{std::move(author)}
	, isbn_{std::move(isbn)}
	, price_{price} {}

	explicit book(std::string name)
	: name_{std::move(name)}
	, price_() {}

	/*
	    ? What does the explicit keyword do ?
	    * Scenario 1: appear before a constructor

	   auto make_book = [] () -> book {
	      return "COMP6771";
	   };




	    * Scenario 2: like below
	*/

	explicit operator std::string() const {
		return author_ + ", " + name_;
	}

	const std::string& name() const {
		return name_;
	}

	const std::string& author() const {
		return author_;
	}

	const std::string& isbn() const {
		return isbn_;
	}

	const double& price() const {
		return price_;
	}

	friend bool operator==(const book& lhs, const book& rhs) {
		return lhs.isbn_ == rhs.isbn_;
	}

	friend bool operator!=(const book& lhs, const book& rhs) {
		return not(lhs == rhs);
	}

	friend bool operator<(const book& lhs, const book& rhs) {
		return lhs.isbn_ < rhs.isbn_;
	}

	friend std::ostream& operator<<(std::ostream& os, const book& b) {
		(void)b;
		return os;
	}

private:
	const std::string name_;
	const std::string author_;
	const std::string isbn_;
	const double price_;
};

#endif // COMP6771_BOOK_H
