#include <bits/stdc++.h>
using namespace std;

void bucketSort(int arr[], int n)
{
    int maxElement = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxElement)
            maxElement = arr[i];
    }
    int k = n;

    vector<vector<int>> bucket(k);
    for (int i = 0; i < n; i++)
    {
        int index = (arr[i] * k) / (maxElement + 1);

        bucket[index].push_back(arr[i]);
    }
    for (int i = 0; i < k; i++)
    {
        sort(bucket[i].begin(), bucket[i].end());
    }
    int index = 0;

    for (int i = 0; i < k; i++)
    {
        for (int value : bucket[i])
        {
            arr[index] = value;
            index++;
        }
    }
}

int main()
{
int n;
cout<<"enter the size of an array"<<endl;
cin>>n;
int arr[n];
cout<<"enter the elements of a array"<<endl;
for(int i=0;i<n;i++){
    cin>>arr[i];
}

    bucketSort(arr, n);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
