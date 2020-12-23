#include "rtweek/color.hpp"

namespace rtweek {

Color::Color() = default;

Color::Color(double r, double g, double b) : red {r}, green {g}, blue {b} {}

std::ostream& operator<<(std::ostream& os, const Color& color) {
	os << static_cast<int>(color.red * MAX_COLOR) << ' ' << static_cast<int>(color.green * MAX_COLOR) << ' '
	   << static_cast<int>(color.blue * MAX_COLOR);
	return os;
}

}  // namespace rtweek
