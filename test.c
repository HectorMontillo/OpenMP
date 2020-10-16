// OpenMP header
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void simple(int n, float *a, float *b)
{
  int i;
#pragma omp parallel for
  for (i = 1; i < n; i++) /* i is private by default */
    b[i] = (a[i] + a[i - 1]) / 2.0;
}
int main(int argc, char *argv[])
{
  float a[5] = {1, 2, 3, 4, 5};
  float b[5];

  simple(5, a, b);

  int i;
  for (i = 0; i < 5; i++)
  {
    printf("%f ", b[i]);
  }
  printf("\n");
}

//int omp_get_num_threads(void); numero de hilos

//int omp_get_thread_num(void); identificar el hilo

//clausulas: shared(list) private(list) default(list)

// \ para hacer salto de linea en pragma
