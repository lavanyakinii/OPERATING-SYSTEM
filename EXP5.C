#include <stdio.h>
#include <conio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

void bankersAlgorithm(int m, int n, int alloc[MAX_PROCESSES][MAX_RESOURCES], int max[MAX_PROCESSES][MAX_RESOURCES], int avail[MAX_RESOURCES], int safeSeq[MAX_PROCESSES]) {
    int i, j, k;
    int need[MAX_PROCESSES][MAX_RESOURCES];
    int finish[MAX_PROCESSES];
    int work[MAX_RESOURCES];
    int count = 0;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for (i = 0; i < m; i++) {
        finish[i] = 0;
    }
    for (i = 0; i < n; i++) {
        work[i] = avail[i];
    }

    while (count < m) {
        int flag = 0;
        for (i = 0; i < m; i++) {
            if (finish[i] == 0) {
                int canProceed = 1;
                for (j = 0; j < n; j++) {
                    if (need[i][j] > work[j]) {
                        canProceed = 0;
                        break;
                    }
                }
                if (canProceed) {
                    for (k = 0; k < n; k++) {
                        work[k] += alloc[i][k];
                    }
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0) {
            printf("System is in an unsafe state\n");
            return;
        }
    }

    printf("System is in a safe state\nSafe Sequence: ");
    for (i = 0; i < m; i++) {
        printf("P%d ", safeSeq[i] + 1);
    }
    printf("\n");
}

void main() {
    int m, n, i, j;
    int alloc[MAX_PROCESSES][MAX_RESOURCES], max[MAX_PROCESSES][MAX_RESOURCES], avail[MAX_RESOURCES], safeSeq[MAX_PROCESSES];

    clrscr();

    printf("Enter the number of processes: ");
    scanf("%d", &m);
    printf("Enter the number of resources: ");
    scanf("%d", &n);

    printf("Enter allocation matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter allocation for process P%d, resource R%d: ", i + 1, j + 1);
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter maximum matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter max for process P%d, resource R%d: ", i + 1, j + 1);
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter available resources:\n");
    for (i = 0; i < n; i++) {
        printf("Enter available resources R%d: ", i + 1);
        scanf("%d", &avail[i]);
    }

    bankersAlgorithm(m, n, alloc, max, avail, safeSeq);

    getch();
}
