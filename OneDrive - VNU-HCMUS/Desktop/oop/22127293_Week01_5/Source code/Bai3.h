#pragma once
#include <iostream>
class Point2D
{
private:
    double x;
    double y;

public:
    Point2D();
    void input(double x, double y);
    void output();
    double distant(const Point2D &other);
    friend bool help_check(Point2D p1, Point2D p2, Point2D p3); // tich vo huong 2 vector = 0 thi vuong goc
};
