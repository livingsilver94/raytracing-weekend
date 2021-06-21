#ifndef RTWEEK_HIT_H
#define RTWEEK_HIT_H

#include <memory>
#include <optional>
#include <vector>

#include "ray.hpp"
#include "vec3.hpp"

namespace rtweek {

struct HitRecord {
  double t = 0;
  Vec3 normal = {};
};

class Hittable {
 public:
  [[nodiscard]] virtual auto hit(const Ray& r, double t_min, double t_max) const -> std::optional<HitRecord> = 0;
};

class HittableList : public Hittable {
 private:
  std::vector<std::shared_ptr<Hittable>> objects = {};

 public:
  HittableList();
  HittableList(std::shared_ptr<Hittable> obj);

  auto add(std::shared_ptr<Hittable> obj) -> void;
  auto clear() -> void;
  [[nodiscard]] auto hit(const Ray& r, double t_min, double t_max) const -> std::optional<HitRecord> override;
};

} // namespace rtweek

#endif
