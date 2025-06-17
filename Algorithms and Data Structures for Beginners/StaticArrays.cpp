#include <iostream>

// Insert n into arr at the next open position.
// Length is the number of 'real' values in arr, and capacity
// is the size (aka memory allocated for the fixed size array).
void insertEnd(int arr[], int n, int length, int capacity) {
	if (length < capacity) {
		arr[length] = n; // Insert at the end
	}
}

// Remove from the last position in the array if the array
// is not empty (i.e. length is non-zero).
void removeEnd(int arr[], int length) {
	if (length > 0) {
		// Overwrite last element with some default value.
        // We would also consider the length to be decreased by 1.
		arr[length - 1] = 0;
	}
}

// Insert n into index i after shifting elements to the right.
// Assuming i is a valid index and arr is not full.
// 5 7 8 9 10 x
// 5 6 7 8 9 10
void insertMiddle(int arr[], int i, int n, int length) {
	for (int idx = length - 1; idx >= i; --idx) {
		arr[idx + 1] = arr[idx];
	}
	arr[i] = n;
}

// Remove value at index i before shifting elements to the left.
// Assuming i is a valid index.
void removeMiddle(int arr[], int i, int length) {
	for (int idx = i; idx < length; ++idx) {
		arr[idx - 1] = arr[idx];
	}
}

void printArr(int arr[], int capacity) {
	for (int i = 0; i < capacity; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	
	return 0;
}
