#include<stdio.h>

struct process {
    char process_name;
    int arr_time, bst_time, ct, waiting_time, turn_around_time, priority;
    int status;
} process_queue[10];

int limit;

void Arr_time_Sorting() {
    struct process temp;
    int i, j;
    for(i = 0; i < limit - 1; i++) {
        for(j = i + 1; j < limit; j++) {
            if(process_queue[i].arr_time > process_queue[j].arr_time) {
                temp = process_queue[i];
                process_queue[i] = process_queue[j];
                process_queue[j] = temp;
            }
        }
    }
}

void main() {
    int i, time = 0, bst_time = 0, largest;
    char c;
    float wait_time = 0, turn_around_time = 0, average_waiting_time, average_turn_around_time;
    
    printf("\nEnter Total Number of Processes:\t");
    scanf("%d", &limit);
    
    for(i = 0, c = 'A'; i < limit; i++, c++) {
        process_queue[i].process_name = c;
        printf("\nEnter Details For Process[%C]:\n", process_queue[i].process_name);
        printf("Enter Arrival Time:\t");
        scanf("%d", &process_queue[i].arr_time);
        printf("Enter Burst Time:\t");
        scanf("%d", &process_queue[i].bst_time);
        printf("Enter Priority:\t");
        scanf("%d", &process_queue[i].priority);
        process_queue[i].status = 0;
        bst_time += process_queue[i].bst_time;
    }

    Arr_time_Sorting();
    process_queue[9].priority = 9999;  // Sentinel for the largest priority
    
    printf("\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnAround Time");
    
    for(time = process_queue[0].arr_time; time < bst_time;) {
        largest = 9;
        for(i = 0; i < limit; i++) {
            if(process_queue[i].arr_time <= time && process_queue[i].status != 1 && process_queue[i].priority < process_queue[largest].priority) {
                largest = i;
            }
        }
        
        time += process_queue[largest].bst_time;
        process_queue[largest].ct = time;
        process_queue[largest].waiting_time = process_queue[largest].ct - process_queue[largest].arr_time - process_queue[largest].bst_time;
        process_queue[largest].turn_around_time = process_queue[largest].ct - process_queue[largest].arr_time;
        process_queue[largest].status = 1;
        
        wait_time += process_queue[largest].waiting_time;
        turn_around_time += process_queue[largest].turn_around_time;
        
        printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", process_queue[largest].process_name, process_queue[largest].arr_time, process_queue[largest].bst_time, process_queue[largest].priority, process_queue[largest].waiting_time, process_queue[largest].turn_around_time);
    }
    
    average_waiting_time = wait_time / limit;
    average_turn_around_time = turn_around_time / limit;
    
    printf("\n\nAverage Waiting Time:\t%f", average_waiting_time);
    printf("\nAverage Turnaround Time:\t%f\n", average_turn_around_time);
}