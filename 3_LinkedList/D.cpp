#include <iostream>
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

		LinkedList(const & LinkedList obj){
			

		}

		void push_front(T data){
			Node *n = new Node(data); 	
			n->next = head;			  			
			head = n;				  			
			if (tail == nullptr){ tail = head; } 
		};

		void push_back(T data){
			Node *n = new Node(data);
			if (head == nullptr){ head = tail = n; }
			else { tail->next = n; tail = n; }
		};

		void pop_front(){
			if (head != nullptr){
				Node *temp = head;
				if (head == tail){ tail = nullptr; }
				head = head->next;
				delete temp;
			}
		}

		void pop_back(){
			if (head != nullptr){
				if (head->next == nullptr){
					delete head;
					head = tail = nullptr;
				}
				else{
					Node *temp = head;
					while (temp->next->next != nullptr){ temp = temp->next;	}
					delete temp->next;
					temp->next = nullptr;
				}
			}
		}

		void push_at(T data, int index){
			Node *temp = head;
			if (index == 0){ push_front(data); }
			else {
				while (--index){
					temp = temp->next;	
					if (temp == nullptr) { cout << "index out of bounds" << endl; return; }
				}
				Node *n = new Node(data);
				n->next = temp->next;
				temp->next = n;
			}
		};

		void pop_at(int index){
			if (head == nullptr){ return; }
			if (index == 0){ pop_front(); }
			else{
				Node *temp = head;
				while (--index){
					temp = temp->next;
					if (temp == nullptr) { cout << "index out of bounds" << endl; return; }
				}
				Node *del = temp->next;
				temp->next = temp->next->next;
				delete del;
			}
		};

		void display(){
			Node *temp = head;
			cout << "head -> ";
			while(temp != nullptr){
				cout << temp->data << " -> ";
				temp = temp->next;
			}
			cout << "nullptr" << endl;
		};

		bool empty(){
			if (head == nullptr) return true;
			else return false;
		}

};

int main(){
	LinkedList<int> lst;

	lst.push_front(10);
	lst.push_front(20);
	lst.push_front(30);
	lst.push_back(5);
	lst.push_back(6);

	lst.push_at(25, 1);
	lst.push_at(15, 3);

	lst.pop_at(3);
	lst.pop_front();


	lst.display();
	return 0;
}