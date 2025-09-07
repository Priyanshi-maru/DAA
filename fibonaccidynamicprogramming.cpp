#include <iostream>
#include <vector>
using namespace std;

int main()
 {
    int n;
    cout << "Enter number of Fibonacci elements: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Please enter a positive number." << endl;
        return 0;
    }

    vector<long long> fib(n);

    fib[0] = 0;
    if (n > 1) fib[1] = 1;

    for (int i = 2; i < n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    cout << "Fibonacci series up to " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << fib[i] << " ";
    }
    cout << endl;

    return 0;
}
