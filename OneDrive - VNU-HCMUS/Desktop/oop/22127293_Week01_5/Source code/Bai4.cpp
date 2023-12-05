#include <iostream>
#include "Bai4.h"

Rectangle::Rectangle()
{
    this->top_left = Point2D();
    this->top_right = Point2D();
    this->bot_right = Point2D();
    this->bot_left = Point2D();
}

void Rectangle::input(Point2D top_left, Point2D top_right, Point2D bot_right, Point2D bot_left)
{
    this->top_left = top_left;
    this->top_right = top_right;
    this->bot_right = bot_right;
    this->bot_left = bot_left;
}

void Rectangle::output()
{
    std::cout << "Top-left point: ";
    top_left.output();
    std::cout << "Top-right point: ";
    top_right.output();
    std::cout << "Bottom-right point: ";
    bot_right.output();
    std::cout << "Bottom-left point: ";
    bot_left.output();
}
bool help_check(Point2D p1, Point2D p2, Point2D p3)
{
    return ((p1.x - p2.x) * (p3.x - p2.x) + (p3.y - p2.y) * (p1.y - p2.y) == 0);
}
bool Rectangle::valid()
{
    bool a1 = help_check(top_left, top_right, bot_right);
    bool a2 = help_check(top_right, bot_right, bot_left);
    bool a3 = help_check(bot_right, bot_left, top_left);
    return (a1 && a2 && a3);
}
double Rectangle::Perimeter()
{
    return 2 * (top_left.distant(top_right) + top_right.distant(bot_right));
}
double Rectangle::Area()
{
    return top_left.distant(top_right) * top_right.distant(bot_right);
}
