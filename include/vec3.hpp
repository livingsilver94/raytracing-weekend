#ifndef RTWEEK_VEC3_H
#define RTWEEK_VEC3_H

namespace rtweek {
class Vec3 {
 public:
  double x = 0;
  double y = 0;
  double z = 0;

 public:
  Vec3();
  Vec3(double x, double y, double z);

  auto operator+(const Vec3& other) const -> Vec3;
  auto operator-(const Vec3& other) const -> Vec3;
  auto operator*(const Vec3& other) const -> Vec3;
  auto operator*(double f) const -> Vec3;
  auto operator/(const Vec3& other) const -> Vec3;
  auto operator/(double f) const -> Vec3;

  auto operator+=(const Vec3& other) -> Vec3&;
  auto operator-=(const Vec3& other) -> Vec3&;
  auto operator*=(const Vec3& other) -> Vec3&;
  auto operator*=(double f) -> Vec3&;
  auto operator/=(const Vec3& other) -> Vec3&;
  auto operator/=(double f) -> Vec3&;

  [[nodiscard]] auto length() const -> double;
  [[nodiscard]] auto length_sq() const -> double;
  [[nodiscard]] auto dot(const Vec3& other) const -> double;
};
} // namespace rtweek

#endif
