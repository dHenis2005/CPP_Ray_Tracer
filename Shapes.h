#ifndef SHAPES_H
#define SHAPES_H

#include <cmath>
#include "Hit.h"

class Sphere : public Hittable {
public:
    Point3 center;
    double radius;

    Sphere() : center(Point3(0, 0, 0)), radius(0) {}
    Sphere(Point3 c, double r) : center(c), radius(r) {}

    bool hit(const Ray& r, double dist_min, double dist_max, Hit& rec) const override {
        Vec3 oc = r.origin() - center;
        double a = r.direction().length_squared();
        double half_b = dot(oc, r.direction());
        double c = oc.length_squared() - radius * radius;

        double delta = half_b * half_b - a * c;
        if (delta < 0) return false;

        double sqrtd = std::sqrt(delta);
        double root = (-half_b - sqrtd) / a;
        if (root < dist_min || dist_max < root) {
            root = (-half_b + sqrtd) / a;
            if (root < dist_min || dist_max < root)
                return false;
        }

        rec.dist = root;
        rec.point = r.at(rec.dist);
        Vec3 outward_normal = (rec.point - center) / radius;
        rec.set_face(r, outward_normal);
        return true;
    }
};

class Plane : public Hittable {
public:
    Point3 plane_point;
    Vec3 normal;

    Plane() : plane_point(Point3(0, 0, 0)), normal(Vec3(0, 1, 0)) {}
    Plane(Point3 p, Vec3 n) : plane_point(p), normal(unit_vector(n)) {}

    bool hit(const Ray& r, double dist_min, double dist_max, Hit& rec) const override {
        Vec3 vector_to_plane = plane_point - r.origin();
        double dist = dot(vector_to_plane, normal) / dot(r.direction(), normal);

        if (dist < dist_min || dist > dist_max)
            return false;

        rec.dist = dist;
        rec.point = r.at(dist);
        rec.set_face(r, normal);
        return true;
    }
};

#endif