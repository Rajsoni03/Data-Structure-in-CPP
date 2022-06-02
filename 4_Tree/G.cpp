// Check If Two Trees Are Mirror

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Node{
	public:
		Node *left;
		Node *right;
		int val;
		Node(int val, Node *left = nullptr, Node *right = nullptr):val(val), left(left), right(right){};
};

bool areMirror(Node *n1, Node *n2){
	if (!n1 && !n2) return true;
	if (!n1 || !n2) return false;
	return (n1->val == n2->val) && areMirror(n1->left, n2->right) && areMirror(n1->right, n2->left);
}

/*
        4                       4
      /   \                   /   \
     2     6       ==        6     2 
    / \   / \               / \   / \
   1   3 5   7             7   5 3   1
*/


int main(){
	Node *n1         = new Node(4);
	n1->left         = new Node(2);
	n1->left->left   = new Node(1);
	n1->left->right  = new Node(3);
	n1->right        = new Node(6);
	n1->right->left  = new Node(5);
	n1->right->right = new Node(7);

	Node *n2         = new Node(4);
	n2->left         = new Node(6);
	n2->left->left   = new Node(7);
	n2->left->right  = new Node(5);
	n2->right        = new Node(2);
	n2->right->left  = new Node(3);
	n2->right->right = new Node(1);

	areMirror(n1, n2) ? cout << "Are Mirror" : cout << "Are Not Mirror" ;
}