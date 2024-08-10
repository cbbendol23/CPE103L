#include <iostream>

using namespace std;

// arrays for sign operations
char signs[5] = {'+', '-', '*', '/', '%'};

/* class used is named calculator and it contains the 
class members that calculates each operations */
class Calculator 
{
    private:
        double firstNum;
        double secondNum;
        
    public:
        Calculator(double x, double y): firstNum(x), secondNum(y){}
    
        // for addition
        double addition()
        {
            return firstNum + secondNum;
        }
        
        // for subtraction
        double subtraction()
        {
            return firstNum - secondNum;
        }
        
        // for multiplication
        double multiplication()
        {
            return firstNum * secondNum;
        }
        
        // for multiplication
        double division()
        {
            return firstNum / secondNum;
        }
        
};

int main()
{
    double firstNum;
    double secondNum;
    double percent;
    char operation;
    
    while (true)
    {   
        cout << "Input first number: ";
        cin >> firstNum;
        
        cout << "Input second number: ";
        cin >> secondNum;
        
        Calculator calculator(firstNum, secondNum);
    
     
        cout << "Choose Operation (+ , -, *, /, %, press X to quit): " << endl;
        cin >> operation;
        
        if (operation == 'X' || operation == 'x')
        {
            cout << "Terminating the program";
            exit(0);
        }
        if (operation == '+')
        {
            double sum = calculator.addition();
            cout << "Sum = " << sum << endl;

        }
        
        else if (operation == '-')
        {
            double difference = calculator.subtraction();
            cout << "Difference = " << difference << endl;
  
        }
        
        else if (operation == '*')
        {
            double product = calculator.multiplication();
            cout << "Product = " << product << endl;
          
        }
        
        else if (operation == '/')
        {
            double quotient = calculator.division();
            if (secondNum == 0)
            {
                cout << "Cannot Divide by ZERO." << endl;
                exit(0);
            }
            cout << "Quotient = " << quotient << endl;
            
        }
        
        // for getting the percentage
        else if (operation == '%')
        {
            cout << "How many percent (0 to 100)? " << endl;
            cin >> percent;
            
            cout << "Percentage of first number = " << firstNum * (percent/100) << endl;
            cout << "Percentage of second number = " << secondNum * (percent/100) << endl;
          
        }
        else
        {
            cout << "Invalid Key, Try again." << endl;
        }
        
    }
    
    return 0;
}