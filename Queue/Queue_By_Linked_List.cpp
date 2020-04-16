#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

// Two glboal variables to store address of front and rear nodes. 
Node* front = nullptr;
Node* rear = nullptr;

void Enqueue(int x) {
	Node* temp = new Node();
	temp->data =x; 
	temp->next = nullptr;
	if(front == nullptr && rear == nullptr){
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

void Dequeue() {
	struct Node* temp = front;
	if(front == nullptr) {
		cout<<"Queue is Empty\n";
		return;
	}
	if(front == rear)
		front = rear = nullptr;
	else
		front = front->next;
    delete temp;
}

int Front() {
	if(front == nullptr) {
		cout<<"Queue is Empty\n";
		return 0;
	}
	return front->data;
}

void Print() {
	Node* temp = front;
	while(temp != nullptr) {
		cout<<temp->data;
		temp = temp->next;
	}
	cout<<endl;
}

int main(){
	Enqueue(2); Print(); 
	Enqueue(4); Print();
	Enqueue(6); Print();
	Dequeue();  Print();
	Enqueue(8); Print();
}