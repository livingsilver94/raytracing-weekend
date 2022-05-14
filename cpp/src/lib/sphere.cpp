#include "sphere.hpp"

#include <cmath>
#include <optional>

#include "hit.hpp"
#include "vec3.hpp"

namespace rtweek {
Sphere::Sphere() = default;
Sphere::Sphere(const Vec3& center, double radius)
    : center{center}, radius{radius} {};

auto Sphere::hit(const Ray& r, double t_min, double t_max) const -> std::optional<HitRecord> {
  const auto oc = r.orig - center;
  const auto a = r.dir.length_sq();
  const auto half_b = oc.dot(r.dir);
  const auto c = oc.length_sq() - radius * radius;
  const auto discriminant = half_b * half_b - a * c;
  if (discriminant < 0) {
    return std::nullopt;
  }

  const auto sqrtd = std::sqrt(discriminant);
  // Find the nearest root that lies in the acceptable range.
  auto root = (-half_b - sqrtd) / a;
  if (root < t_min || t_max < root) {
    root = (-half_b + sqrtd) / a;
    if (root < t_min || t_max < root) {
      return std::nullopt;
    }
  }
  return std::optional<HitRecord>({root, (r.at(root) - center) / radius});
}
} // namespace rtweek
