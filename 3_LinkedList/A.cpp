#include <iostream>
#include "LinkedList.h"
using namespace std;

template <class T>
class LinkedList{
	private:
	class Node {
		public:
			T data;
			Node *next;
			Node(T data) : data(data), next(nullptr){};
	};
	Node *head, *tail;

	public:
		LinkedList() : head(nullptr), tail(nullptr){};

		void push_front(T data){
			Node *n = new Node(data); 				// step 1
			n->next = head;			  				// step 2
			head = n;				  				// step 3
			if (tail == nullptr){ tail = head; } 	// step 4
		};

		void push_back(T data){};
		void push_at(T data, int index){};

		void display(){
			Node *temp = head;
			cout << "head -> ";
			while(temp != nullptr){
				cout << temp->data << " -> ";
				temp = temp->next;
			}
			cout << "nullptr" << endl;
		};
};

int main(){
	LinkedList<int> lst;
	lst.push_front(10);
	lst.push_front(20);
	lst.push_front(30);

	lst.display();
	return 0;
}