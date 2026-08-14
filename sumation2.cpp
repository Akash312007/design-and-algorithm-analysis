#include <iostream>
using namespace std;

int main() {
    int n, x;
    long long sum = 0, term = 1;

    cout << "Enter x and n: ";
    cin >> x >> n;

    for (int i = 0; i < n; i++) {
        sum += term;
        term *= x;
    }

    cout << "Sum = " << sum;

    return 0;
}