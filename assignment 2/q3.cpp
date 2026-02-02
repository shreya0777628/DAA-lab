#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

int main() {
    int N = 3, W = 50;
    int value[]  = {100, 60, 120};
    int weight[] = {20, 10, 40};

    vector<Item> items;
    for (int i = 0; i < N; i++)
        items.push_back({value[i], weight[i]});

    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    for (auto item : items) {
        if (W >= item.weight) {
            W -= item.weight;
            totalValue += item.value;
        } else {
            totalValue += item.value * ((double)W / item.weight);
            break;
        }
    }

    cout << "Maximum value = " << totalValue;
    return 0;
}
