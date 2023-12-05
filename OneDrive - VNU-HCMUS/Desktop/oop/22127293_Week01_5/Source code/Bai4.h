#pragma once
#include <iostream>
#include "Bai3.h"
class Rectangle
{
private:
    Point2D top_left;
    Point2D top_right;
    Point2D bot_right;
    Point2D bot_left;

public:
    Rectangle();
    void input(Point2D top_left, Point2D top_right, Point2D bot_right, Point2D bot_left);
    void output();
    bool valid(); // check 3 cap vuong goc
    double Perimeter();
    double Area();
};