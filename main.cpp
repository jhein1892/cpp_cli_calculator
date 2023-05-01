#include <iostream>
#include <string.h>

int main(){
    std::string equation;
    std::cout << "Please Enter an equation: " <<std::endl;
    std::getline(std::cin, equation);

    std::cout << "The equation you entered is: " << equation << std::endl;

    return 0;
}