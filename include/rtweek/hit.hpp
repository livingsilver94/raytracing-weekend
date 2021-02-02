#ifndef RTWEEK_HIT_H
#define RTWEEK_HIT_H

#include <optional>

#include "ray.hpp"
#include "vec3.hpp"

namespace rtweek {

struct Hit {
	double t;
	Vec3 point;
	bool front_facing;
	Vec3 normal;

	constexpr Hit(double t, const Ray& ray, const Vec3& out_normal) :
	    t {t},
	    point {ray.at(t)},
	    front_facing {ray.direction.dot(out_normal) < 0},
	    normal {this->front_facing ? out_normal : -out_normal} {}
};

class Hittable {
  public:
	[[nodiscard]] virtual auto hit(const Ray& r, double t_min, double t_max) const -> std::optional<Hit> = 0;
};

}  // namespace rtweek

#endif
