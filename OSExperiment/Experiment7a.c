// Aim: To write a C program for implementation of FIFO page replacement algorithm.
// Input:
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i = 0, j = 0, k = 0, i1 = 0, size, n, rs[30], flag = 1, p[30];
    system("clear");
    printf("FIFO page replacement algorithm....\n");
    printf("Enter the number of frames: ");
    scanf("%d", &n);
    printf("Enter the reference string (terminate with 0): ");
    while (1)
    {
        scanf("%d", &rs[i]);
        if (rs[i] == 0)
            break;
        i++;
    }
    size = i;
    for (j = 0; j < n; j++)
        p[j] = 0;
    for (i = 0; i < size; i++)
    {
        flag = 1;
        for (j = 0; j < n; j++)
        {
            if (p[j] == rs[i])
            {
                printf("Data already in page...\n");
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            p[i1] = rs[i];
            i1++;
            k++;
            if (i1 == n)
                i1 = 0;
            printf("\nPage replacements: ");
            for (j = 0; j < n; j++)
            {
                printf("\nPage %d: %d", j + 1, p[j]);
                if (p[j] == rs[i])
                    printf(" *");
            }
            printf("\n\n");
        }
    }
    printf("Total number of page faults = %d\n", k);
    return 0;
}
// Output:
// FIFO page replacement algorithm....
// Enter the number of frames: 4
// Enter the reference string (terminate with 0): 6
// 7
// 9
// 0
// Page replacements:
// Page 1: 6 *
// Page 2: 0
// Page 3: 0
// Page 4: 0
// Page replacements:
// Page 1: 6
// Page 2: 7 *
// Page 3: 0
// Page 4: 0
// Page replacements:
// Page 1: 6
// Page 2: 7
// Page 3: 9 *
// Page 4: 0
// Total number of page faults = 3
