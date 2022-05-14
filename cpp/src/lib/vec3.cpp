#include "vec3.hpp"

#include <cmath>

namespace rtweek {
Vec3::Vec3() = default;
Vec3::Vec3(double x, double y, double z)
    : x{x}, y{y}, z{z} {};

auto Vec3::operator+(const Vec3& other) const -> Vec3 {
  return Vec3(this->x + other.x, this->y + other.y, this->z + other.z);
}
auto Vec3::operator-(const Vec3& other) const -> Vec3 {
  return Vec3(this->x - other.x, this->y - other.y, this->z - other.z);
}
auto Vec3::operator*(const Vec3& other) const -> Vec3 {
  return Vec3(this->x * other.x, this->y * other.y, this->z * other.z);
}
auto Vec3::operator*(double f) const -> Vec3 {
  return Vec3(this->x * f, this->y * f, this->z * f);
}
auto operator*(double f, const Vec3& v) -> Vec3 {
  return v * f;
}
auto Vec3::operator/(const Vec3& other) const -> Vec3 {
  return Vec3(this->x / other.x, this->y / other.y, this->z / other.z);
}
auto Vec3::operator/(double f) const -> Vec3 {
  return Vec3(this->x / f, this->y / f, this->z / f);
}
auto operator/(double f, const Vec3& v) -> Vec3 {
  return v / f;
}

auto Vec3::operator+=(const Vec3& other) -> Vec3& {
  this->x += other.x;
  this->y += other.y;
  this->z += other.z;
  return *this;
}
auto Vec3::operator-=(const Vec3& other) -> Vec3& {
  this->x -= other.x;
  this->y -= other.y;
  this->z -= other.z;
  return *this;
}
auto Vec3::operator*=(const Vec3& other) -> Vec3& {
  this->x *= other.x;
  this->y *= other.y;
  this->z *= other.z;
  return *this;
}
auto Vec3::operator*=(double f) -> Vec3& {
  this->x *= f;
  this->y *= f;
  this->z *= f;
  return *this;
}
auto Vec3::operator/=(const Vec3& other) -> Vec3& {
  this->x /= other.x;
  this->y /= other.y;
  this->z /= other.z;
  return *this;
}
auto Vec3::operator/=(double f) -> Vec3& {
  this->x /= f;
  this->y /= f;
  this->z /= f;
  return *this;
}

auto Vec3::dot(const Vec3& other) const -> double {
  return this->x * other.x + this->y * other.y + this->z * other.z;
}
auto Vec3::length() const -> double {
  return std::sqrt(this->length_sq());
}
auto Vec3::length_sq() const -> double {
  return this->dot(*this);
}
auto Vec3::unit() const -> Vec3 {
  return *this / this->length();
}
} // namespace rtweek
