// Height / Depth of the tree

#include <iostream>
using namespace std;

class Node{
	public:
		Node *left;
		Node *right;
		int val;
		Node(int val, Node *left = nullptr, Node *right = nullptr):val(val), left(left), right(right){};
};

int height(Node* root){{
	if (root==nullptr) return 0;
	int left = (root->left) ? height(root->left) : 0;
	int right = (root->right) ? height(root->right) : 0;
	return max(left, right) + 1;
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

	cout << height(n4);
}
