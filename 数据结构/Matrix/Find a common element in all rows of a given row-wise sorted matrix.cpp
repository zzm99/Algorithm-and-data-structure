// Given a matrix where every row is sorted in increasing order. Write a function that finds and returns a common element in all rows. If there is no common element, then returns -1.
// Example:

// Input: mat[4][5] = { {1, 2, 3, 4, 5},
//                     {2, 4, 5, 8, 10},
//                     {3, 5, 7, 9, 11},
//                     {1, 3, 5, 7, 9},
//                   };
// Output: 5

// A O(m*n*n) simple solution is to take every element of first row and search it in all other rows, till we find a common element.
// Time complexity of this solution is O(m*n*n) where m is number of rows and n is number of columns in given matrix.
// This can be improved to O(m*n*Logn) if we use Binary Search instead of linear search.

// We can solve this problem in O(mn) time using the approach similar to merge of Merge Sort.
// The idea is to start from the last column of every row. If elements at all last columns are same,
// then we found the common element. Otherwise we find the minimum of all last columns.
// Once we find a minimum element, we know that all other elements in last columns cannot be a common element,
// so we reduce last column index for all rows except for the row which has minimum value.
// We keep repeating these steps till either all elements at current last column don’t become same,
// or a last column index reaches 0.

// A C++ program to find a common element in all rows of a 
// row wise sorted array 
#include <bits/stdc++.h> 
using namespace std; 
#define M 4 
#define N 5 

int findCommon(int mat[M][N]) 
{ 
	int column[M]; 
	int min_row; 
	int i; 
	for (i = 0; i < M; i++) 
		column[i] = N - 1; 
	min_row = 0; 
	while (column[min_row] >= 0) { 
		for (i = 0; i < M; i++) { 
			if (mat[i][column[i]] < mat[min_row][column[min_row]]) 
				min_row = i; 
		} 
		int eq_count = 0; 
		for (i = 0; i < M; i++) { 
			if (mat[i][column[i]] > mat[min_row][column[min_row]]) { 
				if (column[i] == 0) 
					return -1; 
				column[i] -= 1;  
			} 
			else
				eq_count++; 
		} 
		if (eq_count == M) 
			return mat[min_row][column[min_row]]; 
	} 
	return -1; 
} 

int main() 
{ 
	int mat[M][N] = { 
		{ 1, 2, 3, 4, 5 }, 
		{ 2, 4, 5, 8, 10 }, 
		{ 3, 5, 7, 9, 11 }, 
		{ 1, 3, 5, 7, 9 }, 
	}; 
	int result = findCommon(mat); 
	if (result == -1) 
		cout << "No common element"; 
	else
		cout << "Common element is " << result; 
	return 0; 
} 


// A Hashing Based Solution
// We can also use hashing. This solution works even if the rows are not sorted. It can be used to print all common elements.

#include <bits/stdc++.h> 
using namespace std; 
#define M 4 
#define N 5 

int findCommon(int mat[M][N]) 
{ 
	unordered_map<int, int> cnt; 
	int i, j; 
	for (i = 0; i < M; i++) { 
		cnt[mat[i][0]]++; 
		for (j = 1; j < N; j++) { 
			if (mat[i][j] != mat[i][j - 1])  // sorted的情况
				cnt[mat[i][j]]++; 
		} 
	} 
	for (auto ele : cnt) { 
		if (ele.second == M) 
			return ele.first; 
	} 
	return -1; 
} 

int main() 
{ 
	int mat[M][N] = { 
		{ 1, 2, 3, 4, 5 }, 
		{ 2, 4, 5, 8, 10 }, 
		{ 3, 5, 7, 9, 11 }, 
		{ 1, 3, 5, 7, 9 }, 
	}; 
	int result = findCommon(mat); 
	if (result == -1) 
		cout << "No common element"; 
	else
		cout << "Common element is " << result; 
	return 0; 
} 
