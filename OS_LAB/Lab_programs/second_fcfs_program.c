PROGRAM 2
2. Simulate the following CPU scheduling algorithms to find turnaround time and waiting
time a) FCFS b) SJF c) Round Robin d) Priority


#include <stdio.h>

int a[10], b[10], no[10], wt[10], ta[10]; // AT, BT, process no, WT, TAT

void main() {
    int i, j, sb = 0, n, temp;
    float avgw = 0, tw = 0, tt = 0, avgt;
    
    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    // Input arrival time and burst time for each process
    for (i = 0; i < n; i++) {
        no[i] = i + 1; // process numbering starts from 1
        printf("Enter the Arrival time and Burst time for process %d: ", i + 1);
        scanf("%d%d", &a[i], &b[i]);
    }
    
    // Bubble Sort processes by arrival time (AT)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                // Swap arrival time
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                
                // Swap burst time
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
                
                // Swap process number
                temp = no[j];
                no[j] = no[j + 1];
                no[j + 1] = temp;
            }
        }
    }
    
    // Calculate Waiting Time (WT) and Turnaround Time (TAT)
    wt[0] = 0; // First process has no waiting time
    
    for (i = 1; i < n; i++) {
        // Waiting time is the total burst time up to this process - its arrival time
        sb += b[i - 1]; // start burst time is the accumulated burst time
        wt[i] = sb - a[i]; // wait time = start burst - arrival time
        
        // Ensure no negative wait time (process arrives after burst)
        if (wt[i] < 0) {
            wt[i] = 0;
            sb = a[i]; // next process starts when it arrives
        }
    }
    
    // Turnaround Time = Burst Time + Waiting Time
    for (i = 0; i < n; i++) {
        ta[i] = b[i] + wt[i];
    }
    
    // Calculate total waiting time and total turnaround time
    for (i = 0; i < n; i++) {
        tw += wt[i];
        tt += ta[i];
    }
    
    avgw = tw / n; // Average Waiting Time
    avgt = tt / n; // Average Turnaround Time
    
    // Display the process details
    printf("\n\tProcess\t\tAT\t\tBT\t\tWT\t\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("\tP%d\t\t%d\t\t%d\t\t%d\t\t%d\n", no[i], a[i], b[i], wt[i], ta[i]);
    }
    
    printf("\nAverage Waiting Time: %.2f", avgw);
    printf("\nAverage Turnaround Time: %.2f\n", avgt);
}
