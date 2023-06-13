//
// Created by Mohamad Harits Nur Fauzan on 13/06/23.
//

#ifndef RAYTRACINGINONEWEEKEND_LAMBERTIAN_H
#define RAYTRACINGINONEWEEKEND_LAMBERTIAN_H

#include "material.h"
#include "../textures/solid_color.h"

class lambertian : public material {
public:
    shared_ptr<texture> albedo;

public:
    lambertian(const color& a) : albedo(make_shared<solid_color>(a)) {}
    lambertian(shared_ptr<texture> a) : albedo(a) {}

    virtual bool scatter(
            const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
    ) const override {
        auto scatter_direction = rec.normal + random_unit_vector();

        // Catch degenerate scatter direction
        if (scatter_direction.near_zero())
            scatter_direction = rec.normal;

        scattered = ray(rec.p, scatter_direction, r_in.time());
        attenuation = attenuation = albedo->value(rec.u, rec.v, rec.p);
        return true;
    }
};

#endif //RAYTRACINGINONEWEEKEND_LAMBERTIAN_H
