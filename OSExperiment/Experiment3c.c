// Aim: To write a C program for implementation of FCFS scheduling algorithm.
// Input:
#include <stdio.h>
#include <stdlib.h>
struct fcfs
{
    int pid;
    int btime;
    int wtime;
    int ttime;
} p[10];
int main()
{
    int i, n;
    int total_wtime = 0, total_ttime = 0;
    printf("\nFCFS Scheduling...\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("\nEnter burst time of process %d: ", p[i].pid);
        scanf("%d", &p[i].btime);
    }
    // Calculating waiting time and turnaround time
    p[0].wtime = 0;          // Waiting time for first process is 0
    p[0].ttime = p[0].btime; // Turnaround time for first process
    for (i = 1; i < n; i++)
    {
        p[i].wtime = p[i - 1].wtime + p[i - 1].btime;
        p[i].ttime = p[i].wtime + p[i].btime;
    }
    // Calculating total waiting time and total turnaround time
    for (i = 0; i < n; i++)
    {
        total_wtime += p[i].wtime;
        total_ttime += p[i].ttime;
    }
    // Displaying process details
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].btime, p[i].wtime, p[i].ttime);
    }
    // Displaying total and average times
    printf("\nTotal Waiting Time: %d", total_wtime);
    printf("\nAverage Waiting Time: %.2f", (float)total_wtime / n);
    printf("\nTotal Turnaround Time: %d", total_ttime);
    printf("\nAverage Turnaround Time: %.2f", (float)total_ttime / n);
    return 0;
}
// Output:
// FCFS Scheduling...
// Enter the number of processes: 3
// Enter burst time of process 1: 5
// Enter burst time of process 2: 4
// Enter burst time of process 3: 6
// Process Burst Time Waiting Time Turnaround Time
// 1 5 0 5
// 2 4 5 9
// 3 6 9 15
// Total Waiting Time: 14
// Average Waiting Time: 4.67
// Total Turnaround Time: 29
// Average Turnaround Time: 9.67
