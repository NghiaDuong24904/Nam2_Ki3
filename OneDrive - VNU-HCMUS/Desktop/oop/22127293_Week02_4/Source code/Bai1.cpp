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
    if (denominator == 0)
    {
        denominator = 1;
    }
    int gcd_value = gcd(numerator, denominator);
    this->numerator = numerator / gcd_value;
    this->denominator = denominator / gcd_value;
    if (this->denominator < 0)
    {
        this->numerator = -numerator;
        this->denominator = -denominator;
    }
}
Fraction::Fraction(const Fraction &other)
{
    this->numerator = other.numerator;
    this->denominator = other.denominator;
    int gcd_value = gcd(numerator, denominator);
    this->numerator = numerator / gcd_value;
    this->denominator = denominator / gcd_value;
    if (this->denominator < 0)
    {
        this->numerator = -numerator;
        this->denominator = -denominator;
    }
}
Fraction &Fraction::operator=(const Fraction &other)
{
    if (this == &other)
    {
        return *this;
    }
    this->numerator = other.numerator;
    this->denominator = other.denominator;

    return *this;
}

Fraction Fraction::operator+(const Fraction &other)
{
    int new_numerator = numerator * other.denominator + other.numerator * denominator;
    int new_denominator = denominator * other.denominator;
    int gcd_value = gcd(new_numerator, new_denominator);
    if (new_denominator < 0)
    {
        new_numerator = -new_numerator;
        new_denominator = -new_denominator;
    }
    Fraction result(new_numerator / gcd_value, new_denominator / gcd_value);
    return result;
}
Fraction Fraction::operator-(const Fraction &other)
{
    int new_numerator = numerator * other.denominator - other.numerator * denominator;
    int new_denominator = denominator * other.denominator;
    int gcd_value = gcd(new_numerator, new_denominator);
    if (new_denominator < 0)
    {
        new_numerator = -new_numerator;
        new_denominator = -new_denominator;
    }
    Fraction result(new_numerator / gcd_value, new_denominator / gcd_value);
    return result;
}
Fraction Fraction::operator*(const Fraction &other)
{
    int new_numerator = numerator * other.numerator;
    int new_denominator = denominator * other.denominator;
    int gcd_value = gcd(new_numerator, new_denominator);
    if (new_denominator < 0)
    {
        new_numerator = -new_numerator;
        new_denominator = -new_denominator;
    }
    Fraction result(new_numerator / gcd_value, new_denominator / gcd_value);
    return result;
}
Fraction Fraction::operator/(const Fraction &other)
{
    int new_numerator, new_denominator;
    if (other.numerator == 0)
    {
        std::cout << "Cannot divide by zero!\n";
        new_numerator = 0;
        new_denominator = 1;
    }
    else
    {
        new_numerator = numerator * other.denominator;
        new_denominator = denominator * other.numerator;
    }
    int gcd_value = gcd(new_numerator, new_denominator);
    if (new_denominator < 0)
    {
        new_numerator = -new_numerator;
        new_denominator = -new_denominator;
    }
    Fraction result(new_numerator / gcd_value, new_denominator / gcd_value);
    return result;
}

Fraction Fraction::operator+(int other)
{
    int new_numerator = numerator * 1 + other * denominator;
    int new_denominator = denominator;
    int gcd_value = gcd(new_numerator, new_denominator);
    if (new_denominator < 0)
    {
        new_numerator = -new_numerator;
        new_denominator = -new_denominator;
    }
    Fraction result(new_numerator / gcd_value, new_denominator / gcd_value);
    return result;
}
Fraction Fraction::operator-(int other)
{
    int new_numerator = numerator * 1 - other * denominator;
    int new_denominator = denominator;
    int gcd_value = gcd(new_numerator, new_denominator);
    if (new_denominator < 0)
    {
        new_numerator = -new_numerator;
        new_denominator = -new_denominator;
    }
    Fraction result(new_numerator / gcd_value, new_denominator / gcd_value);
    return result;
}
Fraction operator*(int p1, const Fraction &p2)
{
    int new_numerator = p2.numerator * p1;
    int new_denominator = p2.denominator;
    int gcd_value = gcd(new_numerator, new_denominator);
    if (new_denominator < 0)
    {
        new_numerator = -new_numerator;
        new_denominator = -new_denominator;
    }
    Fraction result(new_numerator / gcd_value, new_denominator / gcd_value);
    return result;
}

