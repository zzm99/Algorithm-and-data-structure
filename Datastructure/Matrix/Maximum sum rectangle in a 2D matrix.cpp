// Given a matrix, your aim is to find the maximum sum among all axb sub matrices of the matrix. The rows and columns of the submatrix must be contiguous. For example:
// 1 2 3 9
// 4 5 6 2
// 8 3 2 6
// Let us solve for a = 3 and b = 2.
// The first 3x2 submatrix is:
// 1 2
// 4 5
// 8 3
// The sum of elements in this is 23.
// The second 3x2 submatrix is:
// 2 3
// 5 6
// 3 2
// The sum of elements in this is 21.
// The third 3x2 submatrix is:
// 3 9
// 6 2
// 2 6
// The sum of elements in this is 28.
// The maximum among these is 28.
/*
	Author: HitmanM3nace
	@ayusofayush
	Tc: O(Q*N*M)
	Max Sum submatrix queries
	created: 19 June 2019
*/
// ;;;Hitman;;;
#include<bits/stdc++.h>
#define ll long long
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fr(i,n) for(int i=0;i<n;i++)
using namespace std;

int mat[101][101];
int sm[110][110];   // 2D dp array
int n,m,q;

int main()
{	
	fast
	int t;cin>>t;
	while(t--) {
	    cin>>n>>m;
	    fr(i,n) fr(j,m) cin>>mat[i][j];
	    memset(sm,0,sizeof sm);
	    sm[0][0] = mat[0][0];
	    for(int i=1;i<n;i++) {
	        sm[i][0] = sm[i-1][0]+mat[i][0];
	    }
	    for(int j=1;j<m;j++) {
	        sm[0][j] = sm[0][j-1]+mat[0][j];
	    }
	    for(int i=1;i<n;i++) {
	        for(int j=1;j<m;j++) {
	            sm[i][j] = sm[i-1][j]+sm[i][j-1]+mat[i][j]-sm[i-1][j-1];
	        }
	    }
	    
	    cin>>q;int a,b;
	    while(q--) {
	        cin>>a>>b;
	        
	        int mx=INT_MIN,temp=0;
	        for(int i=0;i<n-a+1;i++) {
	            for(int j=0;j<m-b+1;j++) {
	            	
	                temp = sm[i+a-1][j+b-1];
	                if(j-1>=0)
	                    temp -= sm[i+a-1][j-1];
	                if(i-1>=0) 
	                	temp -= sm[i-1][j+b-1];
	                if(i-1>=0 && j-1>=0) 
	                	temp += sm[i-1][j-1];
	                mx = max(mx,temp);
	            }
	        }
	        cout<<mx<<" ";
	    }
	    cout<<endl;
	}
	
	return 0;
}