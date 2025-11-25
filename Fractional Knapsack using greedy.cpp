#include <iostream>
#include <algorithm>
using namespace std;

struct item {
    int wt;
    int val;
    double ratio;
};

int main() {
    int size;
    cout << "Enter total items: ";
    cin >> size;

    item items[size];

    // Taking input
    for (int i = 0; i < size; i++) {
        cout << "Enter item[" << i << "] weight: ";
        cin >> items[i].wt;
        cout << "Enter item[" << i << "] value: ";
        cin >> items[i].val;

        items[i].ratio = (double)items[i].val / items[i].wt;  // value/weight
    }

    // Sort by ratio (descending)
    sort(items, items + size, [](item a, item b) {
        return a.ratio > b.ratio;
    });

    int capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    double total_value = 0.0;
    int current_weight = 0;

    cout << "\nItems taken (can be fractional):\n";

    for (int i = 0; i < size; i++) {
        if (current_weight + items[i].wt <= capacity) {
            // Take full item
            current_weight += items[i].wt;
            total_value += items[i].val;

            cout << "Full item taken: wt = " << items[i].wt
                 << ", val = " << items[i].val << endl;
        }
        else {
            // Fractional part
            int remaining = capacity - current_weight;

            if (remaining > 0) {
                double fraction_value = items[i].ratio * remaining;

                total_value += fraction_value;
                current_weight += remaining;

                cout << "Fraction taken: wt = " << remaining
                     << ", val = " << fraction_value << endl;
            }
            break;  // bag full
        }
    }

    cout << "\nTotal value in bag = " << total_value << endl;
    cout << "Total weight used = " << current_weight << endl;

    return 0;
}
