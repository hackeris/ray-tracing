cmake_minimum_required(VERSION 3.21)
project(ray_tracing)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        ray_tracing
        main.cpp
        vec3.h
        color.h
        ray.h
        hittable.h
        sphere.h
        hittable_list.h
        common.h
        camera.h
        material.h
)

SET(CMAKE_BUILD_TYPE "Release")
