#include <cmath>

class Complex
{
public:
    Complex(double re, double img = 0.0) : re(re), img(img)
    {}

    double Re() const
    {
        return re;
    }

    double Im() const
    {
        return img;
    }

    Complex operator+(Complex cn) const
    {
        return Complex(this->re + cn.re, this->img + cn.img);
    }

    Complex operator+(double val) const
    {
        return Complex(this->re + val, this->img);
    }

    Complex operator-(const Complex& cn) const
    {
        return Complex(this->re - cn.re, this->img - cn.img);
    }

    Complex operator-(const double& val) const
    {
        return Complex(this->re - val, this->img);
    }

    Complex operator*(const Complex& cn) const
    {
        return Complex(this->re * cn.re - this->img * cn.img, this->re * cn.img + this->img * cn.re);
    }

    Complex operator*(const double& val) const
    {
        return Complex(this->re * val, this->img * val);
    }

    Complex operator/(const Complex& cn) const
    {
        return Complex(((this->re * cn.re) + (this->img * cn.img)) / ((cn.re * cn.re) + (cn.img * cn.img)), ((this->img * cn.re) - (this->re * cn.img)) / ((cn.re * cn.re) + (cn.img * cn.img)));
    }

    Complex operator/(const double& val) const
    {
        return Complex(this->re / val, this->img / val);
    }

    Complex operator-() const
    {
        return Complex(-this->re, -this->img);
    }

    Complex operator+() const
    {
        return Complex(this->re, this->img);
    }

    bool operator==(const Complex& cn) const
    {
        return this->re == cn.re && this->img == cn.img;
    }

    bool operator!=(const Complex& cn) const
    {
        return this->re != cn.re || this->img != cn.img;
    }

private:
    double re, img;
};

Complex operator+(double val, Complex& cn)
{
    return Complex(val + cn.Re(), cn.Im());
}

Complex operator-(double val, Complex& cn)
{
    return Complex(val - cn.Re(), -cn.Im());
}

Complex operator*(double val, Complex& cn)
{
    return Complex(val * cn.Re(), val * cn.Im());
}

Complex operator/(double val, Complex& cn)
{
    return Complex((val * cn.Re()) / (cn.Re() * cn.Re() + cn.Im() * cn.Im()), (-val * cn.Im()) / (cn.Re() * cn.Re() + cn.Im() * cn.Im()));
}

double abs(Complex& cn)
{
    return std::sqrt(cn.Re() * cn.Re() + cn.Im() * cn.Im());
}