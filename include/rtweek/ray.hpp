#ifndef RTWEEK_RAY_H
#define RTWEEK_RAY_H

#include "vec3.hpp"

namespace rtweek {

class Ray {
  public:
	Vec3 origin;
	Vec3 direction;

  public:
	Ray();
	Ray(const Vec3& origin, const Vec3& direction);

	Vec3 at(double t) const;
};

}  // namespace rtweek

#endif
