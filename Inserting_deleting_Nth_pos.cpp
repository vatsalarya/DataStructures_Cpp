#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};
Node *head=nullptr;
void Insert(int data,int n=1){
    Node *temp = new Node();
    temp->data=data;
    if(n==1){
        temp->next = head;
        head=temp;
        return;
    }
    Node *temp1=head;
    for(int i=0; i<n-2; i++)
        temp1 = temp1->next;
    temp->next=temp1->next;
    temp1->next=temp;

}
void Delete(int n =1){
    Node *temp = head;
    if(n==1){
        head = temp->next;
        delete temp;
        return;
    }
    for(int i=0; i<n-2; i++)
        temp = temp->next;
    Node *temp1 = temp->next;
    temp->next = temp1->next;
    delete temp1;

}
void print(){
    Node *temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Insert(1,1);
    print();
    Insert(2,2);
    print();
    Delete(2);
    print();
    Insert(33);
    print();
    return 0;
}