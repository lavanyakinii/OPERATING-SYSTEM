#include <stdio.h>
#include <conio.h>

void sjf(int n, int burst_time[]) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = i + 1; j < n; j++) {
            if(burst_time[i] > burst_time[j]) {
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;
            }
        }
    }
    printf("\nShortest Job First Scheduling:\n");
    printf("Process\tBurst Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\n", i + 1, burst_time[i]);
    }
}

void priorityScheduling(int n, int burst_time[], int priority[]) {
    int i, j, temp;
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
    printf("\nPriority Scheduling:\n");
    printf("Process\tBurst Time\tPriority\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", i + 1, burst_time[i], priority[i]);
    }
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


