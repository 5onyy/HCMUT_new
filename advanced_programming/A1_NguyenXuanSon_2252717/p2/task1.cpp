#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double usd_input;
    
    cout << "Enter the amount in USD: ";
    cin >> usd_input;
    
    double vnd_output = usd_input * 24.707;
    
    cout << "\nConversion Results:" << endl;
    cout << "===================" << endl;
    cout << fixed << setprecision(2);
    cout << "USD: $" << usd_input << endl;
    cout << "VND: " << fixed << setprecision(0) << vnd_output << " VND" << endl;
    
    return 0;
}
