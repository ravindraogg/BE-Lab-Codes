PROGRAM 2
2. Simulate the following CPU scheduling algorithms to find turnaround time and waiting
time a) FCFS b) SJF c) Round Robin d) Priority


#include <stdio.h>
int a[10], b[10], no[10], wt[10], ta[10];
void main()
{
    int i, j, sb = 0, n, l, temp, c;
    float avgw, tw = 0, tt = 0, avgt;
    printf("Enter no of processes\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        no[i] = i;
        printf("Enter the Arrival time and Burst time for process %d\n", i);
        scanf("%d%d", &a[i], &b[i]);
    }
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (a[j] > a[j + 1])
            {
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
    l = a[0];
    for (i = 0; i < n; i++)
    {
        if (i == 0)
            sb = l;
        else
        {
            sb = sb + b[i - 1];
        }
        wt[i] = sb - a[i];
        ta[i] = wt[i] + b[i];
    }
    for (i = 0; i < n; i++)
    {
        tw = tw + wt[i];
        tt = tt + ta[i];
    }
    avgw = tw / n;
    avgt = tt / n;
    printf("\tProcess\t\tAT\t\tBT\t\tWT\t\tTAT\n");
    for (i = 0; i < n; i++)
    {
        printf("\tP%d\t\t%d\t\t%d\t\t%d\t\t%d\n", no[i], a[i], b[i], wt[i], ta[i]);
    }
    printf("\nAverage WT is %f\n", avgw);
    printf("\nAverage TAT is %f\n", avgt);
}
