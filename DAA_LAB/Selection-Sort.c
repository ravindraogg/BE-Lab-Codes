#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int arr[], int n) {
    int i, j, min_index;
    for (i = 0; i < n - 1; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main() {
    int i, n;
    clock_t start, stop;
    double duration;

    srand(time(NULL));  // Correct seeding for randomness

    printf("\nEnter n: ");
    scanf("%d", &n);

    int a[n]; // Declare the array dynamically

    for (i = 0; i < n; i++) {
        a[i] = rand(); // Assign random values
    }
    
    start = clock();
    selection_sort(a, n);
    stop = clock();

    duration = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("\nDuration = %lf seconds\n", duration);

    return 0;
}
