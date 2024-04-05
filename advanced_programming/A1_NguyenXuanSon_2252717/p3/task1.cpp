#include <iostream>

using namespace std;

int main() {
    int age;
    double ticket_cost;

    cout << "Enter your age: ";
    cin >> age;

    if (age < 5) {
        ticket_cost = 0;
    } else if (age >= 5 && age <= 10) {
        ticket_cost = 10;
    } else if (age >= 11 && age <= 16) {
        ticket_cost = 20;
    } else {
        ticket_cost = 25;
    }

    cout << "\nTicket Price Information:" << endl;
    cout << "==========================" << endl;
    cout << "Age: " << age << " years old" << endl;
    cout << "Ticket Cost: $" << ticket_cost << endl;

    return 0;
}
