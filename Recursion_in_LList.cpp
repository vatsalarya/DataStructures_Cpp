#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
Node *head=nullptr;
void Insert(int data,int n=1);
void print(Node *p);
void reversePrint(Node *p);
void reverse(Node *p);

int main(){
    Insert(1,1);
    Insert(2,2);
    Insert(33);
    print(head);
    cout<<endl;
    reverse(head);
    print(head);
    cout<<endl;
    reversePrint(head);
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

void print(Node *p){
    if(p==nullptr) return;
    cout<<p->data<<" ";
    print(p->next);
}
void reversePrint(Node *p){
    if(p==nullptr) return;
    reversePrint(p->next);
    cout<<p->data<<" ";
}
void reverse(Node *p){
    if(p->next==nullptr){
        head = p;
        return;
    }
    reverse(p->next);
    Node *q = p->next;
    q->next = p;
    p->next=nullptr;
}