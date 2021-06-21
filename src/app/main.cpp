#include <iostream>
#include <limits>
#include <memory>
#include <optional>

#include "color.hpp"
#include "hit.hpp"
#include "ray.hpp"
#include "sphere.hpp"
#include "vec3.hpp"

using namespace rtweek;

auto sky(const Ray& r) -> Color {
  const auto direction = r.dir.unit();
  const auto t = 0.5 * (direction.y + 1.0);
  return (1.0 - t) * Color(1, 1, 1) + t * Color(0.5, 0.7, 1.0);
}

auto color(const Ray& r, const HittableList& world) -> Color {
  const auto hit = world.hit(r, 0, std::numeric_limits<double>::infinity());
  if (hit.has_value()) {
    const auto n = hit->normal;
    return 0.5 * (Color(n.x, n.y, n.z) + Color(1, 1, 1));
  }
  return sky(r);
}

auto main() -> int {
  // Image.
  const auto aspect_ratio = 16.0 / 9.0;
  const auto img_width = 400;
  const auto img_height = static_cast<int>(img_width / aspect_ratio);

  // World.
  auto world = HittableList();
  world.add(std::make_shared<Sphere>(Vec3(0, 0, -1), 0.5));
  world.add(std::make_shared<Sphere>(Vec3(0, -100.5, -1), 100));

  // Camera.
  const auto viewport_height = 2.0;
  const auto viewport_width = aspect_ratio * viewport_height;
  const auto focal_length = 1.0;

  const auto origin = Vec3(0, 0, 0);
  const auto horizontal = Vec3(viewport_width, 0, 0);
  const auto vertical = Vec3(0, viewport_height, 0);
  const auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - Vec3(0, 0, focal_length);

  std::cout << "P3\n"
            << img_width << ' ' << img_height << "\n255\n";

  for (auto j = img_height - 1; j >= 0; j--) {
    for (auto i = 0; i < img_width; i++) {
      const auto u = double(i) / (img_width - 1);
      const auto v = double(j) / (img_height - 1);
      const auto r = Ray(origin, lower_left_corner + u * horizontal + v * vertical - origin);
      std::cout << color(r, world);
    }
  }
}
