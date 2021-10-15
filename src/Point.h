#ifndef POINT_H
#define POINT_H

class Point
{
private:
    double m_x, m_y;

public:
    Point();
    Point(const double &x, const double &y);
    void print() const;
    friend void print(const Point &pt);
    friend Point operator+(const Point &pt1, const Point &pt2);
    friend Point operator-(const Point &pt1, const Point &pt2);
    friend Point operator*(const double &number, const Point &pt);
    friend Point operator*(const Point &pt, const double &number);
    friend Point operator/(const Point &pt1, const double &number);
};

#endif