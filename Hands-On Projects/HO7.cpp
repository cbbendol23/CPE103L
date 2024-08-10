/*
Write a C++ program to create a class called Triangle 
that has private member variables for the lengths of 
its three sides. Implement member functions to determine 
if the triangle is equilateral, isosceles, or scalene.
*/

#include <iostream>
#include <cmath>

using namespace std;

class Triangle {
	private:
		double lengthOne;
		double lengthTwo;
		double lengthThree;
		
	public:
		Triangle(double one, double two, double three): lengthOne(one), lengthTwo(two), lengthThree(three) {}
			
	    double typeIdentifier(){
	        if (lengthOne == lengthTwo && lengthOne == lengthThree && lengthTwo == lengthThree)
			    cout << "The triangle is an EQUILATERAL TRIANGLE";
			
			else if (lengthOne == lengthTwo || lengthOne == lengthThree || lengthTwo == lengthThree)
			    cout << "The triangle is an ISOSCELES TRIANGLE";
			    
			else
			    cout << "The triangle is an SCALENE TRIANGLE";
			 
			return 0;
	    }
};

int main (){
	double lengthOne;
	double lengthTwo;
	double lengthThree;
	
	cout << "Input first length: ";
	cin >> lengthOne;
	
	
	cout << "Input second length: ";
	cin >> lengthTwo;
	
	cout << "Input third length: ";
	cin >> lengthThree;
	
	Triangle triangle(lengthOne, lengthTwo, lengthThree);

	triangle.typeIdentifier();
	
	return 0;
}