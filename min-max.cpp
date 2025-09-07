/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find min and max using divide-and-conquer
pair<int, int> minMax(const vector<int>& arr, int low, int high) {
    // If only one element
    if (low == high) {
        return {arr[low], arr[low]};
    }

    // If two elements
    if (high == low + 1) {
        if (arr[low] < arr[high])
            return {arr[low], arr[high]};
        else
            return {arr[high], arr[low]};
    }

    // More than two elements: divide
    int mid = (low + high) / 2;
    auto left = minMax(arr, low, mid);
    auto right = minMax(arr, mid + 1, high);

    // Combine results
    int minVal = min(left.first, right.first);
    int maxVal = max(left.second, right.second);

    return {minVal, maxVal};
}

int main() {
    vector<int> arr = {3, 1, 9, 7, 5, 2, 8};
    auto result = minMax(arr, 0, arr.size() - 1);

    cout << "Min: " << result.first << endl;
    cout << "Max: " << result.second << endl;

    return 0;
}
*/
// or by sir

#include <iostream>
using namespace std;
pair<int, int> min_max(int a[], int low, int high)
{
    if (low == high)
    {
        return {a[low], a[low]};
    }
    int m = low + (high - low) / 2;
    pair<int, int> left = min_max(a, low, m);
    pair<int, int> right = min_max(a, m + 1, high);
    return {min(left.first, right.first), max(left.second, right.second)};
}
void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i];
    }
    cout << endl;
}
int main()
{
    cout << "Enter size of array";
    int size;
    cin >> size;

    int array[size];
    for (int ind = 0; ind < size; ind++)
    {
        cout << "Enter array element at index " << ind;
        cin >> array[ind];
    }
