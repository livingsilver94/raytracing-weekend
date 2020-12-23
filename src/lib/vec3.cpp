#include "rtweek/vec3.hpp"

#include <cmath>
#include <sstream>
#include <stdexcept>

namespace rtweek {

Vec3::Vec3() = default;

Vec3::Vec3(double _x, double _y, double _z) : x {_x}, y {_y}, z {_z} {}

Vec3 Vec3::operator-() const {
	return Vec3 {-this->x, -this->y, -this->z};
}

double& Vec3::operator[](int i) {
	switch (i) {
		case 0: return this->x;
		case 1: return this->y;
		case 2: return this->z;
		default:
			std::stringstream fmt;
			fmt << "Invalid index value: " << i;
			throw std::invalid_argument(fmt.str());
	}
}

double Vec3::operator[](int i) const {
	return this->operator[](i);
}

Vec3 Vec3::operator+(const Vec3& v) const {
	return Vec3(this->x + v.x, this->y + v.y, this->z + v.z);
}

Vec3 Vec3::operator-(const Vec3& v) const {
	return Vec3(this->x - v.x, this->y - v.y, this->z - v.z);
}

Vec3 Vec3::operator*(const Vec3& v) const {
	return Vec3(this->x * v.x, this->y * v.y, this->z * v.z);
}

Vec3 Vec3::operator*(double t) const {
	return Vec3(this->x * t, this->y * t, this->z * t);
}

Vec3 Vec3::operator/(double t) const {
	return (1 / t) * (*this);
}

Vec3& Vec3::operator+=(const Vec3& vec3) {
	this->x += vec3.x;
	this->y += vec3.y;
	this->z += vec3.z;
	return *this;
}

Vec3& Vec3::operator*=(const Vec3& vec3) {
	this->x *= vec3.x;
	this->y *= vec3.y;
	this->z *= vec3.z;
	return *this;
}

Vec3& Vec3::operator/=(const Vec3& vec3) {
	this->x /= vec3.x;
	this->y /= vec3.y;
	this->z /= vec3.z;
	return *this;
}

double Vec3::dot(const Vec3& v) const {
	return this->x * v.x + this->y * v.y + this->z * v.z;
}

Vec3 Vec3::cross(const Vec3& v) const {
	return Vec3(this->y * v.z - this->z * v.y, this->z * v.x - this->x * v.z, this->x * v.y - this->y * v.x);
}

double Vec3::len_squared() const {
	return this->x * this->x + this->y * this->y + this->z * this->z;
}

Vec3 Vec3::unit() const {
	return (*this)/this->len();
}

double Vec3::len() const {
	return std::sqrt(this->len_squared());
}

Vec3 operator*(double t, const Vec3& u) {
	return u * t;
}

}  // namespace rtweek
