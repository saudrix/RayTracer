#include "integrator.h"
#include "scene.h"

class FlatIntegrator : public Integrator{
public:
    FlatIntegrator(const PropertyList &props) {
        /* No parameters this time */
    }

    Color3f Li(const Scene *scene, const Ray &ray) const {
        Hit hit = Hit();
        scene->intersect(ray, hit);
        if (hit.foundIntersection())
            //return Color3f(0, 0, 0);
            return hit.shape()->material()->ambientColor();
        else
            return Color3f(0, 0, 0);
    }

    std::string toString() const {
        return "FlatIntegrator[]";
    }
}; 

REGISTER_CLASS(FlatIntegrator, "flat")
