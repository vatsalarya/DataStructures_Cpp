#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
Node *head=nullptr;
void Insert(int data,int n=1);
void print();
void reverse();
int main(){
    Insert(1,1);
    Insert(2,2);
    Insert(33);
    print();
    reverse();
    print();
    return 0;
}

void Insert(int data,int n){
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

void print(){
    Node *temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void reverse(){
    Node *current,*next,*previous;
    current = head;
    previous=nullptr;
    while(current != nullptr){
        next=current->next;
        current->next=previous;
        previous = current;
        current=next;
    }
    head = previous;
}