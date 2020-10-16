#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <string.h>
int main(int argc, char **argv)
{
  int x, y;
  int N = atoi(argv[1]);
  int A[N][N];
  int B[N][N];
  int C[N][N];

  clock_t start, end;

  for (x = 0; x < N; x++)
    for (y = 0; y < N; y++)
    {
      A[x][y] = 3;
      B[x][y] = 3;
      C[x][y] = 0;
    }

  omp_set_num_threads(omp_get_num_procs());
  start = clock();

#pragma omp parallel shared(A, B, C)
  {
    printf("%i\n", omp_get_num_threads());
    int i, j, k;
#pragma omp for
    for (i = 0; i < N; ++i)
    {
      //printf("%i\n", omp_get_num_threads());
      for (j = 0; j < N; ++j)
      {
        for (k = 0; k < N; ++k)
        {
          C[i][j] += A[i][k] * B[k][j];
        }
      }
    }
  }
  end = clock();

  /*
  for (x = 0; x < N; x++)
  {
    for (y = 0; y < N; y++)
    {
      printf("%i - ", C[x][y]);
    }
    printf("\n");
  }*/

  double t = ((double)(end - start)) / (CLOCKS_PER_SEC / 1000);
  printf("%f\n", t);
  return 0;
}