#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline, profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int N = 5;
    Job jobs[] = {
        {'J', 2, 100},
        {'K', 1, 19},
        {'L', 2, 27},
        {'M', 1, 25},
        {'N', 3, 15}
    };

    sort(jobs, jobs + N, compare);

    bool slot[4] = {false};
    char result[4];
    int totalProfit = 0, count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                result[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                count++;
                break;
            }
        }
    }

    cout << "Selected Jobs: ";
    for (int i = 1; i <= 3; i++)
        if (slot[i]) cout << result[i] << " ";

    cout << "\nMaximum Profit = " << totalProfit;
    return 0;
}
