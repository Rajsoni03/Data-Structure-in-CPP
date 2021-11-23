// Loop Detection using Flyid's Algorithm

#include <iostream>
#include <set>
using namespace std;

class Node {
public:
	int data;
	Node *next;
	Node(int data):data(data), next(nullptr){};
};

Node *head = nullptr;

void display(){
	Node *temp = head;
	cout << "head -> ";
	while(temp != nullptr){
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "nullptr" << endl;
};

bool loop_detection(){ // time = O(n), space = O(1)
	Node *temp1 = head;
	Node *temp2 = head;

	while(temp2 && temp2->next){
		temp1 = temp1->next;
		temp2 = temp2->next->next;
		if (temp1 == temp2) {
			cout << "Loop Detected" << endl;
			return 1;
		}
	}
	cout << "Loop Not Detected" << endl;
	return 0;
}


int main(){
	Node *n1 = new Node(10);
	Node *n2 = new Node(20);
	Node *n3 = new Node(30);
	Node *n4 = new Node(40);
	Node *n5 = new Node(50);
	Node *n6 = new Node(60);

	head = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;

	n6->next = n3;

	cout << loop_detection();
	// display();

	return 0;
}