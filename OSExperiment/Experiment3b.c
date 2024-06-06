// Aim: To write a C program for implementation of SJF scheduling algorithm.
// Input:
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int pid;
    int btime;
    int wtime;
} sp;
int main()
{
    int i, j, n, tbm = 0, total_wtime = 0, total_ttime = 0;
    sp *p, t;
    printf("\nSJF Scheduling...\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    p = (sp *)malloc(n * sizeof(sp));
    if (!p)
    {
        printf("Memory allocation failed");
        return 1;
    }
    printf("\nEnter the burst times:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &p[i].btime);
        p[i].pid = i + 1;
        p[i].wtime = 0;
    }
    // Sorting processes by burst time using bubble sort
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i].btime > p[j].btime)
            {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }
    // Calculating waiting time and total burst time
    printf("\nProcess Scheduling\n");
    printf("\nProcess\tBurst Time\tWaiting Time\n");
    for (i = 0; i < n; i++)
    {
        p[i].wtime = tbm;
        total_wtime += p[i].wtime;
        tbm += p[i].btime;
        printf("%d\t%d\t\t%d\n", p[i].pid, p[i].btime, p[i].wtime);
    }
    total_ttime = tbm;
    // Displaying total and average times
    printf("\nTotal Waiting Time: %d", total_wtime);
    printf("\nAverage Waiting Time: %.2f", (float)total_wtime / n);
    printf("\nTotal Turnaround Time: %d", total_ttime);
    printf("\nAverage Turnaround Time: %.2f", (float)total_ttime / n);
    free(p);
    return 0;
}


// Output:
// SJF Scheduling...
// Enter the number of processes: 3
// Enter the burst times:
// Process 1: 5
// Process 2: 6
// Process 3: 8
// Process Scheduling
// Process Burst Time Waiting Time
// 1 5 0
// 2 6 5
// 3 8 11
// Total Waiting Time: 16
// Average Waiting Time: 5.33
// Total Turnaround Time: 19
// Average Turnaround Time: 6.33
