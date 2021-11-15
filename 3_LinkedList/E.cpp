#include <iostream>
using namespace std;


class Node {
public:
	int data;
	Node *next;
	Node(int data):data(data), next(nullptr){};	
};
Node *head = nullptr;

void push_front(int data){
	Node *n = new Node(data);
	n->next = head;
	head = n;
}

void display(){
	Node *temp = head;
	cout << "head -> ";
	while (temp != nullptr){
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "nullptr\n";
}

void reverse(){
	Node *temp1 = head;
	Node *temp2 = head->next;
	Node *temp3 = head->next->next;

	while(temp3 != nullptr){
		temp2->next = temp1;
		temp1 = temp2;
		temp2 = temp3;
		temp3 = temp3->next;
	}
	
	temp2->next = temp1;
	head->next = nullptr;
	head = temp2;
}


int main(){

	push_front(10);
	push_front(20);
	push_front(30);
	push_front(40);
	display();
	reverse();
	display();

	return 0;
}