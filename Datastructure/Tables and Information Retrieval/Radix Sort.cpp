// The idea of Radix Sort is to do digit by digit sort starting from least significant digit to most significant digit. 
// Radix sort uses counting sort as a subroutine to sort.
// Following is a simple implementation of Radix Sort. For simplicity, the value of d is assumed to be 10 (mod).
#include <iostream>
using namespace std;

int getMax(int arr[], int n){
	int mx = arr[0];
	for(int i=1; i<n; i++)
		if(arr[i] > mx)
			mx = arr[i];
	return mx;
}

void countSort(int arr[], int n, int exp){
	int output[n];
	int count[10] = {0};
	int i;

	// Store count of occurrences in count[] 
	for(i = 0; i < n; i++)
		count[(arr[i]/exp)%10]++;

	// Change count[i] so that count[i] now contains actual 
    // position of this digit in output[] 
	for(i = 1; i < 10; i++)
		count[i] += count[i-1];

	// Build the output array 
	for(i = n-1; i>=0; i--){
		output[count[(arr[i]/exp)%10]-1] = arr[i];
		count[(arr[i]/exp)%10]--;
	}

	// Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
}

void radixsort(int arr[], int n){
	int m = getMax(arr, n);
	for(int exp = 1; m/exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

void print(int arr[], int n){
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
}

int main(){
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
	int n = sizeof(arr)/sizeof(arr[0]);
	radixsort(arr, n);
	print(arr,n);
	return 0;
}