// Aim: To write a C program for implementation of LRU page replacement algorithm.
// Input:
#include <stdio.h>
int main()
{
    int q[20], p[50], c = 0, c1, d, f, i, j, k = 0, n, r, t, b[20], c2[20];
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter the reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);
    printf("Enter number of frames: ");
    scanf("%d", &f);
    q[k] = p[k];
    printf("\n\t%d\n", q[k]);
    c++;
    k++;
    for (i = 1; i < n; i++)
    {
        c1 = 0;
        for (j = 0; j < f; j++)
        {
            if (p[i] != q[j])
                c1++;
        }
        if (c1 == f)
        {
            c++;
            if (k < f)
            {
                q[k] = p[i];
                k++;
                for (j = 0; j < k; j++)
                    printf("\t%d", q[j]);
                printf("\n");
            }
            else
            {
                for (r = 0; r < f; r++)
                {
                    c2[r] = 0;
                    for (j = i - 1; j < n; j--)
                    {
                        if (q[r] != p[j])
                            c2[r]++;
                        else
                            break;
                    }
                }
                int maxIndex = 0;
                for (r = 0; r < f; r++)
                {
                    if (c2[r] > c2[maxIndex])
                        maxIndex = r;
                }
                q[maxIndex] = p[i];
                for (r = 0; r < f; r++)
                    printf("\t%d", q[r]);
                printf("\n");
            }
        }
    }
    printf("\nThe number of page faults is %d\n", c);
    return 0;
}
// Output:
// Enter number of pages: 3
// Enter the reference string: 3
// 5
// 6
// Enter number of frames: 4
// 3
// 3 5
// 3 5 6
// The number of page faults is 3
