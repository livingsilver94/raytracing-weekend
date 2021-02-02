#include "rtweek/color.hpp"

namespace rtweek {

auto operator<<(std::ostream& os, const Color& color) -> std::ostream& {
	os << static_cast<int>(color.red * max_color) << ' ' << static_cast<int>(color.green * max_color) << ' '
	   << static_cast<int>(color.blue * max_color);
	return os;
}

}  // namespace rtweek
