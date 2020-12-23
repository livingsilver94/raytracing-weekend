#ifndef RTWEEK_COLOR_H
#define RTWEEK_COLOR_H

#include <ostream>

namespace rtweek {
const auto MAX_COLOR = 255;

class Color
{
  public:
	double red = 0;
	double green = 0;
	double blue = 0;

  public:
	Color() = default;
	Color(double r, double g, double b);
};

std::ostream&
operator<<(std::ostream& os, const Color& color);
}
#endif
