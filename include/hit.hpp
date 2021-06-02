#ifndef RTWEEK_HIT_H
#define RTWEEK_HIT_H

#include <optional>

#include "ray.hpp"
#include "vec3.hpp"

namespace rtweek {

struct HitRecord {
  double t = 0;
  Vec3 normal = {};
};

class Hittable {
 public:
  [[nodiscard]] virtual auto hit(const Ray& r, double t_min, double t_max) const -> std::optional<HitRecord> = 0;
};

} // namespace rtweek

#endif
