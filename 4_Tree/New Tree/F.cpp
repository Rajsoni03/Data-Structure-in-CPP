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

void postorder(Node* root){
	if (root == nullptr) return;
	cout << root->val << ' ';
	postorder(root->left);
	postorder(root->right);
}

void postorderIterative(Node* root){
	stack<Node*> stk;
	stack<Node*> rev;
	Node* curr = root;
	
	while(!stk.empty() || curr){
		while(curr){
			stk.push(curr);
			rev.push(stk.top());
			curr = curr->right;
		}
		curr = stk.top()->left;
		stk.pop();
	}
	while(!rev.empty()){
		cout << rev.top()->val << ' ';
		rev.pop();
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

	postorderIterative(root);
	return 0;
}