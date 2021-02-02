#ifndef RTWEEK_RAY_H
#define RTWEEK_RAY_H

#include "vec3.hpp"

namespace rtweek {

class Ray {
  public:
	Vec3 origin;
	Vec3 direction;

  public:
	constexpr Ray(const Vec3& _origin, const Vec3& _direction) : origin {_origin}, direction {_direction} {}

	[[nodiscard]] constexpr auto at(double t) const -> Vec3 {
		return Vec3(this->origin + this->direction * t);
	}
};

}  // namespace rtweek

#endif
