#include "ray.hpp"

#include "vec3.hpp"

namespace rtweek {
Ray::Ray() = default;
Ray::Ray(const Vec3& orig, const Vec3& dir)
    : orig{orig}, dir{dir} {}

auto Ray::at(double t) const -> Vec3 {
  return this->orig + this->dir * t;
}
} // namespace rtweek
