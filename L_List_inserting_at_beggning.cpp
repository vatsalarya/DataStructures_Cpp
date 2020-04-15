#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};
/*******************************************************************************
IF WE DECLARE IT IN MAIN THEN WE WILL NEED TO PASS THIS ALSO TO FUNCTIONS 
BUT ONE BENIFIT WILL BE WE DONT NEED TO CREATE TEMP BECZ IT IS PASS BY VAL:
WE WILL NEED TO DO(INT MAIN) INSTEAAD OF INSERT(X):
head= insert(head,x);
AND FUNCTION WOULD HAVE RETURNED NODE * INSTEAD OF VOID:
NODE * insert(Node* head,int x)

WE COULD HAVE ALSO PASSED HEAD B REFRENCE SO WE DO:
insert(&head);
AND IN INSERT FUNCTION:
void inster(Node **head, int x)
and replace all head with *head

********************************************************************************/
Node *head;
void insert(int x);
void print();
int main(){
    head = NULL;
    int n{};
    cout<<"How many nos: ";
    cin>>n;
    while(n--){
        int x{};
        cin>>x;
        insert(x);
        print();
    }
}

void insert(int x){
    Node *temp= new Node();
    temp->data = x;
    temp->next = NULL;
    //TO INSERT AT BEGGNING
    if(head!=NULL) temp->next = head;
    head = temp;
}
void print(){
    Node *temp = head;
    cout<<"List is: ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}