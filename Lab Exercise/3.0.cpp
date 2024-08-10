#include <iostream>
#include <cmath>

using namespace std;

class cylinderType
{
private:
    double radius;
    double height;

public:
    cylinderType(double r, double h): radius(r), height(h) {}

    // Amount of liquid in the container
    double calculateVolume()
    {
        return height * pow(radius, 2) * M_PI;
    }

    double calculateSurfaceArea()
    {
        return (2 * M_PI * radius * height) + (2 * M_PI * pow(radius, 2));
    }
};
int main()
{
    double radius;
    double height;
    double volume;
    double surfaceArea;
    double shippingCost;
    double paintCost;
    double totalShippingCost;
    double totalPaintCost;

    cout << "Enter the radius of cylinder: ";
    cin >> radius;

    cout << "Enter the height of cylinder: ";
    cin >> height;

    cylinderType container(radius, height);

    cout << "Enter the shipping cost per liter: ";
    cin >> shippingCost;

    cout << "Enter the paint cost per square foot: ";
    cin >> paintCost;

    // Calculate the shipping cost. 28.3168466 is the conversion from cubic foot to liter.
    volume = container.calculateVolume() * 28.3168466;
    totalShippingCost = volume * shippingCost;

    // Calculate the paint cost.
    surfaceArea = container.calculateSurfaceArea();
    totalPaintCost = surfaceArea * paintCost;

    cout << "The shipping cost per liter is: " << totalShippingCost << " Pesos"<< endl;
    cout << "The paint cost per square foot is: " << totalPaintCost << " Pesos";
    return 0;
}
