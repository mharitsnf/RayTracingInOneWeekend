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
};


#endif //RAYTRACINGINONEWEEKEND_MATERIAL_H
