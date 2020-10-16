//#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <string.h>
int main(int argc, char **argv)
{
  int i, j, k;
  int N = atoi(argv[1]);
  int A[N][N];
  int B[N][N];
  int C[N][N];

  clock_t start, end;

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
    {
      A[i][j] = 3;
      B[i][j] = 3;
      C[i][j] = 0;
    }

  start = clock();

  for (i = 0; i < N; ++i)
  {
    for (j = 0; j < N; ++j)
    {
      for (k = 0; k < N; ++k)
      {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  end = clock();

  /*
  for (i = 0; i < N; i++)
  {
    for (j = 0; j < N; j++)
    {
      printf("%i - ", C[i][j]);
    }
    printf("\n");
  }*/

  double t = ((double)(end - start)) / (CLOCKS_PER_SEC / 1000);
  printf("%f\t", t);
  return 0;
}