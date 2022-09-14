#include <iostream>
int main(){
std::string name;
std::cout << "Enter your name: ";
std::getline(std::cin,name);
std::cout << "Hello " << name << " \U0001F604" << std::endl;
return 0;
}
