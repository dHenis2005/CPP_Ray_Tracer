#ifndef HIT_H
#define HIT_H

#include "Ray.h"

class Hit {
public:
    double dist;
    Point3 point;
    Vec3 normal;
    bool front;

    inline void set_face(const Ray& r, const Vec3& norm) {
        front = dot(r.direction(), norm) < 0;
        if (front)
            normal = norm;
        else
            normal = -norm;
    }
};

class Hittable {
public:
    virtual ~Hittable() = default;
    virtual bool hit(const Ray& r, double dist_min, double dist_max, Hit& rec) const = 0;
};

#endif