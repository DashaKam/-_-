#include <stdlib.h>
#include <stdio.h>
#include <math.h>
void shell_sort (int arr[], int s) {
    int step;
    for (step = s / 2; step > 0; step /= 2) {
        for (int i = step; i < s; i++) {
            for (int j = i - step; j >= 0 && arr[j] > arr[j + step]; j -= step) {
                int t;
                t = arr[j];
                arr[j] = arr[j + step];
                arr[j + step] = t;
            }
        }
    }
}

int main (){
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
        shell_sort (array, 0, h - 1);
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
