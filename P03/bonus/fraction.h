#ifndef __FRACTION_H
#define __FRACTION_H
#include <iostream>
#include <cmath>
#include <map>

class Fraction
{
private:
    int _n;
    char e;
    int _d;
    int gcd(int a, int b)
         {
             return b == 0 ? a : gcd(b, a % b);
             
         }
 
public:
    
    Fraction(int num = 0, int den = 1):_n(num),_d(den) {}
    void reduce();
    friend std::istream &operator>>(std::istream &ist,Fraction &rhs);
    friend std::ostream &operator<<(std::ostream &ost,const Fraction &rhs);
    Fraction operator+(const Fraction &rhs);
    Fraction operator-(const Fraction &rhs);
    Fraction operator*(const Fraction &rhs);
    Fraction operator/(const Fraction &rhs);
    Fraction operator~();
    bool operator!=(const Fraction &rhs) const;
    bool operator==(const Fraction &rhs) const;
    bool operator<(const Fraction &rhs) const;
    bool operator<=(const Fraction &rhs) const;
    bool operator>(const Fraction &rhs) const;
    bool operator>=(const Fraction &rhs) const;
 
};

#endif
