// Flatten Binary Tree to Linked List

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

void preorder(Node *n){
	if (!n) return;
	cout << n->val << ' ';
	if (n->left) preorder(n->left);
	if (n->right) preorder(n->right);
}

void tree2list(Node* root){
	stack<Node*> s;
    Node* n = root;
    if (n->right) s.push(n);
    while(!s.empty() && n){
        while(n->left){             
            cout << n->val << endl;
            if (n->right) s.push(n);                    
            n->right = n->left;
            n->left = nullptr;
            n = n->right;
        }
        cout << "stack : " << s.top()->val <<  n->val << endl;
        n->right = s.top();
        s.pop();
        n = n->right;
    }
}

/*
	  1               1    
    /   \              \
   2	 5     -->      2
  / \     \              \
 3   4     6              3
                           \
                            4
                             \
                              5
                               \
                                6
*/
int main(){
	Node *n3 = new Node(3);
	Node *n4 = new Node(4);
	Node *n2 = new Node(2, n3, n4);

	Node *n6 = new Node(6);
	Node *n5 = new Node(5, nullptr, n6);

	Node *n1 = new Node(1, n2, n5);
	
	tree2list(n1);
	// preorder(n1);
}