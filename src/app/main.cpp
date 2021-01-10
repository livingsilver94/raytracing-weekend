#include <cmath>
#include <iostream>

#include "rtweek/color.hpp"
#include "rtweek/ray.hpp"
#include "rtweek/vec3.hpp"

double hit_sphere_factor(const rtweek::Vec3& center, double radius, const rtweek::Ray& r) {
	const auto oc     = r.origin - center;
	const auto a      = r.direction.len_squared();
	const auto half_b = oc.dot(r.direction);
	const auto c      = oc.len_squared() - radius * radius;
	const auto discr  = half_b * half_b - a * c;

	if (discr < 0) {
		return -1.0;
	}
	return (-half_b - std::sqrt(discr)) / a;
}

rtweek::Color colorize(const rtweek::Ray& ray) {
	const auto center = rtweek::Vec3(0, 0, -1);
	if (auto f = hit_sphere_factor(center, 0.50, ray); f > 0) {
		const auto n = (ray.at(f) - center).unit();
		return 0.5 * rtweek::Color(n.x + 1, n.y + 1, n.z + 1);
	}
	const auto t = 0.5 * (ray.direction.unit().y + 1.0);
	return (1.0 - t) * rtweek::Color(1.0, 1.0, 1.0) + t * rtweek::Color(0.5, 0.7, 1.0);
}

int main() {
	// Image.
	const auto aspect_ratio = 16.0 / 9.0;
	const auto image_width  = 400;
	const auto image_height = static_cast<int>(image_width / aspect_ratio);

	// Camera.
	const auto viewport_height   = 2.0;
	const auto viewport_width    = aspect_ratio * viewport_height;
	const auto focal_length      = 1.0;
	const auto origin            = rtweek::Vec3(0, 0, 0);
	const auto horizontal        = rtweek::Vec3(viewport_width, 0, 0);
	const auto vertical          = rtweek::Vec3(0, viewport_height, 0);
	const auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - rtweek::Vec3(0, 0, focal_length);

	// Print PPM header.
	std::cout << "P3\n" << image_width << ' ' << image_height << "\n" << rtweek::max_color << "\n";

	for (auto y = image_height - 1; y >= 0; y--) {
		std::cerr << "Processing line " << image_height - y << " over " << image_height << '\n';
		for (auto x = 0; x < image_width; x++) {
			const auto u = static_cast<double>(x) / (image_width - 1);
			const auto v = static_cast<double>(y) / (image_height - 1);

			const auto ray   = rtweek::Ray(origin, lower_left_corner + u * horizontal + v * vertical);
			const auto color = colorize(ray);
			std::cout << color << '\n';
		}
	}
}
