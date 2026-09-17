#include <iostream>
#include <climits>
using namespace std;

int maxCrossingSum(int arr[], int low, int mid, int high)
{
    int leftSum = INT_MIN, rightSum = INT_MIN;
    int sum = 0;

    for (int i = mid; i >= low; i--)
    {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    sum = 0;

    for (int i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int maxSubarraySum(int arr[], int low, int high)
{
    if (low == high)
        return arr[low];

    int mid = (low + high) / 2;

    int left = maxSubarraySum(arr, low, mid);
    int right = maxSubarraySum(arr, mid + 1, high);
    int cross = maxCrossingSum(arr, low, mid, high);

    return max(left, max(right, cross));
}

int main()
{
    int n;
    cout<<"enter the size of array"<<endl;
    cin >> n;

    int arr[n];
    cout<<"enter the elements of array"<<endl;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << maxSubarraySum(arr, 0, n - 1);

    return 0;
}