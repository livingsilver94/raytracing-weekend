#ifndef RTWEEK_COLOR_H
#define RTWEEK_COLOR_H

#include <ostream>

namespace rtweek {

const auto max_color = 255;

class Color {
  public:
	double red   = 0;
	double green = 0;
	double blue  = 0;

  public:
	Color();
	Color(double r, double g, double b);

	Color operator+(const Color& color);
	Color operator+(double t) const;
	Color operator*(double t) const;
};

Color operator*(double t, const Color& color);

std::ostream& operator<<(std::ostream& os, const Color& color);

}  // namespace rtweek

#endif
