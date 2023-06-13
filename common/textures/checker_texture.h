//
// Created by Mohamad Harits Nur Fauzan on 13/06/23.
//

#ifndef RAYTRACINGINONEWEEKEND_CHECKER_TEXTURE_H
#define RAYTRACINGINONEWEEKEND_CHECKER_TEXTURE_H

#include "texture.h"
#include "solid_color.h"

class checker_texture : public texture {
public:
    checker_texture() {}

    checker_texture(shared_ptr<texture> _even, shared_ptr<texture> _odd)
            : even(_even), odd(_odd) {}

    checker_texture(color c1, color c2)
            : even(make_shared<solid_color>(c1)) , odd(make_shared<solid_color>(c2)) {}

    virtual color value(double u, double v, const point3& p) const override {
        auto sines = sin(10*p.x())*sin(10*p.y())*sin(10*p.z());
        if (sines < 0)
            return odd->value(u, v, p);
        else
            return even->value(u, v, p);
    }

public:
    shared_ptr<texture> odd;
    shared_ptr<texture> even;
};

#endif //RAYTRACINGINONEWEEKEND_CHECKER_TEXTURE_H
