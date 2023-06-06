#include "common/util.h"

#include "common/color.h"
#include "common/hittable_list.h"
#include "common/sphere.h"
#include "common/camera.h"

#include <iostream>


color ray_color(const ray& r, const hittable& world) {
    hit_record rec;
    if (world.hit(r, 0, infinity, rec)) {
        return 0.5 * (rec.normal + color(1,1,1));
    }
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

int main() {

    // Image
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    const int samples_per_pixel = 100;

    // World
    hittable_list world;
    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    // Camera
    camera cam;

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int i = image_height-1; i >= 0; --i) {
        std::cerr << "\rScanlines remaining: " << i << ' ' << std::flush;

        for (int j = 0; j < image_width; ++j) {
            // One pixel gets to be computated multiple times, according to the number of samples specified above.
            // The result is stored here
            color pixel_color(0, 0, 0);

            for (int s = 0; s < samples_per_pixel; ++s) {

                // The random double is for "finding" the neighbors
                auto u = (j + random_double()) / (image_width-1);
                auto v = (i + random_double()) / (image_height-1);
                ray r = cam.get_ray(u, v);
                pixel_color += ray_color(r, world);
            }

            // And then here, the program will divide / normalize the accumulated value by dividing it
            // by the number of samples specified above.
            write_color(std::cout, pixel_color, samples_per_pixel);

        }
    }

    std::cerr << "\nDone.\n";

    return 0;
}
