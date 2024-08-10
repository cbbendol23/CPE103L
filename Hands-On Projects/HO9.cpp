/*

Using an operator and a friend function create 
a program “Counter”, declare your object as 
private, output should display the following:

a. Incrementing counter.

b. Addition of 2 counter

c. Multiplication of 2 counter

d. Setting the 3rd counter to 0

*/

#include <iostream>

using namespace std;

class Counter {
private:
    int count;

public:
    Counter() : count(0) {} 
    
    Counter& operator++() {
        ++count;
        return *this;
    }

    // Addition of counter1 and counter 2
    friend Counter operator+(const Counter& c1, const Counter& c2) {
        Counter result;
        result.count = c1.count + c2.count;
        return result;
    }

    // Multiplication of counter 1 and counter2
    friend Counter operator*(const Counter& c1, const Counter& c2) {
        Counter result;
        result.count = c1.count * c2.count;
        return result;
    }

    // Setting the 3rd counter to zero
    void reset() {
        count = 0;
    }

    // Friend function
    friend ostream& operator<<(ostream& os, const Counter& counter) {
        os << "Current Value: " << counter.count;
        return os;
    }

    void setCount(int value) {
        count = value;
    }
};

int main() {
    Counter counter1, counter2, counter3;

    int num1, num2, num3;

    // ask fo first number
    cout << "Enter the first number: ";
    cin >> num1;
    counter1.setCount(num1);

    // ask fo second number
    cout << "Enter the second number: ";
    cin >> num2;
    counter2.setCount(num2);

    // ask for third number
    cout << "Enter the third number: ";
    cin >> num3;
    counter3.setCount(num3);


    ++counter1;
    cout << "\n";
    cout << "a. Incrementing counter1: " << counter1 << endl;

    counter3 = counter1 + counter2;
    cout << "b. Addition of counter1 and counter2: " << counter3 << endl;

    counter3 = counter1 * counter2;
    cout << "c. Multiplication of counter1 and counter2: " << counter3 << endl;

    counter3.reset();
    cout << "d. Setting counter3 to 0: " << counter3 << endl;

    return 0;
}
