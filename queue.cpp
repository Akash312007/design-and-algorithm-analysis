#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
node* front=nullptr;
node*rear=nullptr;
void enqueue(int value){
 node* newnode=new node();
 newnode->data=value;
 newnode->next=nullptr;
 if(rear==nullptr){
    rear=front=newnode;
    return ;
 }
 rear->next=newnode;
 rear=newnode;
 cout<<"element is inserted";
 return ;
}
void dequeue(){
    node* temp=front;
 cout<<"deleted element is "<<front->data<<endl;
 front=front->next;
 delete temp;
 return ;
}
void display(){
    node* temp=front;
    while(temp!=nullptr){
    cout<<temp->data<<"->";
    temp=temp->next;
    }
    cout<<"\n";
    return ;
}
int main(){
    int choice,value;
    while(1){
     cout<<"1st choice for enqueue  operation"<<endl;
     cout<<"2nd choice for dequeue operation"<<endl;
     cout<<"3rd choice for display operation"<<endl;
     cout<<"4th choice for exist operation"<<endl;
     cout<<"enter the choice"<<endl;
     cin>>choice;
     switch(choice){
        case 1:
        cout<<"enter the value to insert"<<endl;
        cin>>value;
        enqueue(value);
        break;
        case 2:
        dequeue();
        break;
        case 3:
        display();
        break;
        case 4:
        return 0;
        break;
        default:
        cout<<"invalid choice"<<endl;
        break;
     }
    }
    return 0;
}