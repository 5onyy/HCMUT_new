#include <iostream>
#include <string>

using namespace std;

const int MAX_STUDENTS = 100;

int main() {
    string names[MAX_STUDENTS];
    int scores[MAX_STUDENTS];
    bool passed[MAX_STUDENTS];

    int num_students = 0;

    // Input students' names and scores
    cout << "Enter student's name and score (0-100), or enter -1 to stop:" << endl;
    while (num_students < MAX_STUDENTS) {
        string name;
        int score;
        cout << "Name: ";
        getline(cin, name);

        // Check if user wants to stop entering data
        if (name == "-1") {
            break;
        }

        cout << "Score: ";
        cin >> score;
        cin.ignore();  // Ignore the newline character left in the buffer by cin

        names[num_students] = name;
        scores[num_students] = score;
        passed[num_students] = score >= 50;
        num_students++;
    }

    // Display students' names, scores, and passed/failed status
    cout << "\nStudents Information:" << endl;
    cout << "======================" << endl;
    cout << "Name\t\tScore\t\tStatus" << endl;
    cout << "---------------------------------" << endl;
    for (int i = 0; i < num_students; ++i) {
        cout << names[i] << "\t\t" << scores[i] << "\t\t" << (passed[i] ? "Passed" : "Failed") << endl;
    }

    return 0;
}
