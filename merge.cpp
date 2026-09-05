#include<bits/stdc++.h>
using namespace std;
void merge(int array[],int low,int mid,int high){
  int i=low;
  int j=mid+1;
  int k=0;
  int temp[100];
 while(i<=mid&&j<=high){
    if(array[i]<array[j]){
        temp[k]=array[i];
        i++;
    }
    else{
    temp[k]=array[j];
    j++;
    }
    k++;
 }
 while(i<=mid){
    temp[k]=array[i];
    i++;
    k++;
 }
 while(j<=high){
    temp[k]=array[j];
    j++;
    k++;
 }
 for(int i=low,k=0;i<=high;i++,k++){
    array[i]=temp[k];
 }
}
void mergesort(int array[],int low,int high){
    if(low<high){
    int mid=(low+high)/2;
    mergesort(array,low,mid);
    mergesort(array,mid+1,high);
    merge(array,low,mid,high);
    }
}
int main(){
    int n;
    cout<<"enter the size of an array"<<endl;
    cin>>n;
    int array[n];
    cout<<"enter the elements of an array"<<endl;
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
int low=0;
int high=n-1;
mergesort(array,low,high);
for(int i=0;i<n;i++){
    cout<<array[i]<<" ";
}
return 0;
}