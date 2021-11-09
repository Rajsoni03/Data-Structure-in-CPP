#include <iostream>
using namespace std;

template <class T>
class LinkedList{
	class Node{
	public:
		Node *next;
		T data;
		Node(T data):data(data), next(nullptr){}
	};
	Node *head;
	public:

		LinkedList():head(nullptr){};
	
		void push_front(T data){
			Node *n = new Node(data);
			n->next = head;
			head = n;
		}

		void push_back(T data){
			Node *n = new Node(data);
			if (head == nullptr) { head = n; }
			else{
				Node *temp = head;
				while(temp->next != nullptr){ temp = temp->next; }
				temp->next = n;
			}
		}

		void push_at(T data, int index){
			Node *n = new Node(data);
			if (index == 0){
				n->next = head;
				head = n;
			}
			else {
				Node *temp = head;
				while(--index){	temp = temp->next; }
				n->next = temp->next;
				temp->next = n;
			}
		}

		void pop_front(){
			Node *temp = head;
			head = head->next;
			delete temp;
		}

		void pop_end(){
			Node *temp = head;
			while ((temp->next)->next != nullptr){ temp = temp->next; }
			delete temp->next;
			temp->next = nullptr;
		}

		void pop_at(int index){
			Node *temp = head;
			while(--index){	temp = temp->next; }
			Node *del = temp->next;
			temp->next = (temp->next)->next;
			delete del;
		}

		void print(){
			Node *temp = head;
			while(temp != nullptr){
				cout << temp->data << " -> ";
				temp = temp->next;
			}
			cout << "NULL" << endl;
		}
};

int main(){
	LinkedList<int> lst;
	
	lst.push_front(4);
	lst.push_front(3);
	lst.push_front(1);
	lst.push_back(5);
	lst.push_at(2, 1);

	lst.pop_front();
	lst.pop_end();
	lst.pop_at(1);

	lst.print();

	return 0;
}