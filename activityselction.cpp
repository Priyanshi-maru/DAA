/*
Here is the **theory in very simple words** + **example in words** (no code).

Activity Selection Problem (Very Simple Theory)**

The activity selection problem means:

* You have many activities.
* Each activity has a start time and an end time.
* You must choose the **maximum number of activities** that **do not overlap**.
* You can do **only one activity at a time**.

To solve this, we use a simple greedy trick:
 Always choose the activity that finishes the earliest.

Because if one activity ends early, you get **more free time** to do other activities.
Steps

1. First, make pairs of each activity like this: (start time, finish time).
2. Arrange all activities in order of **finish time – smallest to largest**.
3. Select the first activity (because it finishes earliest).
4. Then check next activities one by one:

   * If its start time is **greater than** the last selected activity’s finish time → select it
   * Otherwise → skip it
5. Count how many activities you selected.

Example

Suppose we have 6 activities:

* Activity 1: starts at 1, ends at 2
* Activity 2: starts at 3, ends at 4
* Activity 3: starts at 0, ends at 6
* Activity 4: starts at 5, ends at 7
* Activity 5: starts at 8, ends at 9
* Activity 6: starts at 5, ends at 9

How we choose activities?

1. First select the activity that finishes earliest → (1,2)
2. Next is (3,4) → it starts after 2, so select
3. Next (0,6) → starts before 4, so skip
4. Next (5,7) → starts after 4, so select
5. Next (8,9) → starts after 7, so select
6. Last (5,9) → starts before 9, so skip

Final selected activities:

* (1,2)
* (3,4)
* (5,7)
* (8,9)

So we can do **4 activities**.

---

If you want, I can write this **even shorter**, or in **very easy Gujarati-English mix**.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sortByEnd(const vector<int>& x, const vector<int>& y) {
    return x[1] < y[1];
}

int maxActivities(vector<int> &s, vector<int> &f) {
    vector<vector<int>> tasks;

    for (int k = 0; k < s.size(); k++) {
        tasks.push_back({s[k], f[k]});
    }

    sort(tasks.begin(), tasks.end(), sortByEnd);

    int total = 1;
    int last = 0;

    for (int i = 1; i < tasks.size(); i++) {
        if (tasks[i][0] > tasks[last][1]) {
            total++;
            last = i;
        }
    }

    return total;
}

int main() {
    vector<int> s = {1, 3, 0, 5, 8, 5};
    vector<int> f = {2, 4, 6, 7, 9, 9};

    cout << maxActivities(s, f);
    return 0;
}
