#include <iostream>
#include <string>
#include <cmath>

int main(){
    using namespace std; 

    string equation;
    cout << "Please Enter an equation: " <<endl;
    getline(cin, equation);

    // Assess the equation
        // Call proper function and do arithmatic on values. 
    string num1 = "", num2 = "";
    bool firstNum = true;
    char equation_type;
    for(int i = 0; i < equation.size(); i++){
        if(equation[i] == ' '){
            firstNum = false;
            continue;
        }
        switch(equation[i]){
            case('+'):
                equation_type = 'a';
                firstNum = false;
                break;
            case('-'):
                equation_type = 's';
                firstNum = false;
                break;
            case('*'):
                equation_type = 'm';
                firstNum = false;
                break;
            case('/'):
                equation_type = 'd';
                firstNum = false;
                break;
            default:
                if(firstNum){
                    num1 += equation[i];
                } else {
                    num2 += equation[i];
                }
        }
    }
    double result;
    switch(equation_type){
        case('a'):
            cout << num1 << " " << num2 << endl;
            result = stod(num1) + stod(num2);
            break;
        case('s'):
            result = stod(num1) - stod(num2);
            break;
        case('m'):
            result = stod(num1) * stod(num2);
            break;
        case('d'):
            result = stod(num1) / stod(num2);
            break;
        default: 
            break;
    }

    cout << "The result is: " << result << endl;


    return 0;
}