#include "GeometricBase.h"
#include "Point.h"
#include <iostream>
#include <stdexcept>

GeometricBase::GeometricBase(const int &num_vertices) : m_num_vertices(num_vertices)
{
    m_vertices.reserve(num_vertices);
};

const Point &GeometricBase::operator[](int i) const
{
    if (i >= m_vertices.size())
    {
        throw std::runtime_error("Index out of bounds!");
    }
    return m_vertices.at(i);
};

const Point &GeometricBase::get_item(int i) const
{
    if (i >= m_vertices.size())
    {
        throw std::runtime_error("Index out of bounds!");
    }
    return m_vertices.at(i);
};

int GeometricBase::get_num_vertices() const { return m_num_vertices; };

void GeometricBase::print() const
{
    std::cout << "Geometric base with vertices at:" << std::endl;
    for (size_t i = 0; i < m_vertices.size(); i++)
    {
        m_vertices.at(i).print();
    }
};