#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
 cout<<"enter the size of hash table"<<endl;
 cin>>n;
 int hash[n];
 for(int i=0;i<n;i++){
    hash[i]=-1;
 }
 int key,size,index;
 cout<<"enter the no of elements to be inserted in hash table"<<endl;
 cin>>size;
 for(int i=0;i<size;i++){
    cout<<"enter the element"<<endl;
    cin>>key;
    index=key%n;
    i=index;
    int j=1;
    while(hash[i]!=-1) {
     i=(index+j*j)%n;
     j++;
    } 
   hash[i]=key;
}
   for(int x:hash)
   cout<<x<<" ";
return 0;
}