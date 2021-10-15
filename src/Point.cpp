#include "Point.h"

#include <iostream>

Point::Point() : m_x(0), m_y(0){};

Point::Point(const double &x, const double &y) : m_x(x), m_y(y){};

void Point::print() const
{
    std::cout << "Point: (" << m_x << "," << m_y << ")" << std::endl;
};

const double Point::get_x() const { return m_x; };

const double Point::get_y() const { return m_y; };

void print(const Point &pt)
{
    std::cout << "Point: (" << pt.m_x << "," << pt.m_y << ")" << std::endl;
};

Point operator+(const Point &pt1, const Point &pt2)
{
    Point res;
    res.m_x = pt1.m_x + pt2.m_x;
    res.m_y = pt1.m_y + pt2.m_y;
    return res;
};

Point operator-(const Point &pt1, const Point &pt2)
{
    Point res;
    res.m_x = pt1.m_x - pt2.m_x;
    res.m_y = pt1.m_y - pt2.m_y;
    return res;
};

Point operator*(const double &number, const Point &pt)
{
    Point res;
    res.m_x = number * pt.m_x;
    res.m_y = number * pt.m_y;
    return res;
};

Point operator*(const Point &pt, const double &number)
{
    Point res;
    res.m_x = number * pt.m_x;
    res.m_y = number * pt.m_y;
    return res;
};

Point operator/(const Point &pt, const double &number)
{
    Point res;
    res.m_x = pt.m_x / number;
    res.m_y = pt.m_y / number;
    return res;
};
