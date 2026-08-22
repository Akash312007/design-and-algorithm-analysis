#include<iostream>
using namespace std;
struct node{
int data;
node*next;
};
node*top=NULL;
void push(int value){
node* newnode=new node();
newnode->data=value;
newnode->next=top;
top=newnode;
cout<<"the enter value "<<value<<"is inserted"<<endl;
return ;
}
void pop(){
  node*temp=top;
  if(top==NULL){
  cout<<"stack is empty";
  return ;
  }
  cout<<"deleted element is "<<top->data<<endl;
  top=top->next;
  delete temp;
  return ;
}
void peek(){
    if(top==NULL){
cout<<"stack is empty"<<endl;
return ;
}
    cout<<"the peek element is "<<top->data<<endl;
    return ;
}
void display(){
 node* temp=top;
 while(temp!=NULL) {
    cout<<temp->data<<"->";
    temp=temp->next;

 } 
 cout<<"\n";
 return ;
}
int main(){
    int choice,value;
    while(1){
     cout<<"1st choice for push operation"<<endl;
     cout<<"2nd choice for pop operation"<<endl;
     cout<<"3rd choice for peek operation"<<endl;
     cout<<"4th choice for display operation"<<endl;
     cout<<"5th choice for exit"<<endl;
     cout<<"enter the choice"<<endl;
     cin>>choice;
     switch(choice){
        case 1:
        cout<<"enter the value to insert"<<endl;
        cin>>value;
        push(value);
        break;
        case 2:
        pop();
        break;
        case 3:
        peek();
        break;
        case 4:
        display();
        break;
        case 5:
        return 0;
        break;
        default:
        cout<<"invalid choice"<<endl;
        break;
     }
    }
    return 0;
}