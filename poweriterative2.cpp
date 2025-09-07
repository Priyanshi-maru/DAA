#include <iostream>
using namespace std;

double power(int base, int exponent) {
    double result = 1.0;

    if (exponent >= 0) {
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
    } else { // handle negative exponent
        for (int i = 0; i < -exponent; i++) {
            result *= base;
        }
        result = 1.0 / result;
    }

    return result;
}

int main() {
    int base, exponent;
    cout << "Enter base: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> exponent;

    double result = power(base, exponent);
    cout << base << " raised to power " << exponent << " is: " << result << endl;

    return 0;
}
