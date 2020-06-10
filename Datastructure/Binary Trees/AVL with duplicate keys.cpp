#include <stdio.h> 
#include <stdlib.h> 
 
struct node { 
	int key; 
	struct node* left; 
	struct node* right; 
	int height; 
	int count; 
}; 

int max(int a, int b)
{ 
	return (a > b) ? a : b; 
}

int height(struct node* N) 
{ 
	if (N == NULL) 
		return 0; 
	return N->height; 
} 

struct node* newNode(int key) 
{ 
	struct node* node = (struct node*)malloc(sizeof(struct node)); 
	node->key = key; 
	node->left = NULL; 
	node->right = NULL; 
	node->height = 1;
	node->count = 1; 
	return (node); 
} 

struct node* rightRotate(struct node* y) 
{ 
	struct node* x = y->left; 
	struct node* T2 = x->right; 
	// Perform rotation 
	x->right = y; 
	y->left = T2; 
	// Update heights 
	y->height = max(height(y->left), height(y->right)) + 1; 
	x->height = max(height(x->left), height(x->right)) + 1; 
	// Return new root 
	return x; 
} 

struct node* leftRotate(struct node* x) 
{ 
	struct node* y = x->right; 
	struct node* T2 = y->left; 
	// Perform rotation 
	y->left = x; 
	x->right = T2; 
	// Update heights 
	x->height = max(height(x->left), height(x->right)) + 1; 
	y->height = max(height(y->left), height(y->right)) + 1; 
	// Return new root 
	return y; 
} 

int getBalance(struct node* N) 
{ 
	if (N == NULL) 
		return 0; 
	return height(N->left) - height(N->right); 
} 

struct node* insert(struct node* node, int key) 
{ 
	if (node == NULL) 
		return (newNode(key)); 
	if (key == node->key) { 
		(node->count)++; 
		return node; 
	} 

	if (key < node->key) 
		node->left = insert(node->left, key); 
	else
		node->right = insert(node->right, key); 

	node->height = max(height(node->left), height(node->right)) + 1; 

	int balance = getBalance(node); 
	// If this node becomes unbalanced, then there are 4 cases 

	// Left Left Case 
	if (balance > 1 && key < node->left->key) 
		return rightRotate(node); 
	
	// Right Right Case 
	if (balance < -1 && key > node->right->key) 
		return leftRotate(node); 
	
	// Left Right Case 
	if (balance > 1 && key > node->left->key) { 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 
	
	// Right Left Case 
	if (balance < -1 && key < node->right->key) { 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 

	return node; 
} 

struct node* minValueNode(struct node* node) 
{ 
	struct node* current = node; 
	while (current->left != NULL) 
		current = current->left; 
	return current; 
} 

struct node* deleteNode(struct node* root, int key) 
{ 
	if (root == NULL) 
		return root; 
	if (key < root->key) 
		root->left = deleteNode(root->left, key); 
	else if (key > root->key) 
		root->right = deleteNode(root->right, key); 
	else { 
		if (root->count > 1) { 
			(root->count)--; 
			return root; 
		} 
		if ((root->left == NULL) || (root->right == NULL)) { 
			struct node* temp = root->left ? root->left : root->right; 
			if (temp == NULL) { 
				temp = root; 
				root = NULL; 
			} 
			else 
				*root = *temp; 
			free(temp); 
		} 
		else { 
			struct node* temp = minValueNode(root->right);  
			root->key = temp->key; 
			root->count = temp->count; 
			temp->count = 1; 
			root->right = deleteNode(root->right, temp->key); 
		} 
	} 

	if (root == NULL) 
		return root; 

	root->height = max(height(root->left), height(root->right)) + 1; 
	int balance = getBalance(root); 

	// Left Left Case 
	if (balance > 1 && getBalance(root->left) >= 0) 
		return rightRotate(root); 

	// Left Right Case 
	if (balance > 1 && getBalance(root->left) < 0) { 
		root->left = leftRotate(root->left); 
		return rightRotate(root); 
	} 

	// Right Right Case 
	if (balance < -1 && getBalance(root->right) <= 0) 
		return leftRotate(root); 

	// Right Left Case 
	if (balance < -1 && getBalance(root->right) > 0) { 
		root->right = rightRotate(root->right); 
		return leftRotate(root); 
	} 
	
	return root; 
} 

void preOrder(struct node* root) 
{ 
	if (root != NULL) { 
		printf("%d(%d) ", root->key, root->count); 
		preOrder(root->left); 
		preOrder(root->right); 
	} 
} 

int main() 
{ 
	struct node* root = NULL; 
	root = insert(root, 9); 
	root = insert(root, 5); 
	root = insert(root, 10); 
	root = insert(root, 5); 
	root = insert(root, 9); 
	root = insert(root, 7); 
	root = insert(root, 17); 

	printf("Pre order traversal of the constructed AVL tree is \n"); 
	preOrder(root); 

	root = deleteNode(root, 9); 

	printf("\nPre order traversal after deletion of 9 \n"); 
	preOrder(root); 

	return 0; 
} 
