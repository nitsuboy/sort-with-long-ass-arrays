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

void shuffle(int *array, int n)
{
    if (n > 1) 
    {
        int i;
        for (i = 0; i < n - 1; i++) 
        {
          int j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

int *LAAA(int n)
{
    int *A = LAAC(n);

    shuffle(A, p(10, n));

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
