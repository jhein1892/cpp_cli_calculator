#include <iostream>
#include <string>
#include <cmath>

int main(){
    std::string equation;
    std::cout << "Please Enter an equation: " <<std::endl;
    std::getline(std::cin, equation);

    // Assess the equation
        // Call proper function and do arithmatic on values. 
    float num1 = 0.0f, num2 = 0.0f;
    char equation_type;
    for(int i = 0; i < equation.size(); i++){
        std::cout << equation[i] << std::endl;
        if(equation[i] == ' '){
            continue;
        }

        if (equation[i] == '+'){
            equation_type = 'a';
            std::cout << "Addition" << std::endl;
            continue;
        }
        else if (equation[i] == '-'){
            std::cout << "Subtraction" << std::endl;
            equation_type = 's';
            continue;
        }
        else if (equation[i] == '*'){
            std::cout << "Multiplication" << std::endl;
            equation_type = 'm';
            continue;
        }
        else if (equation[i] == '/'){
            std::cout << "Division" << std::endl;
            equation_type = 'd';
            continue;
        }

        if(num1 == 0.0f){
            std::cout << "Num 1: " << equation[i] << std::endl;
        } else {
            std::cout << "Num 2: " << equation[i] << std::endl;
        }
    }
    float result;
    switch(equation_type){
        case('a'):
            std::cout << num1 << " " << num2 << std::endl;
            result = num1 + num2;
            break;
        case('s'):
            result = num1 - num2;
            break;
        case('m'):
            result = num1 * num2;
            break;
        case('d'):
            result = num1 / num2;
            break;
        default: 
            break;
    }

    std::cout << "The result is: " << result << std::endl;


    return 0;
}