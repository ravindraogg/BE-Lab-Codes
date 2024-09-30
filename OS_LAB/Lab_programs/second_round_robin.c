#include<stdio.h>

int main() {
    int n, time_slot, total = 0, x, counter = 0;
    int wait_time = 0, ta_time = 0;

    // Input number of processes
    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);
    
    int arr_time[n], burst_time[n], temp_burst_time[n];
    x = n; // Number of processes left

    // Input process details
    for(int i = 0; i < n; i++) {
        printf("Enter Details of Process %d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &arr_time[i]);
        printf("Burst Time: ");
        scanf("%d", &burst_time[i]);
        temp_burst_time[i] = burst_time[i]; // Store burst time in a temp array
    }

    // Input time quantum
    printf("Enter Time Quantum: ");
    scanf("%d", &time_slot);

    printf("\nProcess ID  Burst Time  Turnaround Time  Waiting Time\n");

    // Round Robin Scheduling Algorithm
    for(int i = 0; x != 0; ) {
        if(temp_burst_time[i] <= time_slot && temp_burst_time[i] > 0) {
            total += temp_burst_time[i];
            temp_burst_time[i] = 0;
            counter = 1;
        } else if(temp_burst_time[i] > 0) {
            temp_burst_time[i] -= time_slot;
            total += time_slot;
        }

        if(temp_burst_time[i] == 0 && counter == 1) {
            x--; // Process completed
            printf("Process No %d    %d             %d                %d\n", i + 1, burst_time[i],
                   total - arr_time[i], total - arr_time[i] - burst_time[i]);

            wait_time += total - arr_time[i] - burst_time[i];
            ta_time += total - arr_time[i];
            counter = 0;
        }

        // Move to next process
        if(i == n - 1)
            i = 0;
        else if(arr_time[i + 1] <= total)
            i++;
        else
            i = 0;
    }

    // Calculate and display averages
    float avg_wait_time = (float)wait_time / n;
    float avg_turnaround_time = (float)ta_time / n;
    printf("\nAverage Waiting Time: %.2f", avg_wait_time);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}
