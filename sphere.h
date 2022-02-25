//
// Created by rainm on 2022/2/25.
//

#ifndef RAY_TRACING_SPHERE_H
#define RAY_TRACING_SPHERE_H

#include "vec3.h"
#include "hittable.h"

class sphere : public hittable {
public:
    sphere() : center(), radius{0} {}

    sphere(point3 cen, double r) : center(cen), radius(r) {}

    bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const override;

public:
    point3 center;
    double radius;
};

bool sphere::hit(const ray &r, double t_min, double t_max, hit_record &rec) const {

    vec3 oc = r.origin() - center;
    auto a = r.direction().length_squared();
    auto half_b = dot(oc, r.direction());
    auto c = oc.length_squared() - radius * radius;

    auto discriminant = half_b * half_b - a * c;
    if (discriminant < 0) {
        return false;
    }

    auto sqrtd = std::sqrt(discriminant);
    auto root = (-half_b - sqrtd) / a;
    if (root < t_min || t_max < root) {
        root = (-half_b + sqrtd) / a;
        if (root < t_min || t_max < root) {
            return false;
        }
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    rec.normal = (rec.p - center) / radius;
    return true;
}

#endif //RAY_TRACING_SPHERE_H
