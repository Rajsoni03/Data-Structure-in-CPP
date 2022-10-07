// Binary Search Tree (BST)
#include <iostream>
using namespace std;

struct TreeNode{
	int data;	
	TreeNode* left;
	TreeNode* right;
	TreeNode(int data, TreeNode* left=nullptr, TreeNode* right = nullptr){
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

void insert(TreeNode* &root, int data){
	if (root == nullptr)
		root = new TreeNode(data);
	else if (data <= root->data)
		insert(root->left, data);
	else 
		insert(root->right, data);	
}

void inorder(TreeNode* root){
	if (root==nullptr) return;
	if (root->left) inorder(root->left);
	cout << root->data << ' ';
	if (root->right) inorder(root->right);
}

int main(){
	TreeNode* root = nullptr;
	insert(root, 8);
	insert(root, 1);
	insert(root, 2);
	insert(root, 1);
	insert(root, 3);
	insert(root, 0);

	inorder(root);

	return 0;
}