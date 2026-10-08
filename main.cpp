#include <iostream>
#include <algorithm>
#include "Vec3.h"
#include "Ray.h"
#include "Hit.h"
#include "Shapes.h"
#include "Scene.h"

Color ray_color(const Ray& r, const Scene& world) {
    Hit rec;
    if (world.hit(r, 0.001, 1e9, rec)) {
        Vec3 light_dir = unit_vector(Vec3(1.0, 1.0, 1.5));

        Ray shadow_ray(rec.point, light_dir);
        Hit shadow_rec;
        if (world.hit(shadow_ray, 0.001, 1e9, shadow_rec)) {
            return Color(0.15, 0.15, 0.15);
        }

        double diffuse = std::max(0.0, dot(rec.normal, light_dir));
        double ambient = 0.15;
        double intensity = ambient + 0.85 * diffuse;
        return Color(intensity, intensity, intensity);
    }
    return Color(0.0, 0.0, 0.0);
}

int main() {
    int image_width = 80;
    int image_height = 40;

    Scene world;
    world.add(new Sphere(Point3(0, 0, -1.5), 0.6));
    world.add(new Sphere(Point3(0, -100.6, -1.5), 100));

    double focal_length = 1.0;
    double viewport_height = 2.0;
    double viewport_width = 2.0;

    Point3 camera_c = Point3(0, 0, 0);

    Vec3 viewport_u = Vec3(viewport_width, 0, 0);
    Vec3 viewport_v = Vec3(0, -viewport_height, 0);

    Vec3 pixel_delta_u = viewport_u / image_width;
    Vec3 pixel_delta_v = viewport_v / image_height;

    Point3 top_left = camera_c - Vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    Point3 top_left_pixel = top_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    char ascii_shading[] = " .:-=+*#%@";

    for (int i = 0; i < image_height; i++) {
        for (int j = 0; j < image_width; j++) {
            Point3 pixel_c = top_left_pixel + (j * pixel_delta_u) + (i * pixel_delta_v);
            Vec3 ray_dir = pixel_c - camera_c;
            Ray r(camera_c, ray_dir);
            Color pixel_color = ray_color(r, world);
            int id = (int)(pixel_color.x() * 9);
            if (id < 0)
                id = 0;
            if (id > 9)
                id = 9;
            std::cout << ascii_shading[id];
        }
        std::cout << "\n";
    }

    return 0;
}
