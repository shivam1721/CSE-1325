#include "fraction.h"

int main()
{
    
    
    Fraction x, a, b;
        
    std::cout << "Enter the fractions in the form of a/b " << std::endl;
       
    std::cout << "Enter a fraction for A: ";
    std::cin >> a;
 
    std::cout << "Enter a fraction for B: ";
    std::cin  >> b;
        
    std::cout << "Inverse of A: " << ~a << std::endl;
    std::cout << "Inverse of B: " << ~b << std::endl;
        
    x = a + b;
    std::cout << "Addition = " << a << " + " << b << " : "<< x << std::endl;
    x = a - b;
    std::cout << "Subtraction = " << a << " - " << b << " : "<< x << std::endl;
    x = a * b;
    std::cout << "Multiplication = " << a << " * " << b << " : "<< x << std::endl;
    x = a / b;
    std::cout << "Division = " << a << " / " << b << " : "<< x << std::endl;
    
    if(a == b)
    {
        std::cout << "The fractions are equal: ";
        std::cout << b <<std::endl;
    }
    if(a > b)
    {
        std::cout << "A is greater then B: ";
        std::cout << a << " > " << b <<std::endl;
    }
    if(a < b)
    {
        std::cout << "A is less then B: ";
        std::cout << a << " < " << b <<std::endl;
    }
    if(a >= b)
    {
        std::cout << "A is greater then or equal to B: ";
        std::cout << a << " >= " << b <<std::endl;
    }
    return 0;
}
