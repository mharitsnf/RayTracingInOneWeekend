//
// Created by Mohamad Harits Nur Fauzan on 13/06/23.
//

#ifndef RAYTRACINGINONEWEEKEND_DIFFUSE_LIGHT_H
#define RAYTRACINGINONEWEEKEND_DIFFUSE_LIGHT_H

#include "material.h"
#include "../textures/solid_color.h"

class diffuse_light : public material  {
public:
    diffuse_light(shared_ptr<texture> a) : emit(a) {}
    diffuse_light(color c) : emit(make_shared<solid_color>(c)) {}

    virtual bool scatter(
            const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
    ) const override {
        return false;
    }

    virtual color emitted(double u, double v, const point3& p) const override {
        return emit->value(u, v, p);
    }

public:
    shared_ptr<texture> emit;
};

#endif //RAYTRACINGINONEWEEKEND_DIFFUSE_LIGHT_H
