

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a job
struct Job {
    char id;     // Job ID
    int deadline; // Deadline of job
    int profit;   // Profit of job
};

// Function to compare two jobs based on profit (used in qsort)
int compare(const void* a, const void* b) {
    return ((struct Job*)b)->profit - ((struct Job*)a)->profit;
}

// Function to find the maximum deadline
int findMaxDeadline(struct Job jobs[], int n) {
    int max_deadline = 0;int i;
    for ( i = 0; i < n; i++) {
        if (jobs[i].deadline > max_deadline) {
            max_deadline = jobs[i].deadline;
        }
    }
    return max_deadline;
}

// Function to schedule jobs to get maximum profit and display sequence and profit
void jobSequencing(struct Job jobs[], int n) {
	int i,j;
    // Sort jobs based on profit in non-increasing order
    qsort(jobs, n, sizeof(jobs[0]), compare);

    // Find the maximum deadline among all jobs
    int maxDeadline = findMaxDeadline(jobs, n);

    // Array to keep track of whether a deadline is occupied or not
    char *slots = (char*)malloc(maxDeadline * sizeof(char));
    for (i = 0; i < maxDeadline; i++) {
        slots[i] = 0; // Initialize all slots as empty
    }

    // Array to store the sequence of jobs
    char *sequence = (char*)malloc(maxDeadline * sizeof(char));

    int totalProfit = 0; // Variable to store the total profit

    // Iterate through all jobs
    for (i = 0; i < n; i++) {
        // Find a suitable slot for this job
        for (j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slots[j] == 0) {
                sequence[j] = jobs[i].id;
                slots[j] = 1; // Mark this slot as occupied
                totalProfit += jobs[i].profit; // Add profit of this job to total profit
                break;
            }
        }
    }

    // Print the sequence of jobs
    printf("Sequence of jobs with maximum profit: ");
    for (i = 0; i < maxDeadline; i++) {
        if (slots[i]) {
            printf("%c ", sequence[i]);
        }
    }
    printf("\nMaximum profit total value: %d\n", totalProfit);

    // Free dynamically allocated memory
    free(slots);
    free(sequence);
}

int main() {
    // Example jobs
    struct Job jobs[] = {
        {'A', 3, 200},
        {'B', 1, 800},
        {'C', 3, 400},
        {'D', 2, 350}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobSequencing(jobs, n);

    return 0;
}
