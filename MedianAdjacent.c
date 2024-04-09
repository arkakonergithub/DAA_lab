#include <stdio.h>

// Function to swap two elements in an array
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//Partition
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
     int j;
    for (j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i + 1, high);
    return i + 1;
}

// Function to find the median position using quicksort partitioning
int findMedianPosition(int arr[], int low, int high, int targetPosition) {
    if (low <= high)
	{
        int partitionIndex = partition(arr, low, high);

        if (partitionIndex == targetPosition) 
            return partitionIndex;
         else if (partitionIndex < targetPosition) 
            return findMedianPosition(arr, partitionIndex + 1, high, targetPosition);
         else 
            return findMedianPosition(arr, low, partitionIndex - 1, targetPosition);
        
    }

    // This line should never be reached for a valid input
    return -1;
}

// Function to find and print adjacent elements of the median
void findAdjacentElements(int arr[], int size) {
    int medianPosition = size / 2; // Assuming array size is always even for simplicity

    int medianIndex = findMedianPosition(arr, 0, size - 1, medianPosition);

    printf("Median: %d\n", arr[medianIndex]);

    if (size % 2 == 0) {
        // If array size is even, print two adjacent elements
        printf("Adjacent Elements: %d and %d\n", arr[medianIndex - 1], arr[medianIndex + 1]);
    } else {
        // If array size is odd, print one adjacent element
        printf("Adjacent Element: %d\n", arr[medianIndex + 1]);
    }
}

int main() {
    int arr[] = {156,23,48,73};
    int size = sizeof(arr) / sizeof(arr[0]);

    findAdjacentElements(arr, size);

    return 0;
}
