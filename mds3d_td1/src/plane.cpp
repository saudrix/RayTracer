#include "plane.h"

Plane::Plane()
{
}

Plane::Plane(const PropertyList &propList)
{
    m_position = propList.getPoint("position",Point3f(0,0,0));
    m_normal = propList.getVector("normal",Point3f(0,0,1));
}

Plane::~Plane()
{
}

bool Plane::intersect(const Ray& ray, Hit& hit) const
{
    /// TODO
    Vector3f o = ray.origin;
    Vector3f d = ray.direction;

    float t = (m_position.dot(m_normal) - o.dot(m_normal)) / d.dot(m_normal);

    if (t < 0)
        return false;
    else if(t > 0)
    {
        hit.setT(t);
        hit.setNormal(m_normal);
        hit.setShape(this);
        //hit.setTextCoord();
        return true;
    }
    else return false;
}

REGISTER_CLASS(Plane, "plane")
