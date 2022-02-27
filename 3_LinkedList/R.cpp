// Implement push_at() and pop_at() method in douby LinkedList

#include <iostream>
using namespace std;

template <typename T>
class DoublyLinkedList{
	private:
		class Node {
		public:
			T data;
			Node *next;
			Node *prev;
			Node(T data):data(data), next(nullptr), prev(nullptr){};
		};
		Node *head;
		Node *tail;
		int size;
	public:
		DoublyLinkedList():head(nullptr), size(0){};	

		void push_front(T data){
			Node *n = new Node(data);
			n->next = head;
			head ?  head->prev = n : tail = n;
			head = n;
			size++;
		}

		void push_back(T data){
			Node *n = new Node(data);
			n->prev = tail;
			tail ? tail->next = n : head = n;
			tail = n;
			size++;
		}

		void display(){
			Node *temp = head;
			cout << "head -> ";
			while(temp){
				cout << temp->data << " -> ";
				temp = temp->next;
			}
			cout << " tail\n";
		}

		void display_reverse(){
			Node *temp = tail;
			cout << "tail -> ";
			while(temp){
				cout << temp->data << " -> ";
				temp = temp->prev;
			}
			cout << " head\n";
		}
		// void push_at(T data, int index){
		// 	if (index == 0) {push_front(data); return;}
		// 	if (size == index) {push_back(data); return;}
		// 	if (size < index) {cout << "index out of range\n"; return;}
		// 	Node *temp = head;
		// 	while(index--){
		// 		temp = temp->next;
		// 	}
		// 	Node *n = new Node(data);
		// 	n->next = temp;
		// 	n->prev = temp->prev;
		// 	temp->prev->next = n;
		// 	temp->prev = n;
		// 	size++;
		// }

		void push_at(T data, int index){
			if (index == 0) {push_front(data); return;}
			if (size == index) {push_back(data); return;}
			if (size < index) {cout << "index out of range\n"; return;}
			Node *temp = head;
			while(--index){
				temp = temp->next;
			}
			Node *n = new Node(data);
			n->next = temp->next;
			n->prev = temp;
			temp->next = n;
			n->next->prev = n;
			size++;
		}
		int pop_at(){
			
		}
};

int main(){
	DoublyLinkedList<int> dll;
	dll.push_front(20);
	dll.push_front(10);
	dll.push_back(30);
	dll.push_back(40);
	dll.push_front(50);
	dll.push_back(60);
	dll.display();

	dll.push_at(90, 10);
	dll.display();
	return 0;
}