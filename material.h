//
// Created by rainm on 2022/2/25.
//

#ifndef RAY_TRACING_MATERIAL_H
#define RAY_TRACING_MATERIAL_H

#include "common.h"

#include "ray.h"

struct hit_record;

class material {
public:
    virtual bool scatter(
            const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered
    ) const = 0;
};

class lambertian : public material {
public:
    explicit lambertian(const color &a) : albedo(a) {}

    bool scatter(const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const override;

public:
    color albedo;
};

bool lambertian::scatter(const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const {

    auto scatter_direction = rec.normal + random_unit_vector();

    if (scatter_direction.near_zero()) {
        scatter_direction = rec.normal;
    }

    scattered = ray(rec.p, scatter_direction);
    attenuation = albedo;
    return true;
}

class metal : public material {
public:
    explicit metal(const color &a, double f) : albedo(a), fuzz(f) {}

    bool scatter(const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const override;

public:
    color albedo;
    double fuzz;
};

bool metal::scatter(const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const {

    vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
    scattered = ray(rec.p, reflected + fuzz * random_in_unit_sphere());
    attenuation = albedo;
    return (dot(scattered.direction(), rec.normal) > 0);
}

class dielectric : public material {
public:
    explicit dielectric(double index_of_refraction) : ir(index_of_refraction) {}

    bool scatter(const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const override;

private:
    static double reflectance(double cosine, double ref_idx) {
        auto r0 = (1 - ref_idx) / (1 + ref_idx);
        r0 = r0 * r0;
        return r0 + (1 - r0) * pow(1 - cosine, 5);
    }

public:
    double ir;
};

bool dielectric::scatter(const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const {

    attenuation = color(1.0, 1.0, 1.0);

    double refraction_ratio = rec.front_face ? (1.0 / ir) : ir;

    vec3 unit_direction = unit_vector(r_in.direction());
    double cos_theta = fmin(dot(-unit_direction, rec.normal), 1.0);
    double sin_theta = sqrt(1.0 - cos_theta * cos_theta);

    bool cannot_refract = refraction_ratio * sin_theta > 1.0;
    vec3 direction;
    if (cannot_refract || reflectance(cos_theta, refraction_ratio) > random_double()) {
        direction = reflect(unit_direction, rec.normal);
    } else {
        direction = refract(unit_direction, rec.normal, refraction_ratio);
    }

    scattered = ray(rec.p, direction);
    return true;
}

#endif //RAY_TRACING_MATERIAL_H
