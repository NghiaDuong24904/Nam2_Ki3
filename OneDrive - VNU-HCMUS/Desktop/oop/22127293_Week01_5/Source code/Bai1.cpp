#include <iostream>
#include "Bai1.h"
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}
Fraction::Fraction()
{
    this->numerator = 0;
    this->denominator = 1;
}
Fraction::Fraction(int numerator, int denominator)
{
    this->numerator = numerator;
    this->denominator = denominator;
}
Fraction &Fraction::operator=(const Fraction &other)
{
    if (this != &other)
    {
        this->numerator = other.numerator;
        this->denominator = other.denominator; 
    }
    return *this; 
}
Fraction Fraction::sub(const Fraction &other)
{
    int new_numerator = numerator * other.denominator - other.numerator * denominator;
    int new_denominator = denominator * other.denominator;
    int gcd_value = gcd(new_numerator, new_denominator);
    if (gcd_value < 0)
        gcd_value *= (-1);
    Fraction result(new_numerator / gcd_value, new_denominator / gcd_value);
    return result;
}
Fraction Fraction::operator*(const Fraction &other)
{
    int new_numerator = numerator * other.numerator;
    int new_denominator = denominator * other.denominator;
    int gcd_value = gcd(new_numerator, new_denominator);
    if (gcd_value < 0)
        gcd_value *= (-1);
    Fraction result(new_numerator / gcd_value, new_denominator / gcd_value);
    return result;
}
Fraction Fraction::div(const Fraction &other)
{
    int new_numerator = numerator * other.denominator;
    int new_denominator = denominator * other.numerator;
    int gcd_value = gcd(new_numerator, new_denominator);
    if (gcd_value < 0)
        gcd_value *= (-1);
    Fraction result(new_numerator / gcd_value, new_denominator / gcd_value);
    return result;
}
void Fraction::display1()
{
    if (denominator < 0)
    {
        denominator *= (-1);
        numerator *= (-1);
        std::cout << numerator << "/" << denominator;
    }

    else
        std::cout << numerator << "/" << denominator;
}
double Fraction::display2()
{
    double res = double(numerator) / denominator;
    return res;
}
bool Fraction::operator>(const Fraction &other)
{
    double leftValue = static_cast<double>(numerator) / denominator;
    double rightValue = static_cast<double>(other.numerator) / other.denominator;
    return leftValue > rightValue;
}
bool Fraction::operator<(const Fraction &other)
{
    double leftValue = static_cast<double>(numerator) / denominator;
    double rightValue = static_cast<double>(other.numerator) / other.denominator;
    return leftValue < rightValue;
}

bool Fraction::operator==(const Fraction &other)
{
    return numerator * other.denominator == other.numerator * denominator;
}
bool Fraction::operator<=(const Fraction &other)
{
    return operator<(other) || operator==(other);
}
bool Fraction::operator>=(const Fraction &other)
{
    return operator>(other) || operator==(other);
}
bool Fraction::operator!=(const Fraction &other)
{
    return numerator * other.denominator != other.numerator * denominator;
}

Fraction Fraction::operator+(const Fraction &other)
{
    int new_numerator = numerator * other.denominator + other.numerator * denominator;
    int new_denominator = denominator * other.denominator;
    int gcd_value = gcd(new_numerator, new_denominator);
    Fraction result(new_numerator / gcd_value, new_denominator / gcd_value);
    return result;
}
std::istream &operator>>(std::istream &input, Fraction &frac)
{
    char slash;
    input >> frac.numerator >> slash >> frac.denominator;
    if (frac.denominator == 0)
    {
        std::cerr << "Error: Denominator cannot be zero!" << std::endl;
        exit(1);
    }
    return input;
}

std::ostream &operator<<(std::ostream &output, const Fraction &frac)
{
    output << frac.numerator << "/" << frac.denominator;
    return output;
}
