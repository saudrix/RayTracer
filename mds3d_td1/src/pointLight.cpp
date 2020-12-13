#include "light.h"

class PointLight : public Light
{
public:
    PointLight(const PropertyList &propList)
        : Light(propList.getColor("intensity", Color3f(1.f)))
    {
        m_position = propList.getPoint("position", Point3f::UnitX());
    }

    Vector3f direction(const Point3f& x, float* dist = 0) const
    {
        /// TODO
        /**dist = sqrt((x.x() - m_position.x()) * (x.x() - m_position.x())
                   + (x.y() - m_position.y()) * (x.y() - m_position.y())
                   + (x.z() - m_position.z()) * (x.z() - m_position.z()));*/
        if(dist != nullptr) *dist = (m_position - x).norm();
        return (m_position - x).normalized();
        //return Vector3f(x.x() - m_position.x(), x.y() - m_position.y(), x.z() - m_position.z());
    }

    Color3f intensity(const Point3f& x) const
    {
        /// TODO
        //float* dist;
        //this->direction(x, dist);
        float dist = sqrt((x.x() - m_position.x()) * (x.x() - m_position.x())
                        + (x.y() - m_position.y()) * (x.y() - m_position.y())
                        + (x.z() - m_position.z()) * (x.z() - m_position.z()));
        //float distance = (m_position - x).norm()
        return m_intensity / (dist * dist);
    }

    std::string toString() const {
        return tfm::format(
            "PointLight[\n"
            "  intensity = %s\n"
            "  position = %s\n"
            "]", m_intensity.toString(),
                 ::toString(m_position));
    }

protected:
    Point3f m_position;
};

REGISTER_CLASS(PointLight, "pointLight")
