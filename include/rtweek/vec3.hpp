#ifndef RTWEEK_VEC3_H
#define RTWEEK_VEC3_H

namespace rtweek {

class Vec3 {
  public:
	double x = 0;
	double y = 0;
	double z = 0;

  public:
	Vec3();
	Vec3(double _x, double _y, double _z);

	Vec3 operator-() const;
	double operator[](int i) const;
	double& operator[](int i);
	Vec3 operator+(const Vec3& v) const;
	Vec3 operator-(const Vec3& v) const;
	Vec3 operator*(const Vec3& v) const;
	Vec3 operator*(double t) const;
	Vec3 operator/(double t) const;
	Vec3& operator+=(const Vec3& vec3);
	Vec3& operator*=(const Vec3& vec3);
	Vec3& operator/=(const Vec3& vec3);

	double dot(const Vec3& v) const;
	Vec3 cross(const Vec3& v) const;

	Vec3 unit() const;

	double len() const;
	double len_squared() const;
};

Vec3 operator*(double t, const Vec3& u);

const auto origin = Vec3(0, 0, 0);

}  // namespace rtweek

#endif
