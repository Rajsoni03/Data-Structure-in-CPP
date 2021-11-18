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
	Node *temp1 = head;
	Node *temp2 = head->next;
	Node *temp3 = head->next->next;
	
	while (temp3 != nullptr){
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
	int N, ele;
	cin >> N;
	for (int i = 0; i < N; ++i){
		cin >> ele;
		push_front(ele);
	}

	int start_index, end_index;

	cin >> start_index >> end_index;

	display();

	reverse();

	display();

	return 0;
}