Fraction operator+(int p1, const Fraction &p2)
{
    int new_numerator = p2.numerator + p1 * p2.denominator;
    int new_denominator = p2.denominator;
    int gcd_value = gcd(new_numerator, new_denominator);
    if (new_denominator < 0)
    {
        new_numerator = -new_numerator;
        new_denominator = -new_denominator;
    }
    Fraction result(new_numerator / gcd_value, new_denominator / gcd_value);
    return result;
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

std::ostream &operator<<(std::ostream &out, const Fraction &frac)
{
    if (frac.denominator == 1)
    {
        out << frac.numerator;
    }
    else
        out << frac.numerator << "/" << frac.denominator;

    return out;
}

Fraction &Fraction::operator+=(const Fraction &other)
{
    int new_numerator = numerator * other.denominator + other.numerator * denominator;
    int new_denominator = denominator * other.denominator;
    int gcd_value = gcd(new_numerator, new_denominator);
    if (new_denominator < 0)
    {
        new_numerator = -new_numerator;
        new_denominator = -new_denominator;
    }
    this->numerator = new_numerator / gcd_value;
    this->denominator = new_denominator / gcd_value;
    return *this;
}
Fraction &Fraction::operator-=(const Fraction &other)
{
    int new_numerator = numerator * other.denominator - other.numerator * denominator;
    int new_denominator = denominator * other.denominator;
    int gcd_value = gcd(new_numerator, new_denominator);
    if (new_denominator < 0)
    {
        new_numerator = -new_numerator;
        new_denominator = -new_denominator;
    }
    this->numerator = new_numerator / gcd_value;
    this->denominator = new_denominator / gcd_value;
    return *this;
}
Fraction &Fraction::operator*=(const Fraction &other)
{
    int new_numerator = numerator * other.numerator;
    int new_denominator = denominator * other.denominator;
    int gcd_value = gcd(new_numerator, new_denominator);
    if (new_denominator < 0)
    {
        new_numerator = -new_numerator;
        new_denominator = -new_denominator;
    }
    this->numerator = new_numerator / gcd_value;
    this->denominator = new_denominator / gcd_value;
    return *this;
}
Fraction &Fraction::operator/=(const Fraction &other)
{
    int new_numerator, new_denominator;
    if (other.numerator == 0)
    {
        std::cout << "Cannot divide by zero!\n";
        return *this;
    }
    else
    {
        new_numerator = numerator * other.denominator;
        new_denominator = denominator * other.numerator;
    }
    int gcd_value = gcd(new_numerator, new_denominator);
    if (new_denominator < 0)
    {
        new_numerator = -new_numerator;
        new_denominator = -new_denominator;
    }
    this->numerator = new_numerator / gcd_value;
    this->denominator = new_denominator / gcd_value;
    return *this;
}

Fraction Fraction::operator++(int x)
{
    Fraction d(*this);
    numerator = numerator + denominator;
    return d;
}
Fraction &Fraction::operator++()
{
    numerator = numerator + denominator;
    return *this;
}
Fraction Fraction::operator--(int x)
{
    Fraction d(*this);
    numerator = numerator - denominator;
    return d;
}
Fraction &Fraction::operator--()
{
    numerator = numerator - denominator;
    return *this;
}


Fraction::operator int() {
    return numerator / denominator;
}

Fraction::operator float()
{
    return static_cast<float>(numerator) / denominator;
}