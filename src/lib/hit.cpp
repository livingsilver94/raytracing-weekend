#include "hit.hpp"

#include <memory>
#include <optional>
#include <utility>

#include "ray.hpp"

namespace rtweek {

HittableList::HittableList() = default;
HittableList::HittableList(std::shared_ptr<Hittable> obj) {
  this->add(std::move(obj));
};

auto HittableList::add(std::shared_ptr<Hittable> obj) -> void {
  this->objects.push_back(std::move(obj));
}

auto HittableList::clear() -> void {
  this->objects.clear();
}

auto HittableList::hit(const Ray& r, double t_min, double t_max) const -> std::optional<HitRecord> {
  auto closest_t = t_max;
  auto record = std::optional<HitRecord>(std::nullopt);
  for (const auto& obj : this->objects) {
    if (const auto hit = obj->hit(r, t_min, closest_t); hit.has_value()) {
      record = hit;
      closest_t = hit->t;
    }
  }
  return record;
}

} // namespace rtweek
