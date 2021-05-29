#ifndef RTWEEK_COLOR_H
#define RTWEEK_COLOR_H

namespace rtweek {
class Color {
 public:
  double r = 0;
  double g = 0;
  double b = 0;

 public:
  Color();
  Color(double r, double g, double b);

  auto operator+(const Color& other) const -> Color;
  auto operator-(const Color& other) const -> Color;
  auto operator*(double f) const -> Color;
  auto operator/(double f) const -> Color;

  auto operator+=(const Color& other) -> Color&;
  auto operator-=(const Color& other) -> Color&;
  auto operator*=(double f) -> Color&;
  auto operator/=(double f) -> Color&;
};
} // namespace rtweek

#endif
