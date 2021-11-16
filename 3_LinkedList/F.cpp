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
	while(temp != nullptr){
		cout << temp->data << endl;
		temp = temp->next;
	}
}

bool find(int ele){
	Node *temp = head;
	while(temp != nullptr){
		if (temp->data == ele) return true;
		temp = temp->next;
	}
	return false;
}

int main(){
	int N, ele;
	cin >> N;
	for (int i = 0; i < N; ++i){
		cin >> ele;
		push_front(ele);
	}
	cin >> ele;

	if (find(ele)) cout << "element found\n";
	else cout << "element not found\n";


	return 0;
}