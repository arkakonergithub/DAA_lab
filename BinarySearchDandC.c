#include <stdio.h>
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        if (arr[mid] == x)
            return mid;

        // If the element is smaller than the middle element,
        // it can only be present in the left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else, the element can only be present in the right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
// Element is not present in the array
    return -1;
}
int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 11;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        printf("Element not present in the array\n");
    else
        printf("Element found at index %d\n", result);
    return 0;
}