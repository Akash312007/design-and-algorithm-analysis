
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
    while(hash[index]!=-1){
        index=(index+1)%n;
    }
    hash[index]=key;
 }
 for(int x : hash)
 cout<<x<<" ";
 return 0;
}
 