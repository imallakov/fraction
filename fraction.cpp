// fraction.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class fraction
{
private:
    int num, den;
public:
    fraction(int a = 1, int b = 1)
    {
        try
        {
            if (b == 0)
            {
                num = 0;
                den = 1;
                throw "Error! Denominator can't be equal to zero!";
            }
            else
            {
                num = a;
                den = b;
                reduce();
            }
        }
        catch (const char* str)
        {
            std::cout << str << std::endl;
        }
        /*catch (...)
        {
            std::cout << "Error!" << std::endl;
        }*/
    }
    void show() const
    {
        std::cout << num << "/" << den << std::endl;
    }
    void reduce()
    {
        int a = abs(num);
        int b = abs(den);

        while (a != 0 && b != 0)
        {
            if (a > b)
            {
                a %= b;
            }
            else
            {
                b %= a;
            }
        }
        a += b;
        num /= a;
        den /= a;
        if (den < 0)
        {
            num = -num;
            den = -den;
        }
    }
    int getnum() const
    {
        return num;
    }
    int getden() const
    {
        return den;
    }
    fraction operator+ (const fraction& A) const
    {
        fraction B;
        if (den != A.den)
        {
            B.num = num * A.den;
            int k = A.num * den;
            int m = A.den * den;
            B.den = m;
            B.num += k;
        }
        else
        {
            B.num += A.num;
        }
        B.reduce();
        return B;
    }
    fraction operator- (const fraction& A) const
    {
        fraction B;
        if (den != A.den)
        {
            B.num= num * A.den;
            int k = A.num * den;
            int m = A.den * den;
            B.den = m;
            B.num -= k;
        }
        else
        {
            B.num -= A.num;
        }
        B.reduce();
        return B;
    }
    fraction operator* (const fraction& A) const
    {
        fraction B(num * A.num, den * A.den);
        B.reduce();
        return *this;
    }
    fraction operator/ (const fraction& A) const
    {
        fraction B(num * A.den, den * A.num);
        B.reduce();
        return B;
    }
    fraction operator- ()
    {
        fraction B(-num, den);
        return B;
    }
    fraction& operator+=(const fraction& A) {
        if (den != A.den)
        {
            num = num * A.den;
            int k = A.num * den;
            int m = A.den * den;
            den = m;
            num += k;
        }
        else
        {
            num += A.num;
        }
        reduce();
        return *this;
    }
    fraction& operator-=(const fraction& A) {
        if (den != A.den)
        {
            num = num * A.den;
            int k = A.num * den;
            int m = A.den * den;
            den = m;
            num -= k;
        }
        else
        {
            num -= A.num;
        }
        reduce();
        return *this;
    }
    fraction& operator*=(const fraction& A) {
        num *= A.num;
        den *= A.den;
        reduce();
        return *this;
    }
    fraction& operator/=(const fraction& A) {
        num *= A.den;
        den *= A.num;
        reduce();
        return *this;
    }
};

std::ostream& operator<<(std::ostream& out, const fraction& X) {
    out << X.getnum();
    if(X.getden()!=1) std::cout<< "/" << X.getden();
    return out;
}

int main()
{
    fraction A(5, 0);
    std::cout << A << std::endl;
}