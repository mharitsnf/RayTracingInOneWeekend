//
// Created by Mohamad Harits Nur Fauzan on 04/06/23.
//

#ifndef RAYTRACINGINONEWEEKEND_COLOR_H
#define RAYTRACINGINONEWEEKEND_COLOR_H

#include "vec3.h"
#include <iostream>

void write_color(std::ostream &out, color pixel_color, int samples_per_pixel) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Divide the color by the number of samples and gamma-correct for gamma=2.0.
    // Gamma correct for 2.0 means n^(1/2). 3 probably means n^(1/3)?
    auto scale = 1.0 / samples_per_pixel;
    r = sqrt(scale * r);
    g = sqrt(scale * g);
    b = sqrt(scale * b);

    int ir = static_cast<int>(256 * clamp(r, 0.0, 0.999));
    int ig = static_cast<int>(256 * clamp(g, 0.0, 0.999));
    int ib = static_cast<int>(256 * clamp(b, 0.0, 0.999));

    // Write the translated [0,255] value of each color component.
    out << ir << ' ' << ig << ' ' << ib << '\n';
}

#endif //RAYTRACINGINONEWEEKEND_COLOR_H
