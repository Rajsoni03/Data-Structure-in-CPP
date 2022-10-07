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

void addNodeBST(Node* &root, int val){
	if (root == nullptr)
		root = new Node(val);	
	else if (root->val > val)
		addNodeBST(root->left, val);
	else
		addNodeBST(root->right, val);
}

void preorder(Node* root){
	if (root == nullptr) return;
	cout << root->val << ' ';
	preorder(root->left);
	preorder(root->right);
}

void preorderIterative(Node* root){
	stack<Node*> st;
	st.push(root);
	while(!st.empty()){
		Node *n = st.top();
		st.pop();		
		cout << n->val << ' ';
		if (n->right) st.push(n->right);
		if (n->left) st.push(n->left);
	}
}


int main(){
	Node *root = nullptr;
	addNodeBST(root, 5);
	addNodeBST(root, 3);
	addNodeBST(root, 4);
	addNodeBST(root, 2);
	addNodeBST(root, 7);
	addNodeBST(root, 6);
	addNodeBST(root, 8);

	preorderIterative(root);
	return 0;
}