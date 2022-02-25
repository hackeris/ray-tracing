//
// Created by rainm on 2022/2/25.
//

#ifndef RAY_TRACING_HITTABLE_H
#define RAY_TRACING_HITTABLE_H

#include "ray.h"

struct hit_record {
    point3 p;
    vec3 normal;
    double t{0};
};

class hittable {
public:
    virtual bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const = 0;

    virtual ~hittable() = default;
};

#endif //RAY_TRACING_HITTABLE_H
