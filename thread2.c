#include "thread2.h"

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void* thread_process2(void* arg) {
  int thread_id = ((int*)arg)[0];
  int num_threads = ((int*)arg)[1];

  srand(time(NULL) + thread_id);
  int sleep_time = (rand() % 8) + 1;

  pthread_t self_id = pthread_self();

  if (thread_id < num_threads) {
    printf(
        "Thread %d (ID: %lu) will sleep for %d seconds after creating Thread "
        "%d\n",
        thread_id, (unsigned long)self_id, sleep_time, thread_id + 1);
  } else {
    printf(
        "Thread %d (ID: %lu) [no child created], will sleep for %d seconds\n",
        thread_id, (unsigned long)self_id, sleep_time);
  }

  sleep(sleep_time);

  printf("Thread %d (ID: %lu) exiting.\n", thread_id, (unsigned long)self_id);
  return NULL;
}
