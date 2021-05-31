#include <iostream>

#include "color.hpp"

constexpr int MAX_COLOR = 255;

auto main() -> int {
  const auto width = 256;
  const auto height = 256;

  std::cout << "P3\n"
            << width << ' ' << height << "\n255\n";

  for (auto j = height - 1; j >= 0; j--) {
    for (auto i = 0; i < width; i++) {
      const auto color = rtweek::Color(double(i) / (width - 1), double(j) / (height - 1), 0.25);
      std::cout << color;
    }
  }
}
