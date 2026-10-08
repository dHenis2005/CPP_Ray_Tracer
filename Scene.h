#ifndef SCENE_H
#define SCENE_H

#include "Shapes.h"
#include <vector>

class Scene: public Hittable {
public:
    std::vector<Hittable*> objects;

    Scene() {}
    void add(Hittable* obj) {
        objects.push_back(obj);
    }
    bool hit(const Ray& r, double dist_min, double dist_max, Hit& rec) const override {
        Hit temp_rec;
        bool hit_obj = false;
        double close = dist_max;
        for (Hittable* object : objects) {
            if (object->hit(r, dist_min, close, temp_rec)) {
                hit_obj = true;
                close = temp_rec.dist;
                rec = temp_rec;
            }
        }
        return hit_obj;
    }
};

#endif
