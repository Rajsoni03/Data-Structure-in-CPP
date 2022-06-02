// Check if Two Trees Are Same

#include <iostream>
using namespace std;

class Node{
	public:
		Node *left;
		Node *right;
		int val;
		Node(int val, Node *left = nullptr, Node *right = nullptr):val(val), left(left), right(right){};
};

bool areSame(Node *n1, Node *n2){
	if (!n1 && !n2) return true;
	if (!n1 || !n2) return false;
	return (n1->val == n2->val) && areSame(n1->left, n2->left) && areSame(n1->right, n2->right);
}

/*
        4                       4
      /   \                   /   \
     2     6       ==        2     6 
    / \   / \               / \   / \
   1   3 5   7             1   3 5   7
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
	n2->left         = new Node(2);
	n2->left->left   = new Node(1);
	n2->left->right  = new Node(3);
	n2->right        = new Node(6);
	n2->right->left  = new Node(5);
	n2->right->right = new Node(7);

	areSame(n1, n2) ? cout << "Are Same" : cout << "Are Not Same" ;
}