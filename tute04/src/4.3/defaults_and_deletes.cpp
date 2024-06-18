
namespace part_one {
	struct point2i {
		int x;
		int y;
	};

	// ? Will this compile
	// [[maybe_unused]] const auto p = point2i();

} // namespace part_one

namespace part_two {
	class employee {
	public:
		employee(int employeeno);

	private:
		int employeeno;
	};

	// ? Will this compile
	// [[maybe_unused]] const auto e = employee();

} // namespace part_two

namespace part_three {
	struct point2i {
		point2i() = default;
		point2i(int x = 42, int y = 6771);

		int x;
		int y;
	};

	// ? Will this compile
	// [[maybe_unused]] const auto p = point2i();

} // namespace part_three

namespace part_four {
	struct point2i {
		point2i() = default;
		point2i(const point2i&) = delete;
		point2i(point2i&&) = delete;
	};

	point2i get_point() {
		return point2i{};
	}

	// ? Will this compile
	// [[maybe_unused]] const auto p = get_point();

} // namespace part_four

namespace part_five {
	struct guard {
		guard() = default;
		guard(const guard&) = delete;
		guard(guard&&) = delete;
	};

	struct outer {
		guard g;
	};

	// ? Will this compile
	// [[maybe_unused]] const auto o1 = outer();
	// [[maybe_unused]] const auto o2 = o1;

} // namespace part_five
