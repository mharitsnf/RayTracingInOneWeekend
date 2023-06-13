//
// Created by Mohamad Harits Nur Fauzan on 12/06/23.
//

#ifndef RAYTRACINGINONEWEEKEND_TEXTURE_H
#define RAYTRACINGINONEWEEKEND_TEXTURE_H

#include "../util.h"

// Base texture class

class texture {
public:
    virtual color value(double u, double v, const point3& p) const = 0;
};

#endif //RAYTRACINGINONEWEEKEND_TEXTURE_H
