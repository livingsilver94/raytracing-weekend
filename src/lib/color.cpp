#include "color.hpp"

#include <ostream>

namespace rtweek {
Color::Color() = default;
Color::Color(double r, double g, double b)
    : r{r}, g{g}, b{b} {};

auto Color::operator+(const Color& other) const -> Color {
  return Color(this->r + other.r, this->g + other.g, this->b + other.b);
}
auto Color::operator-(const Color& other) const -> Color {
  return Color(this->r - other.r, this->g - other.g, this->b - other.b);
}
auto Color::operator*(double f) const -> Color {
  return Color(this->r * f, this->g * f, this->b * f);
}
auto Color::operator/(double f) const -> Color {
  return Color(this->r / f, this->g / f, this->b / f);
}

auto Color::operator+=(const Color& other) -> Color& {
  this->r += other.r;
  this->g += other.g;
  this->b += other.b;
  return *this;
}
auto Color::operator-=(const Color& other) -> Color& {
  this->r -= other.r;
  this->g -= other.g;
  this->b -= other.b;
  return *this;
}
auto Color::operator*=(double f) -> Color& {
  this->r *= f;
  this->g *= f;
  this->b *= f;
  return *this;
}
auto Color::operator/=(double f) -> Color& {
  this->r /= f;
  this->g /= f;
  this->b /= f;
  return *this;
}

auto operator<<(std::ostream& out, const Color& c) -> std::ostream& {
  out << static_cast<int>(c.r * COLOR_MAX) << ' '
      << static_cast<int>(c.g * COLOR_MAX) << ' '
      << static_cast<int>(c.b * COLOR_MAX) << '\n';
  return out;
}
} // namespace rtweek
