// Aim: To write a C program for implementation of LFU page replacement algorithm.
// Input:
#include <stdio.h>
int main()
{
    int f, p;
    int pages[50], frame[10], hit = 0, count[50], time[50];
    int i, j, flag, least, minTime, temp;
    printf("Enter number of frames: ");
    scanf("%d", &f);
    printf("Enter number of pages: ");
    scanf("%d", &p);
    for (i = 0; i < f; i++){
        frame[i] = -1; // Initialize frames with invalid page number
    }
    for (i = 0; i < 50; i++){
        count[i] = 0;
    }
    printf("Enter page numbers:\n");
    for (i = 0; i < p; i++) {
        scanf("%d", &pages[i]);
    }
    printf("\n");
    for (i = 0; i < p; i++) {
        count[pages[i]]++;
        time[pages[i]] = i;
        flag = 1;
        least = frame[0];
        for (j = 0; j < f; j++)
        {
            if (frame[j] == -1 || frame[j] == pages[i])
            {
                if (frame[j] != -1)
                {
                    hit++;
                }
                flag = 0;
                frame[j] = pages[i];
                break;
            }
            if (count[least] > count[frame[j]])
            {
                least = frame[j];
            }
        }
        if (flag)
        {
            minTime = 50; // Assuming total pages < 50
            for (j = 0; j < f; j++)
            {
                if (count[frame[j]] == count[least] && time[frame[j]] < minTime)
                {
                    temp = j;
                    minTime = time[frame[j]];
                }
            }
            count[frame[temp]] = 0;
            frame[temp] = pages[i];
        }

        for (j = 0; j < f; j++)
        {
            printf("%d ", frame[j]);
        }
        printf("\n");
    }
    printf("Page hits: %d\n", hit);
    return 0;
}
// Output:
// Enter number of frames: 3
// Enter number of pages: 5
// Enter page numbers:
// 1
// 2
// 3
// 4
// 5
// 1 -1 -1
// 1 2 -1
// 1 2 3
// 4 2 3
// 4 5 3
// Page hits: 0
