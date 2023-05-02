#include <iostream>
#include <string>
#include <cmath>

class Equation {

    public:
        Equation(std::string input_equation): result(stod(parseEquation(input_equation))){} 

        void printResult(){
            std::cout << "Your result: " << result << std::endl;
        }

    private:
        double result;

        std::string parseEquation(std::string equation){
            bool firstNum = true;
            int openCount = 0;
            std::string lhNum = "";
            std::string rhNum = "";
            std::string subEquation = "";
            char eq_type;

            for(int i = 0; i < equation.size(); i++){
                if(equation[i] == ' '){
                    firstNum = false;
                    continue;
                }
                if(equation[i] == '('){
                    openCount++;
                    if(subEquation != ""){
                        subEquation += equation[i];
                    }
                    continue;
                }
                if(equation[i] == ')'){
                    openCount--;
                }
                if(openCount > 0){
                    subEquation += equation[i];
                    continue;
                }
                if(subEquation != "" && openCount == 0){
                    if(firstNum){
                        lhNum = parseEquation(subEquation);
                    } else {
                        rhNum = parseEquation(subEquation);
                    }
                    continue;
                }

                switch(equation[i]){
                    case('+'):
                        eq_type = 'a';
                        firstNum = false;
                        break;
                    case('-'):
                        eq_type = 's';
                        firstNum = false;
                        break;
                    case('*'):
                        eq_type = 'm';
                        firstNum = false;
                        break;
                    case('/'):
                        eq_type = 'd';
                        firstNum = false;
                        break;
                    default:
                        if(firstNum){
                            lhNum += equation[i];
                        } else {
                            rhNum += equation[i];
                        }
                }
            }
            return std::to_string(findResult(lhNum, rhNum, eq_type));
        }

        double findResult(std::string lh, std::string rh, char eq_type){
            double local_result;
            try{
                switch(eq_type){
                    case('a'):
                        local_result = stod(lh) + stod(rh);
                        break;
                    case('s'):
                        local_result = stod(lh) - stod(rh);
                        break;
                    case('m'):
                        local_result = stod(lh) * stod(rh);
                        break;
                    case('d'):
                        local_result = stod(lh) / stod(rh);
                        break;
                    default: 
                        break;
                }
            } catch(std::exception) {
                std::cout << "Sorry, this equation is not valid" << std::endl;
            }

            return local_result;
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