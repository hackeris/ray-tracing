//
// Created by rainm on 2022/2/25.
//

#ifndef RAY_TRACING_HITTABLE_LIST_H
#define RAY_TRACING_HITTABLE_LIST_H

#include <memory>
#include <utility>
#include <vector>

#include "hittable.h"

using std::shared_ptr;
using std::make_shared;

class hittable_list : public hittable {
public:
    hittable_list() = default;

    explicit hittable_list(const shared_ptr<hittable> &object) { add(object); }

    void clear() { objects.clear(); }

    void add(const shared_ptr<hittable> &object) { objects.push_back(object); }

    bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const override;

public:
    std::vector<shared_ptr<hittable>> objects;
};

bool hittable_list::hit(const ray &r, double t_min, double t_max, hit_record &rec) const {

    hit_record temp;

    bool hit_anything = false;
    auto closest_so_far = t_max;

    for (const auto &object: objects) {
        if (object->hit(r, t_min, closest_so_far, temp)) {
            hit_anything = true;
            closest_so_far = temp.t;
            rec = temp;
        }
    }

    return hit_anything;
}

#endif //RAY_TRACING_HITTABLE_LIST_H
