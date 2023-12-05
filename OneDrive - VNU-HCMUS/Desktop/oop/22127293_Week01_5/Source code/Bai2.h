#pragma once
#include <iostream>
#include <iomanip>
bool is_leap(int year); // check nam nhuan
class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date();
    void input(int day, int month, int year); 
    bool valid(); // check ngay ton tai khong
    void output();
    Date inc_1day(); // tomorrow
    Date inc_ndays(int n);
    Date dec_1day(); // yesterday
    Date dec_ndays(int n);
    short int compare(const Date &other);
};