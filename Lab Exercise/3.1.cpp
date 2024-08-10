#include <iostream>

using namespace std;

class rectangleType {
protected:
    double length;
    double width;

public:
    // Constructors
    rectangleType(double l = 1, double w = 1) : length(l), width(w) {
    }

    // pre increment
    rectangleType& operator++() {
        ++length;
        ++width;
        return *this;
    }

    // post increment 
    rectangleType operator++(int) {
        rectangleType temp = *this;
        ++(*this);
        return temp;
    }

    // pre decrement 
    rectangleType& operator--() {
        if (length > 1) --length;
        if (width > 1) --width;
        return *this;
    }

    // post decrement 
    rectangleType operator--(int) {
        rectangleType temp = *this;
        --(*this);
        return temp;
    }

    // binary operator
    rectangleType operator-(const rectangleType& other) {
        double newLength = length - other.length;
        double newWidth = width - other.width;

        if (newLength <= 0 || newWidth <= 0) {
            cout << "Length and Width must be positive.\n";
            return *this;
        }

        return rectangleType(newLength, newWidth);
    }
    
    // compare each the rectangle length and width, area

    bool operator==(const rectangleType& other) const {
        return (length * width) == (other.length * other.width);
    }

    bool operator!=(const rectangleType& other) const {
        return !(*this == other);
    }

    bool operator<(const rectangleType& other) const {
        return (length * width) < (other.length * other.width);
    }

    bool operator>(const rectangleType& other) const {
        return (length * width) > (other.length * other.width);
    }

    bool operator<=(const rectangleType& other) const {
        return (length * width) <= (other.length * other.width);
    }

    bool operator>=(const rectangleType& other) const {
        return (length * width) >= (other.length * other.width);
    }

    // Function to display the dimensions of the rectangle
    void display() const {
        cout << "Length: " << length << ", Width: " << width << endl;
    }

    // Ask user for input of length and width
    bool input() {
        cout << "Enter length: ";
        cin >> length;
        if (length <= 0) {
            cout << "Length must be positive....\n";
            return false;
        }

        cout << "Enter width: ";
        cin >> width;
        if (width <= 0) {
            cout << "Length must be positive...\n";
            return false;
        }

        return true;
    }
};

int main() {
    rectangleType rect1, rect2;

    cout << "Enter the length and width for the first rectangle: " << endl;
    if (!rect1.input()) return 1;

    cout << "Enter the length and width for the second rectangle: " << endl;
    if (!rect2.input()) return 1;

    cout << "\n";
    
    cout << "Initial rectangles: " << endl;;
    
    // call the display function of rectangle object
    rect1.display();
    rect2.display();


    // test code
    cout << "\nTesting increment operators:\n";
    ++rect1;
    rect2++;
    rect1.display();
    rect2.display();

    cout << "\n";
    
    cout << "Testing decrement operators: " << endl;
    --rect1;
    rect2--;
    rect1.display();
    rect2.display();
    
    cout << "\n";
    
    cout << "Testing subtraction operator: " << endl;
    rectangleType rect3 = rect1 - rect2;
    rect3.display();

    cout << "\n";
    
    cout << "Testing relational operators: " << endl;
    
    cout << "\n";
    
    cout << "Rectangle 1 is equal to Rectangle 2: " << (rect1 == rect2 ? "True" : "False") << endl;
    cout << "Rectangle 1 is NOT equal to Rectangle 2: " << (rect1 != rect2 ? "True" : "False") << endl;
    cout << "Rectangle 1 is less than Rectangle 2: " << (rect1 < rect2 ? "True" : "False") << endl;
    cout << "Rectangle 1 is greater than Rectangle 2: " << (rect1 > rect2 ? "True" : "False") << endl;
    cout << "Rectangle 1 is less than or equal to Rectangle 2: " << (rect1 <= rect2 ? "True" : "False") << endl;
    cout << "Rectangle 1 is greater than or equal to Rectangle 2: " << (rect1 >= rect2 ? "True" : "False") << endl;

    return 0;
}
