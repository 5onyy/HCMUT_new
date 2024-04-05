#include <iostream>

using namespace std;

#define float double

float sumTripple(float num1, float num2, float num3) {
    return num1 + num2 + num3;
}

float mulTripple(float num1, float num2, float num3) {
    return num1 * num2 * num3;
}

float aveTripple(float num1, float num2, float num3) {
    return (num1 + num2 + num3) / 3;
}

int main() {

    while (true) {
      float num1 = -10101032, num2 = -10101032, num3 = -10101032;
        cout << "Enter three numbers (or -1 to exit): ";
        int x;
        while (cin >> x){
            if (x == -1){
                  cout << "Exiting the program..." << endl;
                  return 0;
            }
            if (num1 == -10101032) num1 = x;
            else if (num2 == -10101032) num2 = x;
            else if (num3 == -10101032) {num3 = x;      break;}
            else break;
        }


        float sum = sumTripple(num1, num2, num3);
        float multiplication = mulTripple(num1, num2, num3);
        float average = aveTripple(num1, num2, num3);

        cout << "Sum: " << sum << endl;
        cout << "Multiplication: " << multiplication << endl;
        cout << "Average: " << average << endl;
    }

    return 0;
}
