#include <iostream>
#include <iomanip>
#include "Bai2.h"

char month_table[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char leap_month_table[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool is_leap(int year)
{
    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) ? true : false;
}
bool Date::valid()
{
    if (year < 0)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (is_leap(year))
    {
        if (day < 1 || day > leap_month_table[month - 1])
            return false;
    }
    else
    {
        if (day < 1 || day > month_table[month - 1])
            return false;
    }
    return true;
}
Date::Date()
{
    this->day = 0;
    this->month = 0;
    this->year = 0;
}
void Date::input(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}
void Date::output()
{
    std::cout << std::setfill('0') << std::setw(2) << day << "-"
              << std::setfill('0') << std::setw(2) << month << "-"
              << std::setfill('0') << std::setw(4) << year;
}
Date Date::inc_1day()
{
    Date res;
    int new_day = day + 1;
    int new_month = month;
    int new_year = year;
    if (is_leap(new_year))
    {
        if (new_day > leap_month_table[new_month - 1])
        {
            new_day = 1;
            new_month++;
            if (new_month > 12)
            {
                new_month = 1;
                new_year++;
            }
        }
    }
    else
    {
        if (new_day > month_table[new_month - 1])
        {
            new_day = 1;
            new_month++;
            if (new_month > 12)
            {
                new_month = 1;
                new_year++;
            }
        }
    }
    res.input(new_day, new_month, new_year);
    return res;
}
Date Date::inc_ndays(int n)
{
    Date res;
    res.input(day, month, year);
    for (int i = 0; i < n; i++)
    {
        res = res.inc_1day();
    }
    return res;
}
Date Date::dec_1day()
{
    {
        Date res;
        int new_day = day - 1;
        int new_month = month;
        int new_year = year;
        if (is_leap(new_year))
        {
            if (new_day == 0)
            {
                new_month--;
                if (new_month == 0)
                {
                    new_year--;
                    new_month = 12;
                }
                new_day = leap_month_table[new_month - 1];
            }
        }
        else
        {
            if (new_day == 0)
            {
                new_month--;
                if (new_month == 0)
                {
                    new_year--;
                    new_month = 12;
                }
                new_day = month_table[new_month - 1];
            }
        }
        res.input(new_day, new_month, new_year);
        return res;
    }
}
Date Date::dec_ndays(int n)
{
    Date res;
    res.input(day, month, year);
    for (int i = 0; i < n; i++)
    {
        res = res.dec_1day();
    }
    return res;
}
short int Date::compare(const Date &other)
{
    if (year > other.year)
    {
        return 1;
    }
    else if (year == other.year)
    {
        if (month == other.month)
        {
            if (day == other.day)
                return 0;
            else if (day > other.day)
                return 1;
            else
                return -1;
        }
        else if (month > other.month)
            return 1;
        else
            return -1;
    }
    else
        return -1;
}