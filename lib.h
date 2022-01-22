int p(int x, int y)
{
    int aux = x;
    for (int i = 1; i < y; i++)
    {
        x = x * aux;
    }
    return x;
}

int *LAAC(int n)
{
    int *A = (int *)malloc(p(10, n) * sizeof(int));

    for (int i = 0; i < p(10, n); i++)
    {
        A[i] = i;
    }

    return A;
}

int *LAAD(int n)
{
    int *A = (int *)malloc(p(10, n) * sizeof(int));

    for (int i = 0; i < p(10, n); i++)
    {
        A[i] = p(10, n) - i;
    }

    return A;
}

int *LAAA(int n)
{
    int *A = LAAC(n);

    std ::random_shuffle(A, A + p(10, n));

    return A;
}

void printArray(int *a, int size) {
  int i;
  for (i = 0; i < size; i++)
  {
      printf("%d ",a[i]);
  }
  printf("\n");
}
