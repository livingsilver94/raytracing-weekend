#include <cmath>
#include <iostream>
#include <limits>
#include <memory>

#include "rtweek/color.hpp"
#include "rtweek/hit.hpp"
#include "rtweek/ray.hpp"
#include "rtweek/sphere.hpp"
#include "rtweek/vec3.hpp"

auto colorize(const rtweek::Ray& ray, const rtweek::Hittable& world) -> rtweek::Color {
	if (auto hit = world.hit(ray, 0, std::numeric_limits<double>::infinity()); hit.has_value()) {
		const auto n = hit->normal;
		return 0.5 * rtweek::Color(n.x + 1, n.y + 1, n.z + 1);
	}
	const auto t = 0.5 * (ray.direction.unit().y + 1.0);
	return (1.0 - t) * rtweek::Color(1.0, 1.0, 1.0) + t * rtweek::Color(0.5, 0.7, 1.0);
}

int main() {
	// Image.
	constexpr auto aspect_ratio = 16.0 / 9.0;
	constexpr auto image_width  = 400;
	constexpr auto image_height = static_cast<int>(image_width / aspect_ratio);

	// World.
	auto world = rtweek::HittableList();
	world.add(std::make_shared<rtweek::Sphere>(rtweek::Vec3(0, 0, -1), 0.5));
	world.add(std::make_shared<rtweek::Sphere>(rtweek::Vec3(0, -100.5, -1), 100));

	// Camera.
	constexpr auto viewport_height = 2.0;
	constexpr auto viewport_width  = aspect_ratio * viewport_height;
	constexpr auto focal_length    = 1.0;
	constexpr auto horizontal      = rtweek::Vec3(viewport_width, 0, 0);
	constexpr auto vertical        = rtweek::Vec3(0, viewport_height, 0);
	constexpr auto lower_left_corner =
	  rtweek::origin - horizontal / 2 - vertical / 2 - rtweek::Vec3(0, 0, focal_length);

	// Print PPM header.
	std::cout << "P3\n" << image_width << ' ' << image_height << "\n" << rtweek::max_color << "\n";
	for (auto y = image_height - 1; y >= 0; y--) {
		std::cerr << "Processing line " << image_height - y << " over " << image_height << '\n';
		for (auto x = 0; x < image_width; x++) {
			const auto u = static_cast<double>(x) / (image_width - 1);
			const auto v = static_cast<double>(y) / (image_height - 1);

			const auto ray   = rtweek::Ray(rtweek::origin, lower_left_corner + u * horizontal + v * vertical);
			const auto color = colorize(ray, world);
			std::cout << color << '\n';
		}
	}
}
