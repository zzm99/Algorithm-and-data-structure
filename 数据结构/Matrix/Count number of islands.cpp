// Count number of islands where every island is row-wise and column-wise separated
// Given a rectangular matrix which has only two possible values ‘X’ and ‘O’. The values ‘X’ always appear in form of rectangular islands and these islands are always row-wise and column-wise separated by at least one line of ‘O’s. Note that islands can only be diagonally adjacent. Count the number of islands in the given matrix.

// Examples:

// mat[M][N] =  {{'O', 'O', 'O'},
//               {'X', 'X', 'O'},
//               {'X', 'X', 'O'},
//               {'O', 'O', 'X'},
//               {'O', 'O', 'X'},
//               {'X', 'X', 'O'}
//              };
// Output: Number of islands is 3

// mat[M][N] =  {{'X', 'O', 'O', 'O', 'O', 'O'},
//               {'X', 'O', 'X', 'X', 'X', 'X'},
//               {'O', 'O', 'O', 'O', 'O', 'O'},
//               {'X', 'X', 'X', 'O', 'X', 'X'},
//               {'X', 'X', 'X', 'O', 'X', 'X'},
//               {'O', 'O', 'O', 'O', 'X', 'X'},
//              };
// Output: Number of islands is 4

// A C++ program to count the number of rectangular 
// islands where every island is separated by a line 
#include<iostream> 
using namespace std; 

// Size of given matrix is M X N 
#define M 6 
#define N 3 

// This function takes a matrix of 'X' and 'O' 
// and returns the number of rectangular islands 
// of 'X' where no two islands are row-wise or 
// column-wise adjacent, the islands may be diagonaly 
// adjacent 
int countIslands(int mat[][N]) 
{ 
  int count = 0; // Initialize result 

  // Traverse the input matrix 
  for (int i=0; i<M; i++) 
  { 
    for (int j=0; j<N; j++) 
    { 
      // If current cell is 'X', then check 
      // whether this is top-leftmost of a 
      // rectangle. If yes, then increment count 
      if (mat[i][j] == 'X') 
      { 
        if ((i == 0 || mat[i-1][j] == 'O') && 
          (j == 0 || mat[i][j-1] == 'O')) 
          count++; 
      } 
    } 
  } 

  return count; 
} 

// Driver program to test above function 
int main() 
{ 
  int mat[M][N] = {{'O', 'O', 'O'}, 
          {'X', 'X', 'O'}, 
          {'X', 'X', 'O'}, 
          {'O', 'O', 'X'}, 
          {'O', 'O', 'X'}, 
          {'X', 'X', 'O'} 
          }; 
  cout << "Number of rectangular islands is " << countIslands(mat); 
  return 0; 
}
