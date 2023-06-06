//
// Created by Mohamad Harits Nur Fauzan on 05/06/23.
//

#ifndef RAYTRACINGINONEWEEKEND_RAY_H
#define RAYTRACINGINONEWEEKEND_RAY_H

#include "vec3.h"

class ray {
public:
    point3 orig;
    vec3 dir;

public:
    ray() {}
    ray(const point3& origin, const vec3& direction)
            : orig(origin), dir(direction)
    {}

    point3 origin() const  { return orig; }
    vec3 direction() const { return dir; }

    point3 at(double t) const {
        return orig + t*dir;
    }
};

#endif //RAYTRACINGINONEWEEKEND_RAY_H
