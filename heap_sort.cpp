#include <iostream>
using namespace std;

// Function to heapify a subtree rooted with node i which is an index in array[]
void heapify(int array[], int n, int i) {
    int largest = i;          // Initialize largest as root
    int left = 2 * i + 1;     // left child index
    int right = 2 * i + 2;    // right child index

    // If left child is larger than root
    if (left < n && array[left] > array[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && array[right] > array[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(array[i], array[largest]);
        // Recursively heapify the affected subtree
        heapify(array, n, largest);
    }
}

// Main function to do heap sort
void heapSort(int array[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(array[0], array[i]);
        // call max heapify on the reduced heap
        heapify(array, i, 0);
    }
}

// Utility function to print array elements
void printArray(int array[], int n) {
    for (int i = 0; i < n; ++i)
        cout << array[i] << " ";
    cout << "\n";
}

int main() {
    int array[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(array) / sizeof(array[0]);

    cout << "Original array:\n";
    printArray(array, n);

    heapSort(array, n);

    cout << "Sorted array:\n";
    printArray(array, n);
    return 0;
}
