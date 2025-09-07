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

    // Step 3: Insertion Sort
    for (int i = 1; i < n; i++) {
        int key = arr[i];   // Current element
        int j = i - 1;

        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;   // Insert key in correct position
    }

    // Step 4: Output sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
