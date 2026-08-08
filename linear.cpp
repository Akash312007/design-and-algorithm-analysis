#include<iostream>
using namespace std;
int linear(int key,int array[],int n){
 for(int i=0;i<n;i++){
    if(array[i]==key){
        return i;  
    }
 }
 return -1;   
}
int main(){
 int key,n;
 cout<<"enter the size of array"<<endl;
 cin>>n;
 cout<<"enter the key element"<<endl;
 cin>>key;
 int array[n];
 cout<<"enter elements of array"<<endl;
 for(int i=0;i<n;i++){
    cin>>array[i];
 }
 int result=linear(key,array,n);
if(result==-1)
cout<<"element is not found";
else
cout<<"element is found at index"<<" "<<result;
return 0;
}
