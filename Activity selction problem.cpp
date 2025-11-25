/*
activity selection problem
activity start time finihed time
sort activity based in early finished time
consider 1st activity


for all other activity
     if (starting time is >= finished first time of previous activities)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Activity
{
    int start, finish;
};

bool activityCompare(Activity a, Activity b)
{
    return a.finish < b.finish;
}

void activitySelection(vector<Activity> &activities)
{
    sort(activities.begin(), activities.end(), activityCompare);
    cout << "Selected Activities (start, finish):\n";

    int lastFinish = activities[0].finish;
    cout << "(" << activities[0].start << ", " << activities[0].finish << ")\n";

        for (int i = 1; i < activities.size(); i++)
            {
        if (activities[i].start >= lastFinish) {
            cout << "(" << activities[i].start << ", " << activities[i].finish << ")\n";
            lastFinish = activities[i].finish;
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    vector<Activity> activities(n);
    cout << "Enter start and finish time of activities:\n";
    for (int i = 0; i < n; i++)
        {
        cin >> activities[i].start >> activities[i].finish;
        }

    activitySelection(activities);

    return 0;
}


























