#include <iostream>
#include <string>
#include <cmath>

class Equation {

    public:
        Equation(std::string input_equation): equation(input_equation), num1(""), num2("") {
            this->parseEquation();
        } 

        void printValue(){
            std::cout << "Your equation is: " << equation << std::endl;
        }

        void printResult(){
            this->findResult();
            std::cout << "Your result: " << result << std::endl;
        }

        void printEquationDetails(){
            std::cout << "Num1: " << num1 << " Num2: " << num2 << " Type: " << equation_type << std::endl;
        }

    private:
        std::string equation;
        double result;
        std::string num1, num2; 
        char equation_type;

        void parseEquation(){
            bool firstNum = true;
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
        }

        void findResult(){
            try{
                switch(equation_type){
                    case('a'):
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
            } catch(std::exception) {
                std::cout << "Sorry, this equation is not valid" << std::endl;
            }
        }
};

int main(){
    using namespace std; 

    string equation;
    bool getEquation = true;
    while(getEquation){
        cout << "Please Enter an equation: " <<endl;
        getline(cin, equation);

        if(equation == "q") {
            getEquation = false;
            continue;
        } else {
            Equation user_equation(equation);
            user_equation.printResult();
        }
    }

    cout << "Thank you for using my Calculator!" << endl;

    return 0;
}