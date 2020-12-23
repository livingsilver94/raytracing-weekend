#include "rtweek/color.hpp"

namespace rtweek {
Color::Color(double r, double g, double b)
  : red{r}
  , green{g}
  , blue{b}
{}

std::ostream&
operator<<(std::ostream& os, const Color& color)
{
	os << static_cast<int>(color.red * rtweek::MAX_COLOR) << ' '
	   << static_cast<int>(color.green * rtweek::MAX_COLOR) << ' '
	   << static_cast<int>(color.blue * rtweek::MAX_COLOR) << '\n';
	return os;
}
}
