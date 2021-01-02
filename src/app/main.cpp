#include <iostream>

#include "rtweek/color.hpp"
#include "rtweek/ray.hpp"
#include "rtweek/vec3.hpp"

rtweek::Color sky_color(const rtweek::Ray& ray) {
	const auto t = 0.5 * (ray.direction.unit().y + 1.0);
	return (1.0 - t) * rtweek::Color(0.5, 0.7, 1.0) + t * rtweek::Color(1.0, 1.0, 1.0);
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

	for (auto y = 0; y < image_height; y++) {
		std::cerr << "Processing line " << y + 1 << " over " << image_height << '\n';
		for (auto x = 0; x < image_width; x++) {
			const auto u = static_cast<double>(x) / image_width;
			const auto v = static_cast<double>(y) / image_height;

			const auto ray   = rtweek::Ray(origin, lower_left_corner + u * horizontal + v * vertical);
			const auto color = sky_color(ray);
			std::cout << color << '\n';
		}
	}
}
