//
// Created by hnurfauzan on 2023-06-07.
//

#ifndef RAYTRACINGINONEWEEKEND_MATERIAL_H
#define RAYTRACINGINONEWEEKEND_MATERIAL_H

#include "../util.h"
#include "../textures/texture.h"

struct hit_record;

class material {
public:
    virtual bool scatter(
            const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
    ) const = 0;

    virtual color emitted(double u, double v, const point3& p) const {
        return color(0,0,0);
    }
};


#endif //RAYTRACINGINONEWEEKEND_MATERIAL_H
