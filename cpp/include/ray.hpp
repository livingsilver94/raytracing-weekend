#ifndef RTWEEK_RAY_H
#define RTWEEK_RAY_H

#include "vec3.hpp"

namespace rtweek {
class Ray {
 public:
  const Vec3 orig = {};
  const Vec3 dir = {};

 public:
  Ray();
  Ray(const Vec3& orig, const Vec3& dir);

  [[nodiscard]] auto at(double t) const -> Vec3;
};
} // namespace rtweek

#endif
