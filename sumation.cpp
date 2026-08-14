#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x, n;
    double sum;

    cout << "Enter x and n: ";
    cin >> x >> n;

    if (x == 1)
        sum = n;
    else
        sum = (pow(x, n) - 1) / (x - 1);

    cout << "Sum = " << sum;

    return 0;
}