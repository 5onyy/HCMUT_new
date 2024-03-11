#include <iostream>
#include <string>

using namespace std;

struct Student {
    string full_name;
    string date_of_birth;
    string hometown;
    string major;
};

int main() {
    Student student;

    cout << "Enter student's full name: ";
    getline(cin, student.full_name);

    cout << "Enter student's date of birth (DD/MM/YYYY): ";
    getline(cin, student.date_of_birth);

    cout << "Enter student's hometown: ";
    getline(cin, student.hometown);

    cout << "Enter student's major: ";
    getline(cin, student.major);

    cout << "\nStudent Information:" << endl;
    cout << "====================" << endl;
    cout << "Full Name: " << student.full_name << endl;
    cout << "Date of Birth: " << student.date_of_birth << endl;
    cout << "Hometown: " << student.hometown << endl;
    cout << "Major: " << student.major << endl;

    return 0;
}
