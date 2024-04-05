#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double number;

    cout << "Enter a number: ";
    cin >> number;

    cout << "\nCalculations for " << number << ":" << endl;
    cout << "===========================" << endl;
    cout << "Absolute value: " << abs(number) << endl;
    cout << "Sine: " << sin(number) << endl;
    cout << "Cosine: " << cos(number) << endl;
    cout << "Tangent: " << tan(number) << endl;
    cout << "Natural logarithm: " << log(number) << endl;
    cout << "Base-10 logarithm: " << log10(number) << endl;
    cout << "Square root: " << sqrt(number) << endl;
    cout << "Exponential: " << exp(number) << endl;

    return 0;
}
