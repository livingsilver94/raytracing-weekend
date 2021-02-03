#include "rtweek/hit.hpp"

#include <memory>
#include <optional>
#include <vector>

#include "rtweek/ray.hpp"

namespace rtweek {

HittableList::HittableList(const std::shared_ptr<const Hittable>& obj) {
	add(obj);
}

auto HittableList::add(const std::shared_ptr<const Hittable>& obj) -> void {
	list.push_back(obj);
}

auto HittableList::clear() -> void {
	list.clear();
}

auto HittableList::hit(const Ray& r, double t_min, double t_max) const -> std::optional<Hit> {
	auto t_closest = t_max;
	auto record    = std::optional<Hit> {};
	for (const auto& obj : list) {
		if (const auto h = obj->hit(r, t_min, t_closest); h.has_value()) {
			record    = h;
			t_closest = h->t;
		}
	}
	return record;
}

}  // namespace rtweek
