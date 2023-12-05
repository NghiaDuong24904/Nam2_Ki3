#include <iostream>
#include <iomanip>
#include "Bai2.cpp"
#include "Bai3.cpp"
#include "Bai4.cpp"
#include "Bai5.cpp"

int main()
{
    // Bài 2
    std::cout << "Bai 2 --------------- \n";
    Date date;
    int day, month, year;
    std::cout << "Enter day: ";
    std::cin >> day;
    std::cout << "Enter month: ";
    std::cin >> month;
    std::cout << "Enter year: ";
    std::cin >> year;
    date.input(day, month, year);
    if (!date.valid())
    {
        do
        {
            std::cout << "Error!!!\n";
            std::cout << "Enter day again: ";
            std::cin >> day;
            std::cout << "Enter month again: ";
            std::cin >> month;
            std::cout << "Enter year again: ";
            std::cin >> year;
            date.input(day, month, year);
        } while (!date.valid());
    }
    std::cout << "Date: ";
    date.output();
    std::cout << "\n";
    Date tomorrow = date.inc_1day();
    std::cout << "Tomorrow: ";
    tomorrow.output();
    std::cout << "\n";

    Date yesterday = date.dec_1day();
    std::cout << "Yesterday: ";
    yesterday.output();
    std::cout << "\n";

    int n = 0;
    std::cout << "Enter n days increase: ";
    std::cin >> n;
    Date inc_n = date.inc_ndays(n);
    std::cout << "Date after increasing " << n << " days: ";
    inc_n.output();
    std::cout << "\n";

    std::cout << "Enter n days decrease: ";
    std::cin >> n;
    Date dec_n = date.dec_ndays(n);
    std::cout << "Date after decreasing " << n << " days: ";
    dec_n.output();
    std::cout << "\n";

    std::cout << "Enter other day: ";
    std::cin >> day;
    std::cout << "Enter other month: ";
    std::cin >> month;
    std::cout << "Enter other year: ";
    std::cin >> year;
    Date ss;
    ss.input(day, month, year);
    if (!ss.valid())
    {
        do
        {
            std::cout << "Error!!!\n";
            std::cout << "Enter other day again: ";
            std::cin >> day;
            std::cout << "Enter other month again: ";
            std::cin >> month;
            std::cout << "Enter other year again: ";
            std::cin >> year;
            ss.input(day, month, year);
        } while (!ss.valid());
    }
    date.output();
    if (date.compare(ss) == 0)
        std::cout << " = ";
    else if (date.compare(ss) == 1)
        std::cout << " > ";
    else
        std::cout << " < ";
    ss.output();
    // // Bài 3
    std::cout << "\nBai 3 --------------- \n";
    double x, y;
    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << "Enter y: ";
    std::cin >> y;
    Point2D A;
    A.input(x, y);
    A.output();
    std::cout << "\nEnter other x: ";
    std::cin >> x;
    std::cout << "Enter other y: ";
    std::cin >> y;
    Point2D B;
    B.input(x, y);
    B.output();
    std::cout << "\nDistant from ";
    A.output();
    std::cout << " to ";
    B.output();
    std::cout << ": ";
    std::cout << A.distant(B);
    // Bài 4
    std::cout << "\nBai 4 --------------- \n";
    Point2D top_left, top_right, bot_left, bot_right;
    std::cout << "Enter x of top-left: ";
    std::cin >> x;
    std::cout << "Enter y of top-left: ";
    std::cin >> y;
    top_left.input(x, y);
    std::cout << "Enter x of top-right: ";
    std::cin >> x;
    std::cout << "Enter y of top-right: ";
    std::cin >> y;
    top_right.input(x, y);
    std::cout << "Enter x of bottom-right: ";
    std::cin >> x;
    std::cout << "Enter y of bottom-right: ";
    std::cin >> y;
    bot_right.input(x, y);
    std::cout << "Enter x of bottom-left: ";
    std::cin >> x;
    std::cout << "Enter y of bottom-left: ";
    std::cin >> y;
    bot_left.input(x, y);
    Rectangle hcn;
    hcn.input(top_left, top_right, bot_right, bot_left);
    if (hcn.valid())
    {
        std::cout << "is rectangle\n";
        std::cout << "Perimeter: " << hcn.Perimeter() << "\n";
        std::cout << "Area: " << hcn.Area() << "\n";
    }
    else
        std::cout << "isn't rectangle\n";

    // Bài 5
    std::cout << "Bai 5 --------------- \n";
    Student hcmus;
    double math, english, programming;
    std::cout << "Enter math grade: ";
    std::cin >> math;
    std::cout << "Enter english grade: ";
    std::cin >> english;
    std::cout << "Enter programming grade: ";
    std::cin >> programming;
    hcmus.setGrade(math, english, programming);
    if (!hcmus.valid())
    {
        do
        {
            std::cout << "Error !!!";
            std::cout << "Enter math grade again: ";
            std::cin >> math;
            std::cout << "Enter english grade again: ";
            std::cin >> english;
            std::cout << "Enter programming grade again: ";
            std::cin >> programming;
        } while (!hcmus.valid());
    }
    std::cout << "Average grade: " << hcmus.aver_Grade() << "\n";
    if (hcmus.excellent())
    {
        std::cout << "is excellent student";
    }
    else
        std::cout << "isn't excellent student";
    return 0;
}