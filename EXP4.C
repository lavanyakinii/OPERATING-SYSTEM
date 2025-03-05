#include <stdio.h>
#include <conio.h>

void sjf(int n, int burst_time[]) {
    int i, j, temp;
    int waiting_time[20], turnaround_time[20], completion_time[20];
    int total_wt = 0, total_tat = 0;

    for(i = 0; i < n-1; i++) {
        for(j = i + 1; j < n; j++) {
            if(burst_time[i] > burst_time[j]) {
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;
            }
        }
    }
    
    completion_time[0] = burst_time[0];
    for(i = 1; i < n; i++) {
        completion_time[i] = completion_time[i-1] + burst_time[i];
    }

    for(i = 0; i < n; i++) {
        turnaround_time[i] = completion_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
        total_wt += waiting_time[i];
        total_tat += turnaround_time[i];
    }

    printf("\nShortest Job First Scheduling:\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    
    printf("\nAverage Waiting Time = %.2f", (float)total_wt/n);
    printf("\nAverage Turnaround Time = %.2f", (float)total_tat/n);
}

void priorityScheduling(int n, int burst_time[], int priority[]) {
    int i, j, temp;
    int waiting_time[20], turnaround_time[20], completion_time[20];
    int total_wt = 0, total_tat = 0;

    for(i = 0; i < n-1; i++) {
        for(j = i + 1; j < n; j++) {
            if(priority[i] > priority[j]) {
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;

                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
            }
        }
    }

    completion_time[0] = burst_time[0];
    for(i = 1; i < n; i++) {
        completion_time[i] = completion_time[i-1] + burst_time[i];
    }

    for(i = 0; i < n; i++) {
        turnaround_time[i] = completion_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
        total_wt += waiting_time[i];
        total_tat += turnaround_time[i];
    }

    printf("\nPriority Scheduling:\n");
    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], priority[i], waiting_time[i], turnaround_time[i]);
    }
    
    printf("\nAverage Waiting Time = %.2f", (float)total_wt/n);
    printf("\nAverage Turnaround Time = %.2f", (float)total_tat/n);
}

void main() {
    int n, i, choice;
    int burst_time[20], priority[20];
    clrscr(); 

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    printf("Enter 1 for Shortest Job First (SJF) Scheduling\n");
    printf("Enter 2 for Priority Scheduling\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            sjf(n, burst_time);
            break;
        case 2:
            for(i = 0; i < n; i++) {
                printf("Enter priority for process %d: ", i + 1);
                scanf("%d", &priority[i]);
            }
            priorityScheduling(n, burst_time, priority);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    getch(); // Wait for user input before closing
}
