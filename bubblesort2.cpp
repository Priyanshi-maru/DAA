#include <iostream>
using namespace std;

int main() {
    int n;

    // Step 1: Input size of array
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    // Step 2: Input array elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 3: Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;  // Optimization
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // If no swaps, array already sorted
        if (!swapped)
            break;
    }

    // Step 4: Output sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
