#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double calculate_cylinder_volume(double radius, double height) {
    const double pi = 3.14159265358979323846; // Define the value of pi
    double volume = pi * pow(radius, 2) * height; // Calculate the volume
    return volume;
}

int main() {
    double radius, height;

    cout << "Enter the radius of the cylinder: ";
    cin >> radius;

    cout << "Enter the height of the cylinder: ";
    cin >> height;

    double volume = calculate_cylinder_volume(radius, height);

    cout << "\nCylinder Information:" << endl;
    cout << "====================" << endl;
    cout << fixed << setprecision(2);
    cout << "Radius: " << radius << " units" << endl;
    cout << "Height: " << height << " units" << endl;
    cout << "Volume: " << volume << " cubic units" << endl;

    return 0;
}
