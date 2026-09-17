#include <iostream>
using namespace std;

struct Result {
    int min;
    int max;
};

Result findMinMax(int arr[], int low, int high) {
    if (low == high) {
        return {arr[low], arr[low]};
    }
    if (high == low + 1) {
        if (arr[low] < arr[high])
            return {arr[low], arr[high]};
        else
            return {arr[high], arr[low]};
    }
    int mid = (low + high) / 2;

    Result left = findMinMax(arr, low, mid);
    Result right = findMinMax(arr, mid + 1, high);
    Result result;

    result.min=(left.min<right.min)?left.min:right.min;
    result.max=(left.max>right.max)?left.max:right.max;
    return result;
}

int main() {
int n;
cout<<"enter the size of an array"<<endl;
cin>>n;
int arr[n];
cout<<"enter the array elements"<<endl;
for(int i=0;i<n;i++){
    cin>>arr[i];
}
    Result result = findMinMax(arr, 0, n - 1);

    cout << "Minimum = " << result.min << endl;
    cout << "Maximum = " << result.max << endl;

    return 0;
}


