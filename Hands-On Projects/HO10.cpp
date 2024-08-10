/* Create a program that will convert the non-negative
value of your height (feet and inches) to centimeters.
Use the exception handling function to input only the
non-negative number, if the user inputted a negative
number, the program should ask again a non-negative
number for both feet and inches.
*/

#include <iostream>
#include <limits>

using namespace std;

// function prototype
double convertToCentimeters(int feet, int inches);
int promptNonNegativeInput(const string& message);

int main() {
    try 
    {
        // ask user for the height (feet and inches)
        int feet = promptNonNegativeInput("Please enter your height in feet: ");
        int inches = promptNonNegativeInput("Please enter your height in inches: ");
        double heightInCm = convertToCentimeters(feet, inches);
        
        cout << "Your height in centimeters is: " << heightInCm << " cm." << endl;
    } 
    catch (const exception& ex) 
    {
        cerr << "Error: " << ex.what() << endl;
    }

    return 0;
}

// function for conversion
double convertToCentimeters(int feet, int inches) {
    const double CM_PER_INCH = 2.54;
    const int INCHES_PER_FOOT = 12;
    int totalInches = feet * INCHES_PER_FOOT + inches;
    return totalInches * CM_PER_INCH;
}

// if input is non-negative
int promptNonNegativeInput(const string& message) {
    int value;
    while (true) {
        cout << message;
        cin >> value;
        if (cin.fail() || value < 0) 
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a non-negative number." << endl;
        } 
        else 
        {
            break;
        }
    }
    return value;
}
