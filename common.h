//
// Created by rainm on 2022/2/25.
//

#ifndef RAY_TRACING_COMMON_H
#define RAY_TRACING_COMMON_H

#include <cmath>
#include <limits>
#include <memory>

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


#endif //RAY_TRACING_COMMON_H
