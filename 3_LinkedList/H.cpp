// Reverse a LinkList using with new node

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
	Node *n = new Node(data); // Step 1
	n->next = head;           // Step 2
	head = n; 		          // Step 3
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

void reverse(){
	Node *temp = head;
	Node *temp_head = nullptr;
	while(temp != nullptr){
		Node *n = new Node(temp->data);
		n->next = temp_head;
		temp_head = n;

		Node *del = temp; 
		temp = temp->next; 
		delete del;
	}
	head = temp_head;
}



int main(){
	int N, ele;
	cin >> N;
	for (int i = 0; i < N; ++i){
		cin >> ele;
		push_front(ele);
	}
	
	display();
	reverse();
	display();

	return 0;
}