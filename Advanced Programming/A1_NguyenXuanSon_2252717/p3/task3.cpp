#include <iostream>

using namespace std;

int main() {
    double num1, num2;
    char op;
    double result;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Enter the operator (+, -, *, /): ";
    cin >> op;

    switch(op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                cout << "Error: Division by zero!" << endl;
                return 1;
            }
            break;
        default:
            cout << "Invalid operator! Please enter +, -, *, or /." << endl;
            return 1;
    }

    cout << "\nResult:" << endl;
    cout << "=======" << endl;
    cout << num1 << " " << op << " " << num2 << " = " << result << endl;

    return 0;
}
