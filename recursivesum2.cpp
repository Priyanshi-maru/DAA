#include <iostream>
using namespace std;

// Recursive function to calculate sum
int sum(int n) {
    if (n == 0)   // Base case
        return 0;
    else          // Recursive case
        return n + sum(n - 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n < 0) {
        cout << "Sum is not defined for negative numbers!" << endl;
    } else {
        cout << "Sum of first " << n << " natural numbers = " << sum(n) << endl;
    }

    return 0;
}
