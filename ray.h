//
// Created by rainm on 2022/2/24.
//

#ifndef RAY_TRACING_RAY_H
#define RAY_TRACING_RAY_H

#include "vec3.h"

class ray {
public:
    ray() = default;

    ray(const point3 &origin, const vec3 &direction)
            : orig(origin), dir(direction) {}

    [[nodiscard]]
    const point3 &origin() const { return orig; }

    [[nodiscard]]
    const vec3 &direction() const { return dir; }

    [[nodiscard]]
    point3 at(double t) const {
        return orig + t * dir;
    }

public:
    point3 orig;
    vec3 dir;
};

#endif //RAY_TRACING_RAY_H
