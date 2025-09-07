#include <iostream>
#include <algorithm>
using namespace std;

struct item
{
    int wt;
    int val;
    double ratio;
};

// Dynamic Programming Knapsack Function
int knapsackDP(item items[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (items[i - 1].wt <= w)
                dp[i][w] = max(items[i - 1].val + dp[i - 1][w - items[i - 1].wt],
                               dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][capacity];
}

int main()
{
    int size;
    cout << "Enter total items:";
    cin >> size;
    item items[size];
    cout << "Enter details of items:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter item[" << i << "] wt: ";
        cin >> items[i].wt;
        cout << "Enter item[" << i << "] val: ";
        cin >> items[i].val;
        items[i].ratio = (double)items[i].val / items[i].wt;
    }
    sort(items, items + size, [](const item &a, const item &b)
         { return a.ratio > b.ratio; });

    int capacity;
    cout << "Enter total capacity";
    cin >> capacity;

    int current_weight = 0;
    int total_value = 0;
    item selected_items[size];
    int sIndex = 0;
    for (int i = 0; i < size; i++)
    {
        if (current_weight + items[i].wt <= capacity)
        {
            selected_items[sIndex++] = items[i];
            current_weight += items[i].wt;
            total_value += items[i].val;
        }
    }
    cout << "Selected items:" << endl;
    for (int i = 0; i < sIndex; i++)
    {
        cout << selected_items[i].wt << " " << selected_items[i].val << endl;
    }
    cout << "total value" << total_value;
    cout << " wt picked:" << current_weight << endl;

    // -------- Added DP Knapsack Part --------
    int dpResult = knapsackDP(items, size, capacity);
    cout << "\n[Dynamic Programming Result]" << endl;
    cout << "Maximum Value using DP Knapsack = " << dpResult << endl;
    // ----------------------------------------

    return 0;
}
