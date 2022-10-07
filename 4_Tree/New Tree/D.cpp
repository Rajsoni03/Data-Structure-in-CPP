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

void inorder(Node* root){
	if (root == nullptr) return;
	inorder(root->left);
	cout << root->val << ' ';
	inorder(root->right);
}

void inorderIterative(Node* root){
	stack<Node*> st;
	Node *curr = root;
	while(!st.empty() || curr){
		while(curr){
			st.push(curr);
			curr = curr->left;
		}
		cout << st.top()->val << ' ';
		curr = st.top()->right;
		st.pop();
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

	inorderIterative(root);
	return 0;
}