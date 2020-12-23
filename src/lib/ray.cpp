#include "rtweek/ray.hpp"

#include "rtweek/vec3.hpp"

namespace rtweek {

Ray::Ray() = default;

Ray::Ray(const Vec3& _origin, const Vec3& _direction) : origin {_origin}, direction {_direction} {}

Vec3 Ray::at(double t) const {
	return Vec3(this->origin + this->direction * t);
}

}  // namespace rtweek
