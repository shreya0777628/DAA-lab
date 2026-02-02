#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n = 5;
    int arrival[]   = {900, 910, 920, 1100, 1120};
    int departure[] = {940, 1200, 950, 1130, 1140};

    sort(arrival, arrival + n);
    sort(departure, departure + n);

    int platforms = 1, maxPlatforms = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (arrival[i] <= departure[j]) {
            platforms++;
            i++;
        } else {
            platforms--;
            j++;
        }
        maxPlatforms = max(maxPlatforms, platforms);
    }

    cout << "Minimum number of platforms required = " << maxPlatforms;
    return 0;
}
