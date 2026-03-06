#include "header.hpp"

class Complex
{
private:
    double real = 0;
    double img = 0;
public:
    Complex(double r, double i)
    {
        this->real = r;
        this->img = i;
    }
    double _getReal()
    {
        return this->real;
    }
    void _setReal(double num)
    {
        this->real = num;
    }
    double _getImg()
    {
        return this->img;
    }
    void _setImg(double num)
    {
        this->img = num;
    }
    static Complex read(std::istream& inputStream)
    {
        char sign;
        double r = 0;
        double i = 0;
        inputStream >> r >> sign >> i;
        if (sign == '-')
        {
            i = -i;
        } 
        return Complex(r,i);
    }
    void print(std::ostream& outputStream)
    {
        char c;
        if(this->_getImg() < 0)
        {
            c = '+';
        }
        else
        {
            c = '-';
        }
        outputStream << this->_getReal() << c << this->_getImg() << std::endl;
    }
    Complex add(Complex n1, Complex n2)
    {
        return Complex(n1.real + n2.real, n1.img + n2.img);
    }
    Complex operator-(const Complex &other) const
    {
        Complex temp(this->real, this->img);
        return temp - other;
        //friend std::ostream &operator<<(std::ostream &os, const Complex &c);
    }
};

int main(void)
{

}
