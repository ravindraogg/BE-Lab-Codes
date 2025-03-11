PROGRAM 2
2. Simulate the following CPU scheduling algorithms to find turnaround time and waiting
time a) FCFS b) SJF c) Round Robin d) Priority

#include <stdio.h>

int a[10], b[10], no[10], wt[10], ta[10]; 

void main() {
    int i, j, sb = 0, n, temp;
    float avgw = 0, tw = 0, tt = 0, avgt;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        no[i] = i + 1; 
        printf("Enter the Arrival time and Burst time for process %d: ", i + 1);
        scanf("%d%d", &a[i], &b[i]);
    }
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
                
                temp = no[j];
                no[j] = no[j + 1];
                no[j + 1] = temp;
            }
        }
    }
    
    wt[0] = 0; 
    
    for (i = 1; i < n; i++) {
        sb += b[i - 1]; 
        wt[i] = sb - a[i]; 
        
        if (wt[i] < 0) {
            wt[i] = 0;
            sb = a[i]; 
        }
    }
    
    for (i = 0; i < n; i++) {
        ta[i] = b[i] + wt[i];
    }
    
    for (i = 0; i < n; i++) {
        tw += wt[i];
        tt += ta[i];
    }
    
    avgw = tw / n; 
    avgt = tt / n; 
    
    printf("\n\tProcess\t\tAT\t\tBT\t\tWT\t\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("\tP%d\t\t%d\t\t%d\t\t%d\t\t%d\n", no[i], a[i], b[i], wt[i], ta[i]);
    }
    
    printf("\nAverage Waiting Time: %.2f", avgw);
    printf("\nAverage Turnaround Time: %.2f\n", avgt);
}
