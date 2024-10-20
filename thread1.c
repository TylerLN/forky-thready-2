#include "thread1.h"

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void* thread_process1(void* arg) {
  int thread_id = *((int*)arg);

  srand(time(NULL) + thread_id);
  int sleep_time = (rand() % 8) + 1;

  fprintf(stdout, "Thread %d (ID: %lu): will sleep for %d seconds.\n",
          thread_id, pthread_self(), sleep_time);

  sleep(1);

  fprintf(stdout, "Thread %d (ID: %lu) sleeping.\n", thread_id, pthread_self());

  sleep(sleep_time);

  fprintf(stdout, "Thread %d (ID: %lu) exiting.\n", thread_id, pthread_self());

  return NULL;
}
