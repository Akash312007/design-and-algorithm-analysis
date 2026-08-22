#include<iostream>
using namespace std;
void towersofhanoi(int n,char source,char middle,char destination){
    if(n==1){
      cout<<"move disk 1 from"<<" "<<source<<" "<<"to"<<" "<<destination<<endl;
      return ; 
    }
    towersofhanoi(n-1,source,destination,middle);
    cout<<"move disk "<<n<<" from "<<source<<" to "<<destination<<endl;
    towersofhanoi(n-1,middle,source,destination);
}
int main(){
    int n;
    cout<<"enter the no.of disks"<<endl;
    cin>>n;
    towersofhanoi(n,'s','m','d');
    return 0;
}