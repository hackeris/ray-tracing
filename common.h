//
// Created by rainm on 2022/2/25.
//

#ifndef RAY_TRACING_COMMON_H
#define RAY_TRACING_COMMON_H

#include <cmath>
#include <limits>
#include <memory>
#include <random>
#include <chrono>

#include "ray.h"
#include "vec3.h"

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

inline double random_double() {
    static auto now = std::chrono::system_clock::now().time_since_epoch().count();
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator(now);
    return distribution(generator);
}

inline double random_double(double min, double max) {
    return min + (max - min) * random_double();
}

inline double clamp(double x, double min, double max) {
    if (x < min) { return min; }
    if (x > max) { return max; }
    return x;
}

#endif //RAY_TRACING_COMMON_H
