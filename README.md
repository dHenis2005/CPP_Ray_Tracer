# Terminal Ray Tracer (Pure C++17)

A lightweight, zero-dependency 3D software ray tracer built from scratch in pure C++17. It fires mathematical rays into a 3D scene containing spheres and planes, calculates surface normals, Lambertian diffuse lighting, and real-time cast shadows, then renders the 3D frame directly to the terminal using an ASCII character ramp.

---

## Key Features

- **Zero External Dependencies**: Built entirely with standard C++17 headers (`<iostream>`, `<vector>`, `<cmath>`, `<algorithm>`).
- **3D Vector & Ray Engine**: Custom `Vec3` vector math library (dot product, cross product, normalization) and `Ray` parametrization.
- **Geometric Intersection Math**: Quadratic equation solving for ray-sphere collisions and ray-plane intersections.
- **Polymorphic Scene System**: Abstract `Hittable` parent class allowing dynamic scene objects stored in a `Scene` list.
- **Lighting & Cast Shadows**: Lambertian diffuse shading ($\mathbf{N} \cdot \mathbf{L}$) combined with secondary shadow rays for realistic cast shadows.
- **ASCII Terminal Renderer**: Maps floating-point pixel luminance ($0.0 \dots 1.0$) to a 10-level ASCII character density ramp (`" .:-=+*#%@"`).

---

## Codebase Architecture

| File | Description |
|---|---|
| `Vec3.h` | 3D vector arithmetic, dot product, cross product, and type aliases (`Point3`, `Color`). |
| `Ray.h` | Ray representation $\mathbf{P}(t) = \mathbf{O} + t\mathbf{D}$. |
| `Hit.h` | Collision hit record (`Hit`) and abstract geometry interface (`Hittable`). |
| `Shapes.h` | `Sphere` and `Plane` shape primitives with ray intersection math. |
| `Scene.h` | Scene container storing `std::vector<Hittable*>` and querying closest hits. |
| `main.cpp` | Camera viewport configuration, ray casting loop, lighting, and ASCII rendering. |

---

## Build & Run

Compile and run using `make`:

```bash
make
```

---

## Terminal Output Preview

```
                                                                                
                                    **######                                    
                               +***#####%%%%%%%%%                               
                            =++****#####%%%%%%%%%%%%                            
                          -=+++****#####%%%%%%%%%%%%%%                          
                         -==+++****######%%%%%%%%%%%%%%                         
                        --==+++*****######%%%%%%%%%%%%%%                        
                       :--==++++*****#######%%%%%%%%%%%%%                       
                       :--===++++*****########%%%%%%%%%%%                       
                       ::--===++++******#########%%%%%%%#                       
                       .:--====++++*******###############                       
                       .::--====+++++*******#############                       
         ==============..::---====+++++**********######**==============         
========================..::---=====++++++**************==++++++++++++++++++++++
===================.........::---=====+++++++++******+++++++++++++++++++++++++++
==================............::----======+++++++++++=++++++++++++++++++++++++++
=================+++............:::-----===========-++++++++++++++++++++++++++++
=====++++++++++++++++++............::::----------+++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++................++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
