/*
Recursion is when a function calls itself to solve a smaller version of the same problem.

2^3 = 2*2*2 = 8
Base case:
If exponent n is 0, return 1.

Recursive case:
Multiply base a with power(a, n-1)

code :-
#include<iostream>
using namespace std;

int power(int a, int n) {
    if(n == 0)
        return 1;
    return a * power(a, n - 1);
}

int main() {
    int a, n;
    cout << "Enter base and exponent: ";
    cin >> a >> n;

    cout << a << "^" << n << " = " << power(a, n);
    return 0;
}

or

*/

#include<iostream>
using namespace std;

double power(int a, int n)
{
    if(n == 0)
        return 1;
    else if(n > 0)
        return a * power(a, n - 1);
    else // n < 0
        return 1.0 / power(a, -n);  // use 1.0 to ensure double division
}

int main()
{
    int base, exponent;
    cout << "Enter base: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> exponent;

    double result = power(base, exponent);
    cout << base << " raised to power " << exponent << " is: " << result << endl;

    return 0;
}

