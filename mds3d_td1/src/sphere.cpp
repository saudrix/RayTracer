#include "sphere.h"
#include <iostream>

Sphere::Sphere(float radius)
    : m_radius(radius)
{
}

Sphere::Sphere(const PropertyList &propList)
{
    m_radius = propList.getFloat("radius",1.f);
    m_center = propList.getPoint("center",Point3f(0,0,0));
}

Sphere::~Sphere()
{
}

bool Sphere::intersect(const Ray& ray, Hit& hit) const
{
    Vector3f o = ray.origin;
    Vector3f d = ray.direction;

    float delta = (d.dot(o - m_center))*(d.dot(o - m_center)) - (((o - m_center).norm())*((o - m_center).norm()) - m_radius * m_radius);
    //float delta = (d.dot(o-m_center))*(d.dot(o - m_center)) - (((o-m_center).norm())-m_radius);

    if (delta < 0)
    {
        return false;
    }
    else 
    {
        float r1 = -(d.dot(o - m_center)) + sqrt(delta);
        float r2 = -(d.dot(o - m_center)) - sqrt(delta);
        hit.setShape(this);
        if (r1 > 0 && r2 > 0) {
            hit.setT(std::min(r1, r2));
            hit.setNormal((ray.at(std::min(r1, r2)) - m_center).normalized());
        }
        else if (r1 > 0 && r2 < 0) {
            hit.setT(r1);
            hit.setNormal((ray.at(r1) - m_center).normalized());
        }
        else {
            hit.setT(r2);
            hit.setNormal((ray.at(r2) - m_center).normalized());
        }
        return true;
    }

    /// TODO: compute ray-sphere intersection

    throw RTException("Sphere::intersect not implemented yet.");

}

REGISTER_CLASS(Sphere, "sphere")
