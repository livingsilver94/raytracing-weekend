#ifndef RTWEEK_COLOR_H
#define RTWEEK_COLOR_H

#include <ostream>

namespace rtweek {

constexpr auto max_color = 255;

class Color {
  public:
	double red;
	double green;
	double blue;

  public:
	constexpr Color(double r, double g, double b) : red {r}, green {g}, blue {b} {}

	constexpr auto operator+(const Color& color) const -> Color {
		return Color(red + color.red, green + color.green, blue + color.blue);
	}

	constexpr auto operator+(double t) const -> Color { return Color(red + t, green + t, blue + t); }
	constexpr auto operator*(double t) const -> Color { return Color(red * t, green * t, blue * t); }
};

constexpr auto operator*(double t, const Color& color) -> Color {
	return color * t;
}

auto operator<<(std::ostream& os, const Color& color) -> std::ostream&;

}  // namespace rtweek

#endif
