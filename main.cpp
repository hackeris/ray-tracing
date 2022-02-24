#include <iostream>

int main() {

    //  size
    const int image_width = 256;
    const int image_height = 256;

    //  render
    std::cout << "P3" << std::endl << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; j -= 1) {
        for (int i = 0; i < image_width; i += 1) {
            auto r =  double (i)    /(image_width-1);
            auto g = double(j) / (image_height - 1);
            auto b = 0.5;

            int ir = static_cast<int>(255.99 * r);
            int ig = static_cast<int>(255.99 * g);
            int ib = static_cast<int>(255.99 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    return 0;
}
