#include<bits/stdc++.h>
using namespace std;
int main(){
unordered_map<int,int>freq;
int n;
cout<<"enter the size of array"<<endl;
cin>>n;
vector<int>nums(n);
cout<<"enter the elements of array :"<<endl;
for(int i=0;i<n;i++){
    cin>>nums[i];
}
for(int i=0;i<n;i++){
        freq[nums[i]]++;
    }
    for(auto x:freq)
    cout<<x.first<<"->"<<x.second<<endl;
return 0;
}
