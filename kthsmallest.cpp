#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;

    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter k: ";
    cin >> k;

    // Sort the array
    sort(arr, arr + n);

    // Kth smallest element
    cout << "Kth smallest element = " << arr[k - 1];

    return 0;
}