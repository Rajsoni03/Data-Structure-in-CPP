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

void print_at_last(int i){
	int count = 0;
	Node *temp = head;
	while(temp != nullptr){
		count++;
		temp = temp->next;
	}
	int index =  count - i;
	temp = head;
	while(--index){
		temp = temp->next;
	}
	cout << temp->data << endl;
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
	print_at_last(ele);
	print_at_last(4);

	return 0;
}