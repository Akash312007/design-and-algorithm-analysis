#include <iostream>
#include <climits>
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

    int answer;

    for (int count = 1; count <= k; count++) {

        int minIndex = -1;
        int minimum = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (arr[i] != INT_MAX && arr[i] < minimum) {
                minimum = arr[i];
                minIndex = i;
            }
        }

        answer = minimum;

        arr[minIndex] = INT_MAX;
    }

    cout << "Kth smallest element = " << answer;

    return 0;
}