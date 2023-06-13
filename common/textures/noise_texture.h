//
// Created by Mohamad Harits Nur Fauzan on 13/06/23.
//

#ifndef RAYTRACINGINONEWEEKEND_NOISE_TEXTURE_H
#define RAYTRACINGINONEWEEKEND_NOISE_TEXTURE_H

#include "texture.h"
#include "../perlin/perlin.h"

class noise_texture : public texture {
public:
    perlin noise;
    double scale;

public:
    noise_texture() {}
    noise_texture(double sc) : scale(sc) {}

    virtual color value(double u, double v, const point3& p) const override {
        return color(1,1,1) * 0.5 * (1 + sin(scale*p.z() + 10*noise.turb(p)));
    }
};

#endif //RAYTRACINGINONEWEEKEND_NOISE_TEXTURE_H
