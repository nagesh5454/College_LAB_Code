// Aim: To write a C program to implement the producer – consumer problem using Semaphores.
// Input:
#include <stdio.h>
#include <stdlib.h>
int mutex = 1;
int full = 0;
int empty = 3;
int x = 0;
void producer();
void consumer();
int wait(int);
int signal(int);
int main()
{
    int n;
    printf("\n1. PRODUCER\n2. CONSUMER\n3. EXIT\n");
    while (1)
    {
        printf("\nENTER YOUR CHOICE\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if ((mutex == 1) && (empty != 0))
                producer();
            else
                printf("BUFFER IS FULL\n");
            break;
        case 2:
            if ((mutex == 1) && (full != 0))
                consumer();
            else
                printf("BUFFER IS EMPTY\n");
            break;
        case 3:
            exit(0);
        }
    }
    return 0;
}
int wait(int s)
{
    return (--s);
}
int signal(int s)
{
    return (++s);
}
void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("\nProducer produces the item %d\n", x);
    mutex = signal(mutex);
}
void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\nConsumer consumes item %d\n", x);
    x--;
    mutex = signal(mutex);
}
// Output:
// 1. PRODUCER
// 2. CONSUMER
// 3. EXIT
// ENTER YOUR CHOICE
// 1
// Producer produces the item 1
// ENTER YOUR CHOICE
// 2
// Consumer consumes item 1
// ENTER YOUR CHOICE
// 3
