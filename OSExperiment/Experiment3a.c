// Aim: To write a C program for implementation of Round Robin scheduling algorithm.
// Input:
#include <stdio.h>
#include <stdlib.h>
struct rr
{
    int pno, btime, sbtime, wtime, lst;
} p[10];
int main()
{
    int pp = -1, ts, flag, count, ptm = 0, i, n, twt = 0, tottime = 0;
    printf("\nRound Robin Scheduling............");
    printf("\nEnter number of processes: ");
    scanf("%d", &n);
    printf("Enter the time slice: ");
    scanf("%d", &ts);
    printf("Enter the burst time\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d\t", i + 1);
        scanf("%d", &p[i].btime);
        p[i].wtime = p[i].lst = 0;
        p[i].pno = i + 1;
        p[i].sbtime = p[i].btime;
    }
    printf("Scheduling....\n");
    do
    {
        flag = 0;
        for (i = 0; i < n; i++)
        {
            count = p[i].btime;
            if (count > 0)
            {
                flag = 1;
                count = (count >= ts) ? ts : count;
                printf("\nProcess %d ", p[i].pno);
                printf("from %d ", ptm);
                ptm += count;
                printf("to %d", ptm);
                p[i].btime -= count;
                if (pp != i)
                {
                    pp = i;
                    p[i].wtime += ptm - p[i].lst - count;
                    p[i].lst = ptm;
                }
            }
        }
    } while (flag);
    printf("\nProcess\tBurst Time\tWaiting Time\n");
    for (i = 0; i < n; i++)
    {
        twt += p[i].wtime;
        printf("%d\t%d\t\t%d\n", p[i].pno, p[i].sbtime, p[i].wtime);
    }
    printf("\nTotal Waiting Time: %d", twt);
    printf("\nAverage Waiting Time: %.2f", (float)twt / n);
    return 0;
}
// Output:
// Round Robin Scheduling............
// Enter number of processes: 3
// Enter the time slice: 5
// Enter the burst time
// Process 1 1
// Process 2 4
// Process 3 6
// Scheduling....
// Process 1 from 0 to 1
// Process 2 from 1 to 5
// Process 3 from 5 to 10
// Process 3 from 10 to 11
// Process Burst Time Waiting Time
// 1 1 0
// 2 4 1
// 3 6 5
// Total Waiting Time: 6
// Average Waiting Time: 2.00
