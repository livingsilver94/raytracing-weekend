#include "rtweek/sphere.hpp"

#include <cmath>
#include <optional>

#include "rtweek/hit.hpp"
#include "rtweek/vec3.hpp"

namespace rtweek {

Sphere::Sphere() = default;

Sphere::Sphere(const Vec3& _center, double _radius) : center {_center}, radius {_radius} {}

std::optional<Hit> Sphere::hit(const Ray& r, double t_min, double t_max) const {
	const auto oc     = r.origin - this->center;
	const auto a      = r.direction.len_squared();
	const auto half_b = oc.dot(r.direction);
	const auto c      = oc.len_squared() - this->radius * this->radius;
	const auto discr  = half_b * half_b - a * c;

	if (discr < 0) {
		return std::nullopt;
	}

	const auto sqrt = std::sqrt(discr);
	auto root       = (-half_b - sqrt) / a;
	if (root < t_min || root > t_max) {
		root = (-half_b + sqrt) / a;
		if (root < t_min || root > t_max) {
			return std::nullopt;
		}
	}
	return std::optional<Hit>({root, r.at(root), (r.at(root) - this->center) / this->radius});
}

}  // namespace rtweek
