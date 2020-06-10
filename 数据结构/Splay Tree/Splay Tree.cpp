// The important thing to note is, the search or splay operation not only brings the searched key to root, but also balances the BST.

#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int key;
	node *left, *right;
	node(int key){
		this->key = key;
		this->left = this->right = NULL;
	}
};

node* rightRotate(node* x){
	node* y = x->left;
	x->left = y->right;
	y->right = x;
	return y;
}

node* leftRotate(node* x){
	node* y = x->right;
	x->right = y->left;
	y->left = x;
	return y;
}

node* splay(node* root, int key){
	if(root==NULL || root->key == key){
		return root;
	}
	if(root->key > key){
		if(root->left == NULL) return root;
		if(root->left->key > key){
			root->left->left = splay(root->left->left, key);
			root = rightRotate(root);
		}
		else if(root->left->key < key){
			root->left->right = splay(root->left->right, key);
			if(root->left->right != NULL)
				root->left = leftRotate(root->left);
		}
		return (root->left == NULL) ? root: rightRotate(root);
	}
	else{
		if(root->right == NULL) return root;
		if(root->right->key > key){
			root->right->left = splay(root->right->left, key);
			if(root->right->left != NULL)
				root->right = rightRotate(root->right);
		}
		else if(root->right->key < key){
			root->right->right = splay(root->right->right, key);
			root = rightRotate(root);
		}
		return (root->right == NULL) ? root: leftRotate(root);
	}
}

node* search(node* root, int key){
	return splay(root, key);
}

node* insert(node* root, int k){
	if(root == NULL) return new node(k);
	// Bring the closest leaf node to root
	root = splay(root, k);
	if(root->key == k) return root;
	node* newnode = new node(k);
	if(root->key > k){
		newnode->right = root;
		newnode->left = root->left;
		root->left = NULL;
	}
	else{
		newnode->left = root;
		newnode->right = root->right;
		root->right = NULL;
	}
	return newnode;
}

void preOrder(node* root){
	if(root != NULL){
		cout << root->key << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main()
{
    node *root = new node(100);
    root->left = new node(50);
    root->right = new node(200);
    root->left->left = new node(40);
    root->left->left->left = new node(30);
    root->left->left->left->left = new node(20);

    root = insert(root, 25);  
    cout << "Preorder traversal of the modified Splay tree is \n";
    preOrder(root);
    return 0;
}
