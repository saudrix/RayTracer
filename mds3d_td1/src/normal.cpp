#include "integrator.h"
#include "scene.h"

class NormalIntegrator : public Integrator {
public:
    NormalIntegrator(const PropertyList& props) {
        /* No parameters this time */
    }

    Color3f Li(const Scene* scene, const Ray& ray) const {
        Hit hit = Hit();
        scene->intersect(ray, hit);
        if (hit.foundIntersection()){
            return Color3f(abs(hit.normal().x()), abs(hit.normal().y()), abs(hit.normal().z()));
        }
        else
            return Color3f(0, 0, 0);
    }

    std::string toString() const {
        return "NormalIntegrator[]";
    }
};

REGISTER_CLASS(NormalIntegrator, "normal")
