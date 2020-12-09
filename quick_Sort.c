#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void swap (int* n, int* m){
    int a;
    a = *n;
    *n = *m;
    *m = a;
}

void quick_sort(int * a, int x, int y){
    if(x >= y) {
        return;
    }
    int d, b, c;
    d = (a[x] + a[y])/2;
    b = y;
    c = x;
    while(x < y) {
        while ((a[x] <= d)&&(x<=b-1))
            x++;
        while ((a[y] > d)&&(y>=c+1))
            y--;
        if(x <= y) {
            int p = a[x];
            a[x] = a[y];
            a[y] = p;
        }
    }
    if(y<x){
        y++;
        x--;
    }
    if(x == y){
        if(x-1<c)
            y++;
        else
            x--;
    }
    quick_sort(a,c,x);
    quick_sort(a,y,b);
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
            quick_sort(array, 0, h - 1);
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
