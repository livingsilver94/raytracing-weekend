#ifndef RTWEEK_SPHERE_H
#define RTWEEK_SPHERE_H

#include <optional>

#include "hit.hpp"
#include "vec3.hpp"

namespace rtweek {

class Sphere : public Hittable {
  public:
	Vec3 center;
	double radius;

  public:
	Sphere();
	Sphere(const Vec3& center, double radius);

	std::optional<Hit> hit(const Ray& r, double t_min, double t_max) const override;
};

}  // namespace rtweek

#endif
