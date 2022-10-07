// Iterative Postorder Traversal

#include <iostream>
#include <stack>
using namespace std;

class Node{
	public:
		Node *left;
		Node *right;
		int val;
		Node(int val, Node *left = nullptr, Node *right = nullptr):val(val), left(left), right(right){};
};

// void print(stack<Node*> stk1, stack<Node*> stk2){
// 	while(!stk1.empty()){
// 		cout << stk1.top()->val << ' ';
// 		stk1.pop();
// 	}
// 	cout << endl;
// 	while(!stk2.empty()){
// 		cout << stk2.top()->val << ' ';
// 		stk2.pop();
// 	}
// 	cout << endl << endl;
// }

void postorderIterative(Node *n){
	stack<Node*> stk1;
	stack<Node*> stk2;
	stk1.push(n);
 
	while(!stk1.empty()){
		// print(stk1, stk2);

		n = stk1.top();
		stk2.push(n);
		stk1.pop();		

		if (n->left) stk1.push(n->left);
		if (n->right) stk1.push(n->right);
	}
	// print(stk1, stk2);
	while(!stk2.empty()){
		cout << stk2.top()->val << ' ';
		stk2.pop();
	}
}


/*
		4
	  /   \
	 2	   6
    / \	  / \
   1   3 5   7

*/

int main(){
	Node *n1 = new Node(1);
	Node *n3 = new Node(3);
	Node *n2 = new Node(2, n1, n3);

	Node *n5 = new Node(5);
	Node *n7 = new Node(7);
	Node *n6 = new Node(6, n5, n7);

	Node *n4 = new Node(4, n2, n6);

	postorderIterative(n4);
}