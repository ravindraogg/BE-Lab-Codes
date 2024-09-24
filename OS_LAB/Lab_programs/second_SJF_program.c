ii. SJF SCHEDULING ALGORITHM:
SJF scheduling algorithm, read the number of processes/jobs in the system, their CPU burst
times. Arrange all the jobs in order with respect to their burst times. There may be two jobs
in queue with the same execution time, and then FCFS approach is to be performed. Each
process will be executed according to the length of its burst time. Then calculate the waiting
time and turnaround time of each of the processes accordingly.



#include <stdio.h>
int main()
{
    int time, burst_time[10], at[10], sum_burst_time = 0, smallest, n, i;
    int sumt = 0, sumw = 0;
    printf("enter the no of processes : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("the arrival time for process P%d : ", i + 1);
        scanf("%d", &at[i]);
        printf("the burst time for process P%d : ", i + 1);
        scanf("%d", &burst_time[i]);
        sum_burst_time += burst_time[i];
    }
    burst_time[9] = 9999;
    for (time = 0; time < sum_burst_time;)
    {
        smallest = 9;
        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && burst_time[i] > 0 && burst_time[i] < burst_time[smallest])
                smallest = i;
        }
        printf("P[%d]\t|\t%d\t|\t%d\n", smallest + 1, time + burst_time[smallest] - at[smallest], time - at[smallest]);
        sumt += time + burst_time[smallest] - at[smallest];
        sumw += time - at[smallest];
        time += burst_time[smallest];
        burst_time[smallest] = 0;
    }
    printf("\n\n average waiting time = %f", sumw * 1.0 / n);
    printf("\n\n average turnaround time = %f", sumt * 1.0 / n);
    return 0;
}
