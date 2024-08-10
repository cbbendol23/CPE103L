#include <iostream>

using namespace std;

class rectangleType {
protected:
    double length;
    double width;

public:
    // Constructors
    rectangleType(double l = 1, double w = 1) : length(l), width(w) {
        if (l <= 0) length = 1;
        if (w <= 0) width = 1;
    }

    // friend functions
    friend rectangleType& operator++(rectangleType& rect);
    friend rectangleType operator++(rectangleType& rect, int);
    friend rectangleType& operator--(rectangleType& rect);
    friend rectangleType operator--(rectangleType& rect, int);
    friend rectangleType operator-(const rectangleType& rect1, const rectangleType& rect2);
    friend bool operator==(const rectangleType& rect1, const rectangleType& rect2);
    friend bool operator!=(const rectangleType& rect1, const rectangleType& rect2);
    friend bool operator<(const rectangleType& rect1, const rectangleType& rect2);
    friend bool operator>(const rectangleType& rect1, const rectangleType& rect2);
    friend bool operator<=(const rectangleType& rect1, const rectangleType& rect2);
    friend bool operator>=(const rectangleType& rect1, const rectangleType& rect2);

    void display() const {
        cout << "Length: " << length << ", Width: " << width << endl;
    }

    // ask user to input for the length and weidth
    bool input() {
        cout << "Enter length: ";
        cin >> length;
        if (length <= 0) {
            cout << "Length must be positive...\n";
            return false;
        }

        cout << "Enter width: ";
        cin >> width;
        if (width <= 0) {
            cout << "Width must be positive...\n";
            return false;
        }

        return true;
    }
};

// pre increment 
rectangleType& operator++(rectangleType& rect) {
    ++rect.length;
    ++rect.width;
    return rect;
}

// post increment
rectangleType operator++(rectangleType& rect, int) {
    rectangleType temp = rect;
    ++rect;
    return temp;
}

// pre decrement
rectangleType& operator--(rectangleType& rect) {
    if (rect.length > 1) --rect.length;
    if (rect.width > 1) --rect.width;
    return rect;
}

// post decrement 
rectangleType operator--(rectangleType& rect, int) {
    rectangleType temp = rect;
    --rect;
    return temp;
}

rectangleType operator-(const rectangleType& rect1, const rectangleType& rect2) {
    double newLength = rect1.length - rect2.length;
    double newWidth = rect1.width - rect2.width;

    if (newLength <= 0 || newWidth <= 0) {
        cout << "Resulting dimensions must be positive.\n";
        return rect1;
    }

    return rectangleType(newLength, newWidth);
}

// comparison operator
bool operator==(const rectangleType& rect1, const rectangleType& rect2) {
    return (rect1.length * rect1.width) == (rect2.length * rect2.width);
}

bool operator!=(const rectangleType& rect1, const rectangleType& rect2) {
    return !(rect1 == rect2);
}

bool operator<(const rectangleType& rect1, const rectangleType& rect2) {
    return (rect1.length * rect1.width) < (rect2.length * rect2.width);
}

bool operator>(const rectangleType& rect1, const rectangleType& rect2) {
    return (rect1.length * rect1.width) > (rect2.length * rect2.width);
}

bool operator<=(const rectangleType& rect1, const rectangleType& rect2) {
    return (rect1.length * rect1.width) <= (rect2.length * rect2.width);
}

bool operator>=(const rectangleType& rect1, const rectangleType& rect2) {
    return (rect1.length * rect1.width) >= (rect2.length * rect2.width);
}

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

