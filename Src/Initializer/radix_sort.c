#include <stdio.h>
#include <stdint.h>

uint64_t getMax(uint64_t arr[], int n) { 
    uint64_t mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 
  
// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
void countSort(uint64_t arr[], int n, uint64_t exp) { 
    uint64_t output[n]; // output array 
    int i, count[2] = {0}; 
  
    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++) 
        count[ (arr[i]/exp)%2 ]++; 
  
    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 2; i++) 
        count[i] += count[i - 1]; 
  
    // Build the output array 
    for (i = n - 1; i >= 0; i--) { 
        output[count[ (arr[i]/exp)%2 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%2 ]--; 
    } 
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 
  
// The main function to that sorts arr[] of size n using  
// Radix Sort 
void radixsort(uint64_t arr[], int n) { 
    // Find the maximum number to know number of digits 
    uint64_t m = getMax(arr, n); 
  
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 0x010000 * 2i 
    // where i is current bit of the first byte 
    for (uint64_t exp = 0x010000; m/exp >= 1; exp *= 2) {
//		printf("exp = %llu\n", exp);
        countSort(arr, n, exp); 
	}
} 
  
// A utility function to print an array 
void print(uint64_t arr[], int n) { 
    for (int i = 0; i < n; i++) 
		printf("%llu ", arr[i]);
	printf("\n");
} 
  
//sort regarding the first rightmost byte 
int main() {
//we have
//0x201000, 0x200000, 0x0fffff, 0x5bc300 
//we want
//0x0fffff, 0x201000 , 0x200000, 0x5bc300

    uint64_t arr[] = {2101248, 2097152, 1048575, 6013696}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    print(arr, n); 
	printf("we want:\n1048575, 2101248, 2097152, 6013696\n");
    radixsort(arr, n); 
    print(arr, n); 
	return 0;
}
