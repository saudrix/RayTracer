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
            Color3f color = Color3f(.0f);
            for (Light *l : scene->lightList()) 
            {
                
                // Inspected secondary Ray
                float distToLamp = .0f;
                Ray bounceRay = Ray(ray.at(hit.t())/* + 0.001 * hit.normal()*/, -l->direction(ray.at(hit.t()), &distToLamp));
                Hit secondaryHit = Hit();
                scene->intersect(bounceRay, secondaryHit);
                // If te light is not obstructed
                if(secondaryHit.foundIntersection() && secondaryHit.t() < distToLamp && hit.shape() != secondaryHit.shape()){
                    //std::cout << hit.shape();
                    //std::cout << "\n"; 
                    /*std::cout << secondaryHit.t();
                    std::cout << "  ||  ";
                    std::cout << distToLamp;
                    std::cout << "\n";*/
                }
                else{
                    // Including light source l
                    Color3f ro = hit.shape()->material()->brdf(-ray.direction, l->direction(ray.at(hit.t())), hit.normal(), hit.textCoord());
                    color += ro * (std::max(l->direction(ray.at(hit.t())).dot(hit.normal()), .0f) * (l->intensity(ray.at(hit.t()))));
                }
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
