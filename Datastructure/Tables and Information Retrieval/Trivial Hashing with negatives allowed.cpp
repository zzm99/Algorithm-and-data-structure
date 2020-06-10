// Given a limited range array contains both positive and non-positive numbers, i.e., 
// elements are in the range from -MAX to +MAX. Our task is to search if some number is present in the array or not in O(1) time.

// Since range is limited, we can use index mapping (or trivial hashing). We use values as the index in a big array. 
// Therefore we can search and insert elements in O(1) time.

// How to handle negative numbers?
// The idea is to use a 2D array of size hash[MAX+1][2]

// Assign all the values of the hash matrix as 0.
// Traverse the given array:
//     If the element ele is non negative assign 
//         hash[ele][0] as 1.
//     Else take the absolute value of ele and 
//          assign hash[ele][1] as 1.

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

bool has[MAX+1][2];

bool search(int X){
	if(X >= 0){
		if(has[X][0] == 1) return true;
		else return false;
	}
	X = abs(X);
	if(has[X][1] == 1) return true;
	return false;
}

void insert(int a[], int n){
	for(int i=0; i<n; i++){
		if(a[i] >= 0)
			has[a[i]][0] = 1;
		else
			has[abs(a[i])][1] = 1;
	}
}

int main(){
	int a[] = {-1, 9, -5, -8, -5, -2};
	int n = sizeof(a)/sizeof(a[0]);
	insert(a, n);
	int X = -5;
	if(search(X) == true)
		cout << "Present";
	else
		cout << "Not Present";
	return 0;
}