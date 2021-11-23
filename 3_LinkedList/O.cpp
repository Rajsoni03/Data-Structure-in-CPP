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
			// if (head) head->prev = n; else tail = n;
			head ?  head->prev = n : tail = n;
			head = n;
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
};

int main(){
	DoublyLinkedList<int> dll;
	dll.push_front(10);
	dll.push_front(20);
	dll.push_front(30);
	dll.push_front(40);
	dll.display();
	dll.display_reverse();
	return 0;
}