#ifndef REGULARCONVEXPOLYGON_H
#define REGULARCONVEXPOLYGON_H

#include "GeometricBase.h"

class RegularConvexPolygon : public GeometricBase
{
private:
    double m_radius;

protected:
    void create_vertices();

public:
    RegularConvexPolygon(const int &num_vertices, const double &radius);
};

#endif