#include "integrator.h"
#include "scene.h"

using namespace std;

class DirectIntegrator : public Integrator {
public:
    DirectIntegrator(const PropertyList& props) {
        /* No parameters this time */
    }

    Color3f Li(const Scene* scene, const Ray& ray) const {
        Hit hit = Hit();
        scene->intersect(ray, hit);
        if (hit.foundIntersection()) {
            // To be replace by phong computation
            Color3f color = 0;
            float *dist = 0;
            for (Light *l : scene->lightList()) 
            {
                Color3f ro = hit.shape()->material()->brdf(-ray.direction,l->direction(ray.at(hit.t())),hit.normal(), hit.textCoord());
                color += ro*(std::max(l->direction(ray.at(hit.t()), dist).dot(hit.normal()), .0f) * (l->intensity(ray.at(hit.t()))));
            }
            return color;
        }
        else
            return scene->backgroundColor();
    }

    std::string toString() const {
        return "FlatIntegrator[]";
    }
};

REGISTER_CLASS(DirectIntegrator, "direct")
