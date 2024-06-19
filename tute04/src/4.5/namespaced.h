#ifndef COMP6771_NAMESPACED_H
#define COMP6771_NAMESPACED_H

#include <string>
#include <vector>

struct celestial_body {
	std::string name;
	int pos;
};

// Hint: type aliases in modern C++ also use the "using" directive...

// ! Don't do this
// Pollutes the current namespace with all the symbols in the std library
using namespace std;

namespace comp6771 {
	using std::vector;

	// using creates an alias for a type
	using planet = celestial_body;

	namespace planets {
		using terrestrial = planet;
	}
} // namespace comp6771

#endif // COMP6771_NAMESPACED_H