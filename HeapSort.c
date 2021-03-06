#include <stdio.h>
#include <stdlib.h>
void heap_breaking(int *n, int a, int b)
{
    int max, d = 0;

    while ((a * 2 <= b) && (!d))
    {
        if (a * 2 == b) {
            max = a * 2;
        }
        else if (n[a * 2] > n[a * 2 + 1])
            max = a * 2;

        else
            max = a * 2 + 1;

        if (n[a] < n[max])
        {
            int t;
            t = n[a];
            n[a] = n[max];
            n[max] = t;
            a = max;
        }
        else
            d = 1;
    }
}

void HeapSort(int *n, int arr_size)
{

    for (int i = (arr_size / 2) - 1; i >= 0; i--)
        heap_breaking(n, i, arr_size - 1);
        for (int i = arr_size - 1; i >= 1; i--)
    {
        int t;
        t = n[0];
        n[0] = n[i];
        n[i] = t;
        heap_breaking (n, 0, (i - 1));
    }
}
int main()
{
    FILE* F = fopen("input.txt", "r");
    FILE* f = fopen("output.txt", "w");
    int  N = 0, h = 0;
    double t = 0, a = 0;
    fscanf(F, "%d", &N);
    int* array = malloc(sizeof(int));
    for(int i = 0; i < N; i++)
    {
        fscanf(F, "%d", &h);
        free(array);
        array = malloc(sizeof(int) * h);
        for(int j = 0; j < h; j++)
        {
            fscanf(F, "%d", &array[j]);
        }
        t = timing();

        HeapSort(array, 0, h - 1);

        t = (timing() - t);
        a += t * 1000;
        for(int j = 0; j < h; j++)
        {
            fprintf(f, "%d ", array[j]);
        }
        fprintf(f, "\n");
        fprintf(f, "Algorithm running time: %lf\n", t * 1000);
    }

    free(array);
    fclose(F);
    fclose(f);
    return 0;
}
