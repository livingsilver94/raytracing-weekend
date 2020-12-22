#include "rtweek/color.hpp"

using rtweek::Color;

Color::Color(double r, double g, double b)
  : red{r}
  , green{g}
  , blue{b}
{}

std::ostream&
operator<<(std::ostream& os, Color const& color)
{
	os << static_cast<int>(color.red * rtweek::MAX_COLOR) << ' '
	   << static_cast<int>(color.green * rtweek::MAX_COLOR) << ' '
	   << static_cast<int>(color.blue * rtweek::MAX_COLOR) << '\n';
	return os;
}
