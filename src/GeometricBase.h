#ifndef GEOMETRICBASE_H
#define GEOMETRICBASE_H

#include "Point.h"
#include <vector>

class GeometricBase
{
protected:
    int m_num_vertices;
    std::vector<Point> m_vertices;

protected:
    virtual void create_vertices() = 0;

public:
    GeometricBase(const int &num_vertices);
    const Point &operator[](int i) const;
    int get_num_vertices() const;
    void print() const;
};

#endif