#include "fraction.h"

void Fraction::reduce()
    {
        
        int a = abs(_n);
        int b = abs(_d);
        
        while(a * b != 0)
        {
            if(a > b)
                a = a - b;
            else
                b = b - a;
            
        }
        _n = _n / (gcd(a, b));
        _d = _d / (gcd(a, b));
        
        if(_d < 0)
        {
            _d = _d * -1;
            _n = _n * -1;
        }
        
    }
 
Fraction Fraction::operator~()
{
 
    Fraction inv;
    inv._n = _d;
    inv._d = _n;
    if(inv._d < 0)
    {
        inv._d=-inv._d;
        inv._n=-inv._n;
    }
    return inv;
}
 
 
Fraction Fraction::operator+(const Fraction &rhs)
{
  Fraction op;
  op._n = _n * rhs._d + rhs._n * _d;
  op._d = _d * rhs._d;
  op.reduce();
  return op;
}

Fraction Fraction::operator-(const Fraction &rhs)
{
   Fraction op;
   op._n = _n * rhs._d - rhs._n * _d;
   op._d = _d * rhs._d;
   op.reduce();
   return op;
   
}
 
 
Fraction Fraction::operator*(const Fraction &rhs)
{
   Fraction op;
   op._n = _n * rhs._n;
   op._d = _d * rhs._d;
   op.reduce();
   return op;
   
}
 
 
Fraction Fraction::operator/(const Fraction &rhs)
{
   Fraction op;
   op._n = _n * rhs._d;
   op._d = _d * rhs._n;
   op.reduce();
   return op;
   
}
 
bool Fraction::operator!=(const Fraction &rhs) const
{
  return !(_n == rhs._n && _d == rhs._d);
}
 
bool Fraction::operator==(const Fraction &rhs) const
{
  return _n == rhs._n && _d == rhs._d;
}
 
 
bool Fraction::operator<(const Fraction &rhs) const
{
  return(_n * rhs._d < rhs._n * _d);
}
 
bool Fraction::operator>(const Fraction &rhs) const
{
  return(_n * rhs._d > rhs._n * _d);
}
 
bool Fraction::operator<=(const Fraction &rhs) const
{
  return(_n * rhs._d <= rhs._n * _d);
}
 
bool Fraction::operator>=(const Fraction &rhs) const
{
  return(_n * rhs._d >= rhs._n * _d);
}
 
std::istream &operator>>(std::istream &ist, Fraction &rhs)
 {
    return ist >> rhs._n >> rhs.e >> rhs._d;
     
 }
 
 std::ostream &operator<<(std::ostream &ost, const Fraction &rhs)
 {
     
    return ost << rhs._n << "/" << rhs._d;
 }
