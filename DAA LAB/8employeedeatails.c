#include<stdio.h>
struct employee{
    char name[30];
    int id;
    int  salary;
};
int main(){
   struct employee em1;
   struct employee em2;
   printf("first employee");
   printf("enter name of em1 :");
   scanf("%s\n",&em1.name);
   printf("enter id");
   scanf("%d\n",&em1.id);
   printf("enter salary");
   scanf("%d\n",&em1.salary);
   printf("the name of the employee is  %s",em1.name);
   printf("id ofthe emploeyee is %d\n",em1.id);
   printf("salary of the employee is %d\n",em1.salary);
   
   printf("----------second employee:--------------");
   printf("enter name of em2 :");
   scanf("%s\n",&em2.name);
   printf("enter id");
   scanf("%d\n",&em2.id);
   printf("enter salary");
   scanf("%d\n",&em2.salary);
   printf("the name of the employee is  %s",em2.name);
   printf("id ofthe emploeyee is %d\n",em2.id);
   printf("salary of the employee is %d\n",em2.salary);
   
   return 0;
}