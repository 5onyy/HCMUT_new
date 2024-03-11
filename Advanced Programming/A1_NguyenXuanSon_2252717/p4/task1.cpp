#include <iostream>

using namespace std;

int main() {
    const int num_students = 10;
    double scores[num_students];
    double total_score = 0;
    
    for (int i = 0; i < num_students; ++i) {
        cout << "Enter the score for student " << i + 1 << ": ";
        cin >> scores[i];
        total_score += scores[i];
    }

    double average_score = total_score / num_students;

    cout << "\nAverage Score: " << average_score << endl;

    return 0;
}
