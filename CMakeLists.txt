cmake_minimum_required(VERSION 3.25)
project(RayTracingInOneWeekend)

set(CMAKE_CXX_STANDARD 17)

add_executable(RayTracingInOneWeekend main.cpp common/vec3.h common/color.h common/ray.h common/hittables/hittable.h common/hittables/sphere.h common/hittables/hittable_list.h common/util.h common/camera.h common/material.h common/hittables/moving_sphere.h common/aabb.h common/hittables/bvh_node.h common/texture.h)
