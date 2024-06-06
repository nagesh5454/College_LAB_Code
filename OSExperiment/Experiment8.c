// Aim: To write C program to implement Threading & Synchronisation.
// Input:


// #include<stdio.h>
// #include<string.h>
// #include<pthread.h>
// #include<stdlib.h>
// #include<unistd.h>
// pthread_t tid[2];
// pthread_mutex_t lock;
// void* doSomeThing(void *arg) {
//  unsigned long i = 0;
//  pthread_t id = pthread_self();
//  if(pthread_equal(id, tid[0])) {
//  printf("\nFirst thread processing\n");
//  } else {
//  printf("\nSecond thread processing\n");
//  }
//  for(i = 0; i < 0xFFFFFFFF; i++); // This loop can be removed or adjusted as needed
//  return NULL;
// }
// int main(void) {
//  int i = 0;
//  int err;
//  if (pthread_mutex_init(&lock, NULL) != 0) {
//  printf("\nMutex initialization failed\n");
//  return 1;
//  }
//  while(i < 2) {
//  err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
//  if (err != 0) {
//  printf("\nCan't create thread : [%s]\n", strerror(err));
//  } else {
//  printf("\nThread %d created successfully\n", i + 1);
//  }
//  i++;
//  }
//  // Wait for threads to complete before exiting
//  for (i = 0; i < 2; i++) {
//  pthread_join(tid[i], NULL);
//  }
//  pthread_mutex_destroy(&lock);
//  return 0;
// }


// Output:
// Thread 1 created successfully
// Thread 2 created successfully
// First thread processing
// Second thread processin