// Given an n x n square matrix, find sum of all sub-squares of size k x k where k is smaller than or equal to n.
// Examples :

// Input:
// n = 5, k = 3
// arr[][] = { {1, 1, 1, 1, 1},
//             {2, 2, 2, 2, 2},
//             {3, 3, 3, 3, 3},
//             {4, 4, 4, 4, 4},
//             {5, 5, 5, 5, 5},
//          };
// Output:
//        18  18  18
//        27  27  27
//        36  36  36


// Input:
// n = 3, k = 2
// arr[][] = { {1, 2, 3},
//             {4, 5, 6},
//             {7, 8, 9},
//          };
// Output:
//        12  16
//        24  28

// A simple C++ program to find sum of all subsquares of size k x k 
#include <iostream> 
using namespace std; 
#define n 5 
void printSumSimple(int mat[][n], int k) 
{ 
    if (k > n) return; 
    for (int i=0; i<n-k+1; i++) 
    { 
      for (int j=0; j<n-k+1; j++) 
      { 
        int sum = 0; 
        for (int p=i; p<k+i; p++) 
          for (int q=j; q<k+j; q++) 
            sum += mat[p][q]; 
        cout << sum << " "; 
      } 
      cout << endl; 
    } 
} 

int main() 
{ 
  int mat[n][n] = {{1, 1, 1, 1, 1}, 
          {2, 2, 2, 2, 2}, 
          {3, 3, 3, 3, 3}, 
          {4, 4, 4, 4, 4}, 
          {5, 5, 5, 5, 5}, 
          }; 
  int k = 3; 
  printSumSimple(mat, k); 
  return 0; 
} 

//////////////////////////////////////

// An efficient C++ program to find sum of all subsquares of size k x k 
#include <iostream> 
using namespace std; 

// Size of given matrix 
#define n 5 

// A O(n^2) function to find sum of all sub-squares of size k x k 
// in a given square matrix of size n x n 
void printSumTricky(int mat[][n], int k) 
{ 
    if (k > n) return; 
    int stripSum[n][n]; 
    for (int j=0; j<n; j++) 
    { 
      int sum = 0; 
      for (int i=0; i<k; i++) 
        sum += mat[i][j]; 
      stripSum[0][j] = sum; 
      for (int i=1; i<n-k+1; i++) 
      { 
          sum += (mat[i+k-1][j] - mat[i-1][j]); 
          stripSum[i][j] = sum; 
      } 
    } 

    for (int i=0; i<n-k+1; i++) 
    { 
      int sum = 0; 
      for (int j = 0; j<k; j++) 
        sum += stripSum[i][j]; 
      cout << sum << " "; 
      for (int j=1; j<n-k+1; j++) 
      { 
        sum += (stripSum[i][j+k-1] - stripSum[i][j-1]); 
        cout << sum << " "; 
      } 
      cout << endl; 
    } 
} 

int main() 
{ 
  int mat[n][n] = {{1, 1, 1, 1, 1}, 
          {2, 2, 2, 2, 2}, 
          {3, 3, 3, 3, 3}, 
          {4, 4, 4, 4, 4}, 
          {5, 5, 5, 5, 5}, 
          }; 
  int k = 3; 
  printSumTricky(mat, k); 
  return 0; 
} 
