/*
Algorithm for Linear Search

Start

Input the size of the array (n).

Input n elements into the array.

Input the element to be searched (key).

Set flag = -1 (to check if element is found).

Repeat for i = 0 to n-1:

If arr[i] == key:

Set flag = i (store the index).

Break the loop.

If flag != -1, print "Element found at position (flag+1)".

Else, print "Element not found".

End

*/

#include <iostream>
using namespace std;

int main() {
    int n, key, flag = -1;

    // Step 1: Input size of array
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];  // Array declaration

    // Step 2: Input array elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 3: Input element to search
    cout << "Enter element to search: ";
    cin >> key;

    // Step 4: Linear Search
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            flag = i;   // Store index
            break;      // Exit loop if found
        }
    }

    // Step 5: Display result
    if (flag != -1)
        cout << "Element found at position " << flag + 1 << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
