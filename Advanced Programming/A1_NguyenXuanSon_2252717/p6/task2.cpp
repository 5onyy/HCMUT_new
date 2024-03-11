#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159265359;

double squareArea(double side) {
    return side * side;
}

double rectangleArea(double length, double width) {
    return length * width;
}

double circleArea(double radius) {
    return PI * radius * radius;
}

double triangleArea(double base, double height) {
    return 0.5 * base * height;
}

int main() {
    int choice;
    
    while (true) {
        cout << "Choose the shape to calculate the area:" << endl;
        cout << "1. Square" << endl;
        cout << "2. Rectangle" << endl;
        cout << "3. Circle" << endl;
        cout << "4. Triangle" << endl;
        cout << "Enter your choice (1-4), or -1 to exit: ";
        cin >> choice;

        if (choice == -1) {
            cout << "Exiting the program..." << endl;
            break;
        }

        double area = 0.0;
        double param1, param2;

        switch (choice) {
            case 1:
                cout << "Enter the side length of the square: ";
                cin >> param1;
                area = squareArea(param1);
                break;
            case 2:
                cout << "Enter the length and width of the rectangle: ";
                cin >> param1 >> param2;
                area = rectangleArea(param1, param2);
                break;
            case 3:
                cout << "Enter the radius of the circle: ";
                cin >> param1;
                area = circleArea(param1);
                break;
            case 4:
                cout << "Enter the base and height of the triangle: ";
                cin >> param1 >> param2;
                area = triangleArea(param1, param2);
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
                continue;
        }

        cout << "Area: " << area << endl;
    }

    return 0;
}
