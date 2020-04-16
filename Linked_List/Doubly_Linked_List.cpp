#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};
Node *head=nullptr;
Node * GetNewNode(int x=0){
    Node *newNode = new Node();
    newNode->data=x;
    newNode->next=nullptr;
    newNode->prev=nullptr;
    return newNode;
}
void insertAtHead(int x){
    Node *newNode = GetNewNode(x);
    if(head == nullptr) return;
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}
void Insert(int x,int n=1){
    Node *newNode = GetNewNode(x);
    
    if(n==1){
        if(head!=nullptr)
            head->prev = newNode;
        newNode->next = head;
        head=newNode;
        return;
    }
    Node *temp = head;
    for(int i=0; i<n-2; i++)
        temp = temp->next;
    newNode->next = temp->next;
        newNode->prev = temp;
    if(temp->next != nullptr)
    temp->next->prev = newNode; 
    temp->next = newNode;
}

void print(Node *p=head){
    if(p==nullptr) return;
    cout<<p->data<<" ";
    print(p->next);
}

int main(){
    Insert(1,1);
    print();cout<<endl;
    Insert(2,2);
    print();cout<<endl;
    Insert(33);
    print();cout<<endl;
}