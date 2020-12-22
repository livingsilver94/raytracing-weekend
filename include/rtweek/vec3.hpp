#ifndef RTWEEK_VEC3_H
#define RTWEEK_VEC3_H
namespace rtweek {
class Vec3
{
  public:
	double x = 0;
	double y = 0;
	double z = 0;

  public:
	Vec3() = default;
	Vec3(double _x, double _y, double _z);

	Vec3 operator-() const;
	double operator[](int i) const;
	double& operator[](int i);
	Vec3& operator+=(const Vec3& vec3);
	Vec3& operator*=(const Vec3& vec3);
	Vec3& operator/=(const Vec3& vec3);

	double len() const;
	double len_squared() const;
};
}

#endif
