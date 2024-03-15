#include <iostream>
#include <numeric>
#include <string>

class Rational
{
public:
    Rational(int num = 0, int den = 1)
    {
        this->num = num;
        if (den != 0)
            this->den = den;
        else
            this->den = 1;
    }

    int numerator() const
    {
        int realDen = den / std::gcd(num, den);
        int realNum = num / std::gcd(num, den);
        return (realDen < 0) ? -realNum : realNum;
    }

    int denominator() const
    {
        int realDen = den / std::gcd(num, den);
        return abs(realDen);
    }

    Rational operator+(const Rational& r);

    Rational operator-(const Rational& r) const
    {
        return Rational(this->num * r.den - r.num * this->den, this->den * r.den);
    }

    Rational operator-(int val) const
    {
        return Rational(this->num - this->den * val, this->den);
    }

    friend Rational operator-(int val, Rational& r)
    {
        return -Rational(r - val);
    }

    Rational operator*(const Rational& r) const
    {
        return Rational(this->num * r.num, this->den * r.den);
    }

    Rational operator*(int val) const
    {
        return Rational(val * this->num, this->den);
    }

    friend Rational operator*(int val, Rational& r)
    {
        return r * val;
    }

    Rational operator/(const Rational& r) const
    {
        return Rational(this->num * r.den, this->den * r.num);
    }

    Rational operator/(int val) const
    {
        return Rational(this->num, this->den * val);
    }

    friend Rational operator/(int val, Rational& r)
    {
        return Rational(r.den * val, r.num);
    }

    Rational operator+() const
    {
        return *this;
    }

    Rational operator-() const
    {
        return Rational(-this->num, this->den);
    }

    Rational operator+=(const Rational& r)
    {
        *this = *this + r;
        return *this;
    }

    Rational operator-=(const Rational& r)
    {
        *this = *this - r;
        return *this;
    }

    Rational operator*=(const Rational& r)
    {
        *this = *this * r;
        return *this;
    }

    Rational operator/=(const Rational& r)
    {
        *this = *this / r;
        return *this;
    }

    bool operator==(const Rational& r) const
    {
        return this->denominator() == r.denominator() && this->numerator() == r.numerator();
    }

    bool operator!=(const Rational& r) const
    {
        return this->denominator() != r.denominator() || this->numerator() != r.numerator();
    }

    Rational& operator++()
    {
        this->num += this->den;
        return *this;
    }

    Rational& operator--()
    {
        this->num -= this->den;
        return *this;
    }

    Rational operator++(int)
    {
        Rational temp = *this;
        ++*this;
        return temp;
    }

    Rational operator--(int)
    {
        Rational temp = *this;
        --*this;
        return temp;
    }

private:
    int num, den;
};

Rational Rational::operator+(const Rational& r)
{
    return Rational(this->num * r.den - r.num * this->den, this->den * r.den);
}

Rational operator+(int val, Rational& r)
{
    return r + val;
}

std::ostream& operator<<(std::ostream& os, Rational& r)
{
    os << r.numerator() << "/" << r.denominator();
    return os;
}

int main()
{
    Rational r1(1, 2);
    int n = 1;
    Rational r2 = r1 + n, r3 = n + r1, r4 = r1 + r1;
    std::cout << r2 << ' ' << r3 << ' ' << r4 << '\n';
    return 0;
}