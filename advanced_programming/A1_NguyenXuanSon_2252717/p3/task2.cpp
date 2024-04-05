#include <iostream>

using namespace std;

int main() {
    double vnd_amount;
    int choice;
    double conversion_rate;
    double converted_amount;

    cout << "Enter the amount of money in VND: ";
    cin >> vnd_amount;

    cout << "Choose the currency conversion:" << endl;
    cout << "1. Convert to AUD" << endl;
    cout << "2. Convert to USD" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        conversion_rate = 0.000057;  
        converted_amount = vnd_amount * conversion_rate;
        cout << "\nConversion Information:" << endl;
        cout << "========================" << endl;
        cout << "VND Amount: " << vnd_amount << " VND" << endl;
        cout << "Converted Amount: " << converted_amount << " AUD" << endl;
    } else if (choice == 2) {
        conversion_rate = 0.000043; 
        converted_amount = vnd_amount * conversion_rate;
        cout << "\nConversion Information:" << endl;
        cout << "========================" << endl;
        cout << "VND Amount: " << vnd_amount << " VND" << endl;
        cout << "Converted Amount: " << converted_amount << " USD" << endl;
    } else {
        cout << "Invalid choice. Please choose 1 or 2." << endl;
    }

    return 0;
}
