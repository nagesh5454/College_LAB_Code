// Aim: To write a C program to implement Banker’s algorithm for deadlock avoidance.
// Input:
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n, r;
void input();
void show();
void cal();
int main()
{
    printf("********** Banker's Algorithm ************\n");
    input();
    show();
    cal();
    getch();
    return 0;
}
void input()
{
    int i, j;
    printf("Enter the number of Processes: ");
    scanf("%d", &n);
    printf("Enter the number of Resources instances: ");
    scanf("%d", &r);
    printf("Enter the Max Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the Allocation Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter the Available Resources:\n");
    for (j = 0; j < r; j++)
    {
        scanf("%d", &avail[j]);
    }
}
void show()
{
    int i, j;
    printf("Process\tAllocation\tMax\t\tAvailable\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t", i + 1);
        for (j = 0; j < r; j++)
        {
            printf("%d ", alloc[i][j]);
        }
        printf("\t");
        for (j = 0; j < r; j++)
        {
            printf("%d ", max[i][j]);
        }
        printf("\t");
        if (i == 0)
        {
            for (j = 0; j < r; j++)
            {
                printf("%d ", avail[j]);
            }
        }
        printf("\n");
    }
}
void cal()
{
    int finish[100], safe[100], temp;
    int i, j, k, c1 = 0, flag = 1;
    for (i = 0; i < n; i++)
    {
        finish[i] = 0;
    }
    // Find need matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    printf("\n");
    while (flag)
    {
        flag = 0;
        for (i = 0; i < n; i++)
        {
            int c = 0;
            for (j = 0; j < r; j++)
            {
                if (finish[i] == 0 && need[i][j] <= avail[j])
                {
                    c++;
                }
            }
            if (c == r)
            {
                for (j = 0; j < r; j++)
                {
                    avail[j] += alloc[i][j];
                }
                finish[i] = 1;
                flag = 1;
                safe[c1++] = i;
                printf("P%d -> ", i);
            }
        }
    }
    printf("\n");
    int unsafe = 0;
    for (i = 0; i < n; i++)
    {
        if (finish[i] == 0)
        {
            unsafe = 1;
            printf("P%d -> ", i);
        }
    }
    if (unsafe)
    {
        printf("\nSystem is in unsafe state");
    }
    else
    {
        printf("\nThe system is in a safe state");
    }
}
// Output:
// ********** Banker's Algorithm ************
// Enter the number of Processes: 5
// Enter the number of Resources instances: 3
// Enter the Max Matrix:
// 7 5 3
// 3 2 2
// 9 0 2
// 2 2 2
// 4 3 3
// Enter the Allocation Matrix:
// 0 1 0
// 2 0 0
// 3 0 2
// 2 1 1
// 0 0 2
// Enter the Available Resources:
// 3 3 2
// Process Allocation Max Available
// P1 0 1 0 7 5 3 3 3 2
// P2 2 0 0 3 2 2
// P3 3 0 2 9 0 2
// P4 2 1 1 2 2 2
// P5 0 0 2 4 3 3
// P1 -> P3 -> P4 -> P0 -> P2 ->
// The system is in a safe state
