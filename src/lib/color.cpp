#include "rtweek/color.hpp"

namespace rtweek {

Color::Color() = default;

Color::Color(double r, double g, double b) : red {r}, green {g}, blue {b} {}

Color Color::operator+(const Color& color) {
	return Color(this->red + color.red, this->green + color.green, this->blue + color.blue);
}

Color Color::operator+(double t) const {
	return Color(this->red + t, this->green + t, this->blue + t);
}

Color Color::operator*(double t) const {
	return Color(this->red * t, this->green * t, this->blue * t);
}

Color operator*(double t, const Color& color) {
	return color * t;
}

std::ostream& operator<<(std::ostream& os, const Color& color) {
	os << static_cast<int>(color.red * max_color) << ' ' << static_cast<int>(color.green * max_color) << ' '
	   << static_cast<int>(color.blue * max_color);
	return os;
}

}  // namespace rtweek
