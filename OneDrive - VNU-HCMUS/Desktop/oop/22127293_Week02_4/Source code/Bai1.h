class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction();
    Fraction(int numerator, int denominator);
    Fraction(const Fraction &other); // Copy contructor
    Fraction &operator=(const Fraction &other);
    Fraction operator+(const Fraction &other);
    Fraction operator-(const Fraction &other);
    Fraction operator*(const Fraction &other);
    Fraction operator/(const Fraction &other);
    Fraction operator+(int other);
    Fraction operator-(int other);
    friend Fraction operator*(int p1, const Fraction &p2);
    friend Fraction operator+(int p1, const Fraction &p2);
    Fraction &operator-=(const Fraction &other);
    Fraction &operator*=(const Fraction &other);
    Fraction &operator/=(const Fraction &other);
    Fraction operator++(int x);
    Fraction& operator++();
    Fraction operator--(int x);
    Fraction& operator--();
    Fraction& operator+=(const Fraction &other);
    bool operator>(const Fraction &other);
    bool operator<(const Fraction &other);
    bool operator==(const Fraction &other);
    bool operator>=(const Fraction &other);
    bool operator<=(const Fraction &other);
    bool operator!=(const Fraction &other);
    friend std::ostream &operator<<(std::ostream &out, const Fraction &frac);
    operator int();
    operator float();
};
