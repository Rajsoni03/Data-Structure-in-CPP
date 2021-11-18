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

void pop_at(int start_index, int end_index){
	Node *temp1 = head;	
	int range = end_index - start_index;

	while(--start_index){ 
		temp1 = temp1->next; 
	}

	Node *temp2 = temp1->next;
	while(range--){
		Node *del = temp2;
		temp2 = temp2->next;
		delete del;
	}
	temp1->next = temp2;
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

	pop_at(start_index, end_index);

	display();

	return 0;
}