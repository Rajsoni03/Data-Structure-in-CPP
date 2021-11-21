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
	while(temp != nullptr){
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "nullptr" << endl;
};

void print_at_last_optimized(int i){
	Node *F = head;
	Node *B = head;

	while(i--){	F = F->next; }
	while(F->next != nullptr){
		F = F->next;
		B = B->next;
	}
	cout << B->data << endl;
}


int main(){
	int N, ele;
	cin >> N;
	for (int i = 0; i < N; ++i){
		cin >> ele;
		push_front(ele);
	}

	display();

	cin >> ele;
	print_at_last_optimized(ele);

	return 0;
}