#include <iostream>

#include "color.hpp"
#include "ray.hpp"

auto sky(const rtweek::Ray& r) -> rtweek::Color {
  const auto t = 0.5 * (r.dir.unit().y + 1.0);
  return (1.0 - t) * rtweek::Color(1.0, 1.0, 1.0) + t * rtweek::Color(0.5, 0.7, 1.0);
}

auto main() -> int {
  // Image.
  const auto aspect_ratio = 16.0 / 9.0;
  const auto img_width = 400;
  const auto img_height = static_cast<int>(img_width / aspect_ratio);

  // Camera.
  const auto viewport_height = 2.0;
  const auto viewport_width = aspect_ratio * viewport_height;
  const auto focal_length = 1.0;

  const auto origin = rtweek::Vec3(0, 0, 0);
  const auto horizontal = rtweek::Vec3(viewport_width, 0, 0);
  const auto vertical = rtweek::Vec3(0, viewport_height, 0);
  const auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - rtweek::Vec3(0, 0, focal_length);

  std::cout << "P3\n"
            << img_width << ' ' << img_height << "\n255\n";

  for (auto j = img_height - 1; j >= 0; j--) {
    for (auto i = 0; i < img_width; i++) {
      const auto u = double(i) / (img_width - 1);
      const auto v = double(j) / (img_height - 1);
      const auto r = rtweek::Ray(origin, lower_left_corner + u * horizontal + v * vertical - origin);
      std::cout << sky(r);
    }
  }
}
