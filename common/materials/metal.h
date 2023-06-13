//
// Created by Mohamad Harits Nur Fauzan on 13/06/23.
//

#ifndef RAYTRACINGINONEWEEKEND_METAL_H
#define RAYTRACINGINONEWEEKEND_METAL_H

#include "material.h"

class metal : public material {
public:
    metal(const color& a, double f) : albedo(a), fuzz(f < 1 ? f : 1) {}

    virtual bool scatter(
            const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
    ) const override {
        vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
        scattered = ray(rec.p, reflected + fuzz*random_in_unit_sphere(), r_in.time());
        attenuation = albedo;
        return (dot(scattered.direction(), rec.normal) > 0);
    }

public:
    color albedo;
    double fuzz;
};

#endif //RAYTRACINGINONEWEEKEND_METAL_H
