#ifndef RAY_H
#define RAY_H

#include "Vec3.h"
class Ray {
public:
    Point3 o;
    Vec3 dir;

    Ray() {}
    Ray(const Point3& origin, const Vec3& direction) : o(origin), dir(direction) {}

    Point3 origin() const { return o;}
    Vec3 direction() const { return dir;}

    Point3 at(double t) const {
        return o + t * dir;
    }
};

#endif