cmake_minimum_required(VERSION 3.25)
project(RayTracingInOneWeekend)

set(CMAKE_CXX_STANDARD 17)

add_executable(RayTracingInOneWeekend main.cpp common/vec3.h common/color.h common/ray.h common/hittable.h common/sphere.h common/hittable_list.h common/util.h)
