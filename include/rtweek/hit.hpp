#ifndef RTWEEK_HIT_H
#define RTWEEK_HIT_H

#include <optional>

#include "ray.hpp"
#include "vec3.hpp"

namespace rtweek {

struct Hit {
	double t;
	Vec3 point;
	Vec3 normal;
};

class Hittable {
  public:
	virtual std::optional<Hit> hit(const Ray& r, double t_min, double t_max) const = 0;
};

}  // namespace rtweek

#endif
