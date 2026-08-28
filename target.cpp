#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter the size of array"<<endl;
    cin>>n;
vector<int>array(n);
cout<<"enter the array elements"<<endl;
for(int i=0;i<n;i++){
  cin>>array[i];
}
int target,remaing;
cout<<"enter the target element"<<endl;
cin>>target;
unordered_set<int>s;
for(int i=0;i<n;i++){
    remaing=target-array[i];
    if(s.find(remaing)!=s.end()){
        cout<<"the two elements are found  and elements are "<<remaing<<" "<<array[i]<<endl;
        return 0;
    }
    s.insert(array[i]);
}
cout<<"elements are not found"<<endl;
return 0;



}