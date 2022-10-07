// construct binery tree
// using preorder and inorder
#include <iostream>
#include <unordered_map>
using namespace std;

struct Node{
	int val;
	Node* left;
	Node* right;
	Node(int val, Node* left = nullptr, Node* right = nullptr){
		this->val = val;
		this->left = left;
		this->right = right;
	}
};


void inorderTraversal(Node *root){
	if (!root) return;
	if (root->left) inorderTraversal(root->left);
	if (root->right) inorderTraversal(root->right);
	cout << root->val << ' ';
}


void buildTree(Node** tree, int p1, int p2, int preorder[], int i1, int i2, int inorder[], unordered_map<int, int> &table){
	if (i1 == i2) {
		*tree = nullptr;
		return;
	};
	// cout << p1 << ", "<< p2 << "\t" << i1 << ", " << i2 << endl;
	int val = preorder[p1];
	Node *node = new Node(val);
	buildTree(&node->left, p1+1, p1+1+table[val]-i1, preorder, i1, table[val], inorder, table);
	buildTree(&node->right, p1+1+table[val]-i1, p2, preorder, table[val]+1, i2, inorder, table);	
	*tree = node;
}

Node* buildTree(int p1, int p2, int preorder[], int i1, int i2, int inorder[], unordered_map<int, int> &table){
	if (i1 == i2) {
		return nullptr;
	};
	// cout << p1 << ", "<< p2 << "\t" << i1 << ", " << i2 << endl;
	int val = preorder[p1];
	Node *node  = new Node(val);
	node->left  = buildTree(p1+1, p1+1+table[val]-i1, preorder, i1, table[val], inorder, table);
	node->right = buildTree(p1+1+table[val]-i1, p2, preorder, table[val]+1, i2, inorder, table);	
	return node;
}


int main(){
	int n = 7;
	int preorder[] = {4, 2, 1, 3, 6, 5, 7};
	int inorder[]  = {1, 2, 3, 4, 5, 6, 7};
	unordered_map<int, int> table;
	for (int i = 0; i < n; i++){
		table[inorder[i]] = i;
	}
	// call 1
	Node* tree1 = buildTree(0, n, preorder, 0, n, inorder, table);
	// call 2
	Node* tree2;
	buildTree(&tree2, 0, n, preorder, 0, n, inorder, table);
	return 0;
}






/*
        4     
      /   \     
     2     6  
    / \   / \       
   1   3 5   7      

   preorder = [4, 2, 1, 3, 6, 5, 7]
   inorder  = [1, 2, 3, 4, 5, 6, 7]

           4     
         /   \     
   2, 1, 3    6, 5, 7
   1, 2, 3    5, 6, 7
      2          6
    /   \      /   \
   1     3    5     7
   1     3    5     7
*/