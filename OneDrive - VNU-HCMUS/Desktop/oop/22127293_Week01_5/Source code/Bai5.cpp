#include <iostream>
#include "Bai5.h"
Student::Student()
{
    this->mathGrade = 0;
    this->englishGrade = 0;
    this->programmingGrade = 0;
}
void Student::setGrade(double mathGrade, double englishGrade, double programmingGrade)
{
    this->mathGrade = mathGrade;
    this->englishGrade = englishGrade;
    this->programmingGrade = programmingGrade;
}
double Student::aver_Grade()
{
    return static_cast<double>((mathGrade + englishGrade + programmingGrade)) / 3;
}
bool Student::excellent()
{
    if (aver_Grade() > 8 && mathGrade >= 6.5 && englishGrade >= 6.5 && programmingGrade >= 6.5)
        return true;
    else
        return false;
}
bool Student::valid()
{
    if (mathGrade < 0 || mathGrade > 10 || englishGrade > 10 || englishGrade < 0 || programmingGrade > 10 || programmingGrade > 10)
        return false;
    else
        return true;
}