#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#include "thread1.h"
#include "thread2.h"

#define MAX_THREADS 256

int main(int argc, char** argv) {
  if (argc != 3) {
    fprintf(stderr, "Invalid number of arguments");
    return 1;
  }

  int num_threads = atoi(argv[1]);
  int thread_choice = atoi(argv[2]);

  if (num_threads <= 0 || num_threads > MAX_THREADS) {
    fprintf(stderr, "Invalid number of threads. (Max threads: %d)\n",
            MAX_THREADS);
    return 1;
  }

  if (thread_choice < 1 || thread_choice > 2) {
    fprintf(stderr, "Invalid thread value.\n");
    return 1;
  }

  pthread_t threads_array[MAX_THREADS];
  int thread_data[MAX_THREADS][2];

  for (int ix = 0; ix <= num_threads; ix++) {
    thread_data[ix][0] = ix;
    thread_data[ix][1] = num_threads;

    if (thread_choice == 1) {
      pthread_create(&threads_array[ix], NULL, thread_process1,
                     thread_data[ix]);
    } else {
      pthread_create(&threads_array[ix], NULL, thread_process2,
                     thread_data[ix]);
    }

    fprintf(stdout, "Thread %d Created.\n", thread_data[ix][0]);
  }

  for (int iy = 0; iy < num_threads; iy++) {
    pthread_join(threads_array[iy], NULL);
  }

  fprintf(stdout, "All Threads Have Exited.\n");

  return 0;
}