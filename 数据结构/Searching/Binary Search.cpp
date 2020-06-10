#include <iostream>
using namespace std;

// Recursive implementation of Binary Search
int binarySearch1(int arr[], int l, int r, int x){
	if(r >= l){
		int mid = l + (r-l)/2;
		if(arr[mid] == x)
			return mid;
		if(arr[mid] > x)
			return binarySearch1(arr, l, mid-1, x);
		return binarySearch1(arr, mid+1, r, x);
	}
	return -1;
}

// Iterative implementation of Binary Search
int binarySearch2(int arr[], int l, int r, int x){
	while(l <= r){
		int m = l + (r-l)/2;
		if(arr[m] == x)
			return m;
		if(arr[m] < x)
			l = m+1;
		else
			r = m-1;
	}
	return -1;
}

int main(void) 
{ 
    int arr[] = { 2, 3, 4, 10, 40 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int x = 10; 
    int result = binarySearch1(arr, 0, n - 1, x); 
    (result == -1) ? printf("Element is not present"
                            " in array") 
                   : printf("Element is present at "
                            "index %d", 
                            result); 
    return 0; 
}