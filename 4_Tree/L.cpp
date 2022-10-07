// Minimum depth of tree

#include <iostream>
#include <climits>
using namespace std;

class Node{
	public:
		Node *left;
		Node *right;
		int val;
		Node(int val, Node *left = nullptr, Node *right = nullptr):val(val), left(left), right(right){};
};

int minDepth(Node* root){
	if (root==nullptr) return 0;
	if (root->left && root->right) return 1;
	int left = (root->left) ? minDepth(root->left) : INT_MAX;
	int right = (root->right) ? minDepth(root->right) : INT_MAX;
	return min(left, right) + 1;
}

/*
		4
	  /   \
	 2	   6
       	  / \
         5   7
*/

int main(){
	Node *n1 = new Node(1);
	Node *n3 = new Node(3);
	Node *n2 = new Node(2, n1, n3);
	// Node *n2 = new Node(2);

	Node *n5 = new Node(5);
	Node *n7 = new Node(7);
	Node *n6 = new Node(6, n5, n7);

	Node *n4 = new Node(4, n2, n6);

	cout << minDepth(n4);
}


// int minDepth(Node* n){
// 	if (!n) return 0;
// 	if (n->left && n->right) return 1;
// 	int l = (n->left) ? minDepth(n->left) : INT_MAX;
// 	int r = (n->right) ? minDepth(n->right) : INT_MAX;
// 	return (l<r)?l+1:r+1;
// }
