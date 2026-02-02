#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            return binarySearch(arr, low, mid - 1, key);
        else
            return binarySearch(arr, mid + 1, high, key);
    }
    return -1;
}

int main() {
    int arr[] = {2,5,8,12,16,23,38,56,72,91};
    int n = 10, key = 23;

    int result = binarySearch(arr, 0, n-1, key);

    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";
}
