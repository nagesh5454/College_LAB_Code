// Aim: To write a C program for implementation of Priority scheduling algorithm.
// Input: 
#include<stdio.h> 
#include<stdlib.h> 
typedef struct 
{ int pno; 
 int pri; 
 int btime; 
 int wtime; 
} sp; 
int main() 
{ int i, j, n; 
 int tbm = 0, totwtime = 0, totttime = 0; 
 sp *p, t; 
 printf("\n PRIORITY SCHEDULING.\n"); 
 printf("\n enter the number of processes:\n"); 
 scanf("%d", &n); 
 p = (sp*)malloc(n * sizeof(sp)); 
 printf("Enter the burst time and priority:\n"); 
 for(i = 0; i < n; i++) 
 { printf("Process %d: ", i + 1); 
 scanf("%d%d", &p[i].btime, &p[i].pri); 
 p[i].pno = i + 1;
 p[i].wtime = 0; 
 } 
 for(i = 0; i < n - 1; i++) 
 for(j = i + 1; j < n; j++) 
 { if(p[i].pri > p[j].pri) 
 { t = p[i]; 
 p[i] = p[j]; 
 p[j] = t; 
 } } 
 printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
 for(i = 0; i < n; i++) 
 { totwtime += p[i].wtime = tbm; 
 tbm += p[i].btime; 
 printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].pno, p[i].btime, p[i].wtime, p[i].wtime + p[i].btime); 
 } 
 totttime = tbm; 
 printf("\nTotal waiting time: %d", totwtime); 
 printf("\nAverage waiting time: %.2f", (float)totwtime / n); 
 printf("\nTotal turnaround time: %d", totttime); 
 printf("\nAverage turnaround time: %.2f\n", (float)totttime / n); 
 free(p); // Free the allocated memory
 return 0;
}
// Output: 
// PRIORITY SCHEDULING.
// enter the number of processes: 3
// Enter the burst time and priority:
// Process 1: 5
// 1
// Process 2: 3
// 1
// Process 3: 5
// 2
// Process Burst Time Waiting Time Turnaround Time
// 1 5 0 5
// 2 3 5 8
// 3 5 8 13
// Total waiting time: 13
// Average waiting time: 4.33
// Total turnaround time: 13
// Average turnaround time: 4.33
