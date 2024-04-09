#include <stdio.h>

typedef struct {
    int min_first;
    int min_second;
    int max_first;
    int max_second;
} Extremes;

Extremes find_extremes(int arr[], int start, int end) {
    Extremes result;

    if (end == start) {
        result.min_first = arr[start];
        result.min_second = arr[start];
        result.max_first = arr[start];
        result.max_second = arr[start];
    } else if (end == start + 1) {
        if (arr[start] < arr[end]) {
            result.min_first = arr[start];
            result.min_second = arr[end];
            result.max_first = arr[end];
            result.max_second = arr[start];
        } else {
            result.min_first = arr[end];
            result.min_second = arr[start];
            result.max_first = arr[start];
            result.max_second = arr[end];
        }
    } else {
        int mid = (start + end) / 2;

        Extremes left_extremes = find_extremes(arr, start, mid);
        Extremes right_extremes = find_extremes(arr, mid + 1, end);

        if (left_extremes.min_first < right_extremes.min_first) {
            result.min_first = left_extremes.min_first;
            result.min_second = (right_extremes.min_first < left_extremes.min_second) ? right_extremes.min_first : left_extremes.min_second;
        } else {
            result.min_first = right_extremes.min_first;
            result.min_second = (left_extremes.min_first < right_extremes.min_second) ? left_extremes.min_first : right_extremes.min_second;
        }

        if (left_extremes.max_first > right_extremes.max_first) {
            result.max_first = left_extremes.max_first;
            result.max_second = (right_extremes.max_first > left_extremes.max_second) ? right_extremes.max_first : left_extremes.max_second;
        } else {
            result.max_first = right_extremes.max_first;
            result.max_second = (left_extremes.max_first > right_extremes.max_second) ? left_extremes.max_first : right_extremes.max_second;
        }
    }

    return result;
}


int main() {
    int arr[] = {130,156,142,189};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;
    
    printf("Elements-\n");
    for(i=0;i<n;i++)
    {printf("%d ",arr[i]);
	}

    Extremes result = find_extremes(arr, 0, n - 1);

    //printf("\nMinimum: %d\n", result.min_first);
    printf("\nSecond Minimum: %d\n", result.min_second);
    //printf("Maximum: %d\n", result.max_first);
    printf("Second Maximum: %d\n", result.max_second);

    return 0;
}
