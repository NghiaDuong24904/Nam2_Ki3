class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction();
    Fraction(int numerator, int denominator);
    Fraction operator +(const Fraction &other);
    Fraction sub(const Fraction &other);
    Fraction operator *(const Fraction &other);
    Fraction div(const Fraction &other);
    void display1();
    double display2();
    bool operator >(const Fraction &other);
    bool operator <(const Fraction &other);
    bool operator ==(const Fraction &other);
    bool operator >=(const Fraction &other);
    bool operator <=(const Fraction &other);
    bool operator !=(const Fraction &other);
    friend std::istream &operator>>(std::istream &input, Fraction &frac);
    friend std::ostream &operator<<(std::ostream &output, const Fraction &frac);
};
