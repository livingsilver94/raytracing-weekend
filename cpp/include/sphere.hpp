#ifndef RTWEEK_SPHERE_H
#define RTWEEK_SPHERE_H

#include <optional>

#include "hit.hpp"
#include "ray.hpp"
#include "vec3.hpp"

namespace rtweek {
class Sphere : public Hittable {
 public:
  Vec3 center = {};
  double radius = 0;

 public:
  Sphere();
  Sphere(const Vec3& center, double radius);

  [[nodiscard]] auto hit(const Ray& r, double t_min, double t_max) const -> std::optional<HitRecord> override;
};
} // namespace rtweek

#endif
