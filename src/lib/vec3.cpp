#include <cmath>
#include <rtweek/vec3.hpp>

namespace rtweek {

auto Vec3::len() const -> double {
	return std::sqrt(len_squared());
}

auto Vec3::unit() const -> Vec3 {
	return (*this) / this->len();
}

}  // namespace rtweek
