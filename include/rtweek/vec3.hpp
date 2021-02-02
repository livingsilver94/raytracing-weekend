#ifndef RTWEEK_VEC3_H
#define RTWEEK_VEC3_H

namespace rtweek {

class Vec3 {
  public:
	double x;
	double y;
	double z;

  public:
	constexpr Vec3(double _x, double _y, double _z) : x {_x}, y {_y}, z {_z} {}

	constexpr auto operator-() const -> Vec3 { return {-x, -y, -z}; }
	constexpr auto operator+(const Vec3& v) const -> Vec3 { return {x + v.x, y + v.y, z + v.z}; }
	constexpr auto operator-(const Vec3& v) const -> Vec3 { return {x - v.x, y - v.y, z - v.z}; }
	constexpr auto operator*(const Vec3& v) const -> Vec3 { return {x * v.x, y * v.y, z * v.z}; }
	constexpr auto operator*(double t) const -> Vec3 { return {x * t, y * t, z * t}; }
	constexpr auto operator/(double t) const -> Vec3 { return {x / t, y / t, z / t}; }
	constexpr auto operator+=(const Vec3& v) -> Vec3& {
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}
	constexpr auto operator*=(const Vec3& v) -> Vec3& {
		x *= v.x;
		y *= v.y;
		z *= v.z;
		return *this;
	}
	constexpr auto operator/=(const Vec3& v) -> Vec3& {
		x /= v.x;
		y /= v.y;
		z /= v.z;
		return *this;
	}

	[[nodiscard]] constexpr auto dot(const Vec3& v) const -> double { return x * v.x + y * v.y + z * v.z; }
	[[nodiscard]] constexpr auto cross(const Vec3& v) const -> Vec3 {
		return {y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x};
	}

	[[nodiscard]] constexpr auto len_squared() const -> double { return x * x + y * y + z * z; }
	[[nodiscard]] auto len() const -> double;
	[[nodiscard]] auto unit() const -> Vec3;
};

constexpr auto operator*(double t, const Vec3& u) -> Vec3 {
	return u * t;
}

constexpr inline Vec3 origin {0, 0, 0};

}  // namespace rtweek

#endif
