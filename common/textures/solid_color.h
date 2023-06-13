//
// Created by Mohamad Harits Nur Fauzan on 13/06/23.
//

#ifndef RAYTRACINGINONEWEEKEND_SOLID_COLOR_H
#define RAYTRACINGINONEWEEKEND_SOLID_COLOR_H

#include "texture.h"

class solid_color : public texture {
private:
    color color_value;

public:
    solid_color() {}
    solid_color(color c) : color_value(c) {}

    solid_color(double red, double green, double blue)
            : solid_color(color(red,green,blue)) {}

    virtual color value(double u, double v, const vec3& p) const override {
        return color_value;
    }
};

#endif //RAYTRACINGINONEWEEKEND_SOLID_COLOR_H
