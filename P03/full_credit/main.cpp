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
        
   return 0;
}

