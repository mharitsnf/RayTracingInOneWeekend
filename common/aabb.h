//
// Created by Mohamad Harits Nur Fauzan on 12/06/23.
//

#ifndef RAYTRACINGINONEWEEKEND_AABB_H
#define RAYTRACINGINONEWEEKEND_AABB_H

#include "util.h"

class aabb {
public:
    point3 minimum;
    point3 maximum;

public:
    aabb() {}
    aabb(const point3& a, const point3& b) { minimum = a; maximum= b; }

    point3 min() { return minimum; }
    point3 max() { return maximum; }

    bool hit(const ray& r, double t_min, double t_max) const {
        for (int a = 0; a < 3; a++) {
            auto invD = 1.0f / r.direction()[a];
            auto t0 = (minimum[a] - r.origin()[a]) * invD;
            auto t1 = (maximum[a] - r.origin()[a]) * invD;
            if (invD < 0.0f)
                std::swap(t0, t1);
            t_min = t0 > t_min ? t0 : t_min;
            t_max = t1 < t_max ? t1 : t_max;
            if (t_max <= t_min)
                return false;
        }
        return true;
    }
};

// Finds the smallest point (most bottom left) and the largest point (most top right)
// to form a new bounding box based on those points
aabb surrounding_box(aabb box0, aabb box1) {
    point3 small(fmin(box0.min().x(), box1.min().x()),
                 fmin(box0.min().y(), box1.min().y()),
                 fmin(box0.min().z(), box1.min().z()));

    point3 big(fmax(box0.max().x(), box1.max().x()),
               fmax(box0.max().y(), box1.max().y()),
               fmax(box0.max().z(), box1.max().z()));

    return aabb(small,big);
}

#endif //RAYTRACINGINONEWEEKEND_AABB_H
