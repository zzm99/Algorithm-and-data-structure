// Given a binary matrix, print all unique rows of the given matrix.
// Example:

// Input:
//     {0, 1, 0, 0, 1}
//         {1, 0, 1, 1, 0}
//         {0, 1, 0, 0, 1}
//         {1, 1, 1, 0, 0}
// Output:
//     0 1 0 0 1 
//     1 0 1 1 0 
//     1 1 1 0 0 

// Method 1 (Simple)
// Method 2 (Use Binary Search Tree)
// Method 3 (Use Trie data structure)
// Since the matrix is boolean, a variant of Trie data structure can be used where each node will be having two children one for 0 and other for 1. Insert each row in the Trie. If the row is already there, don’t print the row. If row is not there in Trie, insert it in Trie and print it.
// Method 4 (Use HashSet data structure)
// In this method convert the whole row into a single String and then check it is already present in HashSet or not. If row is present then we will leave it otherwise we will print unique row and add it to HashSet.

// Method3:
#include <bits/stdc++.h>
using namespace std;

int mat[][10] = {{0, 1, 0, 0, 1},
		        {1, 0, 1, 1, 0},
		        {0, 1, 0, 0, 1},
		        {1, 1, 1, 0, 0}};

struct Trie
{
	Trie* child[2];
	bool isend;
	Trie() {
		this->isend = false;
		for(int i=0;i<2;i++)
			this->child[i] = NULL;
	}
};

void print(int arr[],int m) {
	for(int i=0;i<m;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void insert(Trie* &root,int arr[],int m) {
	Trie* curr = root;
	bool fg=0;
	for(int i=0;i<m;i++) {
		if(!curr->child[arr[i]]){
			curr->child[arr[i]] = new Trie();
			fg=1;
		}
		curr = curr->child[arr[i]];
	}
	curr->isend = true;
	if(fg)
		print(arr,m);
}

int main() {
	int n = 4,m=5;
	Trie* root = new Trie();
	for(int i=0;i<n;i++) {
		insert(root,mat[i],m);
	}
}


// Method4:
#include<bits/stdc++.h> 
using namespace std; 

void printArray(int arr[][5], int row, int col) 
{ 
	unordered_set<string> uset; 
	
	for(int i = 0; i < row; i++) 
	{ 
		string s = ""; 
		
		for(int j = 0; j < col; j++) 
			s += to_string(arr[i][j]); 
		
		if(uset.count(s) == 0) 
		{ 
			uset.insert(s); 
			cout << s << endl; 
		} 
	} 
} 

int main() 
{ 
	int arr[][5] = {{0, 1, 0, 0, 1}, 
					{1, 0, 1, 1, 0}, 
					{0, 1, 0, 0, 1}, 
					{1, 1, 1, 0, 0}}; 
	
	printArray(arr, 4, 5); 
} 
