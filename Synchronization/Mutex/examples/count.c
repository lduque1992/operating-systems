#include <stdio.h>
#include <pthread.h>
#define NUM_LOOPS 2000000;
long long sum = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* counting_threads(void *arg) {

  int offset = *(int *) arg;
  for (int i = 0; i < NUM_LOOPS i++) {
    // Start critical section
    pthread_mutex_lock(&mutex);
    sum += offset;
    pthread_mutex_unlock(&mutex);
    // End critical section
  }
  pthread_exit(NULL);

}

int main(int argc, char const *argv[]) {

  // spawn threads
  pthread_t id1;
  int offset1 = 1;
  pthread_create(&id1, NULL, counting_threads, &offset1);

  pthread_t id2;
  int offset2 = -1;
  pthread_create(&id2, NULL, counting_threads, &offset2);

  pthread_t id3;
  int offset3 = 2;
  pthread_create(&id3, NULL, counting_threads, &offset3);

  pthread_t id4;
  int offset4 = -2;
  pthread_create(&id4, NULL, counting_threads, &offset4);

  // wait to threads to finish
  pthread_join(id1, NULL);
  pthread_join(id2, NULL);
  pthread_join(id3, NULL);
  pthread_join(id4, NULL);

  printf("Sum = %lld\n", sum);
  return 0;
}
