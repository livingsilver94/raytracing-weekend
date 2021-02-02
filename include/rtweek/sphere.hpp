#ifndef RTWEEK_SPHERE_H
#define RTWEEK_SPHERE_H

#include <cmath>
#include <optional>

#include "hit.hpp"
#include "vec3.hpp"

namespace rtweek {

class Sphere : public Hittable {
  public:
	Vec3 center;
	double radius;

  public:
	constexpr Sphere(const Vec3& _center, double _radius) : center {_center}, radius {_radius} {}

	[[nodiscard]] auto hit(const Ray& r, double t_min, double t_max) const -> std::optional<Hit> override;
};

}  // namespace rtweek
#endif
