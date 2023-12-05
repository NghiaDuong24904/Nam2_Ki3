#include <iostream>
#include <cmath>
#include "Bai3.h"
Point2D::Point2D()
{
    this->x = 0;
    this->y = 0;
}
void Point2D::input(double x, double y)
{
    this->x = x;
    this->y = y;
}
void Point2D::output()
{
    std::cout << "(" << x << "," << y << ")";
}
double Point2D::distant(const Point2D &other)
{
    return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}

