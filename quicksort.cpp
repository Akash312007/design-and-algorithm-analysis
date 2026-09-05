#include<bits/stdc++.h>
using namespace std;
int partion(int array[],int low,int high){
    int pivot=array[low];
    int i=low+1;
    int j=high;
   while(i<=j){
    while(i<=high&&pivot>array[i]){
        i++;
    }
    while(j>=low&&pivot<array[j]){
        j--;
    }
    if(i<j){
        swap(array[i],array[j]);
        i++;
        j--;
    }
   }
   swap(array[low],array[j]);
   return j;
}
void quicksort(int array[],int low,int high){
    if(low<high){
      int p=partion(array,low,high);
      quicksort(array,low,p-1);
      quicksort(array,p+1,high);
    }
}
int main(){
    int n;
    cout<<"enter the size of an array"<<endl;
    cin>>n;
    int array[n];
    cout<<"enter the elements of a array"<<endl;
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    quicksort(array,0,n-1);
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}
