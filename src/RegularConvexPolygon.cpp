#define _USE_MATH_DEFINES

#include "RegularCovexPolygon.h"
#include "Point.h"

#include <cmath>
#include <iostream>

RegularConvexPolygon::RegularConvexPolygon(const int &num_vertices, const double &radius)
    : GeometricBase(num_vertices), m_radius(radius)
{
    create_vertices();
};

void RegularConvexPolygon::create_vertices()
{
    const double angle_increment = (m_num_vertices - 2.0f) / m_num_vertices * M_PI;
    double current_angle = 0.0;

    for (size_t i = 0; i < m_num_vertices; i++)
    {
        m_vertices.emplace_back(sin(current_angle) * m_radius, cos(current_angle) * m_radius);
        current_angle += angle_increment;
    }
}
