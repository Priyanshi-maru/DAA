/*
Linear Search Algorithm
Step-by-step:
1. Start from the first element of the array.
2. Compare each element with the target value.
3. If a match is found, return the index.
4. If no match is found after the loop, return -1.
*/

#include <iostream>
using namespace std;

int linear_search(int a[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] == target)
            return i;
    }
    return -1;
}

void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Enter size of array: ";
    int size;
    cin >> size;

    int array[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element at index " << i << ": ";
        cin >> array[i];
    }

    cout << "Array entered: ";
    printArray(array, size);

    cout << "Enter target value to search: ";
    int target;
    cin >> target;

    int result = linear_search(array, size, target);

    if (result == -1)
        cout << "Target not found in the array." << endl;
    else
        cout << "Target found at index " << result << "." << endl;

    // Your name
    cout << "Programmed by Priyanshi" << endl;

    return 0;
}
