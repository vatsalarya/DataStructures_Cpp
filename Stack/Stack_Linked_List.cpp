#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* link;
};
struct Node* top = nullptr;

void Push(int x){
    Node *temp = new Node();
    temp->data = x;
    temp->link = top;
    top = temp;
}

void Pop(){
    if(top ==nullptr) {
        cout<<"Already Empty"<<endl;
        return;
    }
    top = top->link;
}

bool isEmpty(){
    if(top == nullptr) return 1;
    else return 0;
}

int Top(){
    return top->data;
}

void Print(){
    Node* temp = top;
    if(isEmpty()){
        printf("Stack is Empty");
        return;
    }
    cout<<"Top| ";
    while(temp != NULL){
        cout<<temp->data<<"  ";
        temp = temp->link;
    }
    cout<<"|End"<<endl;
}

int main()
{
   int choice,enter;

    while(choice =! 0){

            cout<<"\nPlease ENTER your choice\n"
                <<"1. Push\n"
                <<"2. Pop\n"
                <<"3. What is Top ?\n"
                <<"4. Is Stack Empty ?\n"
                <<"5. Print Stack\n";

            printf("Choice: ");

            cin>>choice;
            cout<<endl;

            switch(choice){

            case 1: printf("Enter the number for Push: ");
                    cin>>enter;
                    Push(enter);
                    cout<<endl;
                    break;

            case 2: Pop();
                    cout<<"It's popped!\n";
                    break;

            case 3: enter = Top();
                    cout<<"Top is = "<<enter<<endl;
                    break;

            case 4: enter = isEmpty();
                    if(enter == 1)
                    cout<<"Yes, It's empty\n";
                    else
                    cout<<"Nope, It contains elements\n";
                    break;

            case 5: cout<<"Stack Elements: ";
                    Print();
                    cout<<endl;
                    break;

            default : cout<<"Enter numbers between 1 and 5 !\n";
                      break;
            }
    }      
  return 0;
}