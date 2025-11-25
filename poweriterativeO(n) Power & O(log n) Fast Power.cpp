#include <iostream>
using namespace std;
double powerON(int base, int exponent)
{
    double result = 1.0;

    if (exponent >= 0) {
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
    } else {
        for (int i = 0; i < -exponent; i++) {
            result *= base;
        }
        result = 1.0 / result;
    }

    return result;
}
double powerOlogN(int base, int exponent) {
    if (exponent == 0)
        return 1;

    if (exponent < 0)
        return 1.0 / powerOlogN(base, -exponent);

    double half = powerOlogN(base, exponent / 2);

    if (exponent % 2 == 0)
        return half * half;
    else
        return base * half * half;
}

int main() {
    int base, exponent;
    cout << "Enter base: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> exponent;

    cout << "\nUsing O(n) method: "
         << powerON(base, exponent);

    cout << "\nUsing O(log n) method: "
         << powerOlogN(base, exponent);

    cout << endl;
    return 0;
}
