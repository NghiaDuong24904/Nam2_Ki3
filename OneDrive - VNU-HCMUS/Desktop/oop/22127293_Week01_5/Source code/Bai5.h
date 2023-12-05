#pragma once
#include <iostream>
class Student
{
private:
    double mathGrade;
    double englishGrade;
    double programmingGrade;

public:
    Student();
    void setGrade(double mathGrade, double englishGrade, double progammingGrade);
    bool valid();
    double aver_Grade();
    bool excellent();
};