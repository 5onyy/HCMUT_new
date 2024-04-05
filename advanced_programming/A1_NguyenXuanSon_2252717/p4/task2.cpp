#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(nullptr));

    // Generate the secret number between 0 and 20
    int secret_number = rand() % 21;

    int guess;
    bool found = false;

    cout << "Welcome to the Guessing Game!" << endl;
    cout << "Guess the secret number between 0 and 20." << endl;

    // Keep asking the user to guess until they guess the secret number
    while (!found) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess < secret_number) {
            cout << "The secret number is greater than your guess. Try again." << endl;
        } else if (guess > secret_number) {
            cout << "The secret number is smaller than your guess. Try again." << endl;
        } else {
            found = true;
            cout << "Congratulations! You guessed the secret number " << secret_number << " correctly!" << endl;
        }
    }

    return 0;
}
