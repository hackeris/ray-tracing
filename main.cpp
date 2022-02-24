#include <iostream>

#include "vec3.h"
#include "color.h"

int main() {

    //  size
    const int image_width = 256;
    const int image_height = 256;

    //  render
    std::cout << "P3" << std::endl << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; j -= 1) {
        for (int i = 0; i < image_width; i += 1) {

            color pixel{
                    double(i) / (image_width - 1),
                    double(j) / (image_height - 1),
                    0.25
            };

            write_color(std::cout, pixel);
        }
    }

    return 0;
}
