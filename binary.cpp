#include<iostream>
using namespace std;
int binary(int key,int array[],int beg,int end){
 while(beg<=end){
  int mid=(beg+end)/2;
  if(array[mid]==key){
    cout<<"element is found at index"<<" "<<mid;
    return 0;
  }
  else if(array[mid]<key){
    beg=mid+1;
  }
  else
  end=mid-1;

 }
 cout<<"element is not found"<<endl;
 return 0;  
}
int main(){
 int n,key;
 cout<<"enter the size of array"<<endl;
 cin>>n;
 int array[n],beg=0,end=n-1;
 cout<<"enter the elements of array"<<endl;
 for(int i=0;i<n;i++){
    cin>>array[i];
 }
cout<<"enter the key element"<<endl;
cin>>key;
binary(key,array,beg,end);
return 0;
}
