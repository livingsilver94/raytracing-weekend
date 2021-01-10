#ifndef RTWEEK_RAY_H
#define RTWEEK_RAY_H

#include "vec3.hpp"

namespace rtweek {

class Ray {
  public:
	Vec3 origin    = origin;
	Vec3 direction = origin;

  public:
	Ray();
	Ray(const Vec3& _origin, const Vec3& _direction);

	Vec3 at(double t) const;
};

}  // namespace rtweek

#endif
