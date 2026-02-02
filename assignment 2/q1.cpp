#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to store activity start and finish time
struct Activity {
    int start, finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;  // sort by finish time
}

int main() {
    int N = 6;
    int start[]  = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};

    vector<Activity> activities;
    for (int i = 0; i < N; i++)
        activities.push_back({start[i], finish[i]});

    sort(activities.begin(), activities.end(), compare);

    int count = 1;
    int lastFinish = activities[0].finish;

    cout << "Selected activities:\n";
    cout << "(" << activities[0].start << ", " << activities[0].finish << ") ";

    for (int i = 1; i < N; i++) {
        if (activities[i].start >= lastFinish) {
            cout << "(" << activities[i].start << ", " << activities[i].finish << ") ";
            lastFinish = activities[i].finish;
            count++;
        }
    }

    cout << "\nMaximum number of activities = " << count;
    return 0;
}
