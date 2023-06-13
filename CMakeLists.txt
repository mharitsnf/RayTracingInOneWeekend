cmake_minimum_required(VERSION 3.25)
project(RayTracingInOneWeekend)

set(CMAKE_CXX_STANDARD 17)

add_executable(RayTracingInOneWeekend main.cpp common/vec3/vec3.h common/vec3/color.h common/ray/ray.h common/hittables/hittable.h common/hittables/sphere.h common/hittables/hittable_list.h common/util.h common/camera/camera.h common/materials/material.h common/hittables/moving_sphere.h common/aabb.h common/hittables/bvh_node.h common/textures/texture.h common/materials/lambertian.h common/materials/metal.h common/materials/dielectric.h common/textures/solid_color.h common/textures/checker_texture.h)
