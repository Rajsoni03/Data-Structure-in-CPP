// Convert to Mirror Tree

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

void inorder(Node *n){
	if (!n) return;
	if (n->left) inorder(n->left);
	cout << n->val << ' ';
	if (n->right) inorder(n->right);
}

void mirror(Node *n){
	if (!n) return;
	if (n->left) mirror(n->left);
	if (n->right) mirror(n->right);
	if (n->left && n->right) swap(n->left, n->right);
}

/*
        4                       4
      /   \                   /   \
     2     6       -->       6     2 
    / \   / \               / \   / \
   1   3 5   7             7   5 3   1
*/


int main(){
	Node *n         = new Node(4);
	n->left         = new Node(2);
	n->left->left   = new Node(1);
	n->left->right  = new Node(3);
	n->right        = new Node(6);
	n->right->left  = new Node(5);
	n->right->right = new Node(7);

	cout << "Preorder of Orignal Tree" << endl;
	inorder(n);

	mirror(n);

	cout << "\nPreorder of Mirror Tree" << endl;
	inorder(n);
}