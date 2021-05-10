#include <stdio.h>

int s_1(int * a, int r, int n){
    for(int i = 0; i < n; i++) {
        if (a[i] == r) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

int DFS(int (*masive)[2], int * n, int p, int result, int t, int l){
    n[p-1] = p;
    for (int i = 0; i < t; i++){
        int d, h;
        if(masive[i][0] == p){
            h = s_1(n,masive[i][1],l);
            if (!h){
                result++;
                d = DFS(masive,n,masive[i][1],result,t,l);
                result = d;
            }

        }
    }
    return result;
}

int main(int argc, char * argv[]) {
    FILE * file_1;
    FILE * file_2;
    if (argc >= 3){
        file_1 = fopen(argv[1], "r");
        file_2 = fopen(argv[2], "w");
    }else if (argc == 2){
        file_1 = fopen(argv[1], "r");
        file_2 = fopen("output.txt", "w");
    }else{
        file_1 = fopen("input.txt", "r");
        file_2 = fopen("output.txt", "w");
    }
    if ((file_1 == NULL)||(file_2 == NULL)) {
        return -1;
    }
    int r, fi, number_of_vertexes, number_of_rib, type;
    fscanf(file_1, "%d %d %d %d %d", &r, &fi, &number_of_vertexes, &number_of_rib, &type);
    int length = 0,  masive[number_of_rib*2][2];
    while (!(feof(file_1))) {
        fscanf(file_1, "%d %d", &masive[length][0], &masive[length][1]);
        length++;
    }

    int n[number_of_vertexes];
    for(int i = 0; i < number_of_vertexes; i++)
        n[i] = 0;
        int res;
        res = DFS(masive, n, r, 0, length, number_of_vertexes);
        fprintf(file_2, "%d", &res);

        if (s_1(n, fi, number_of_vertexes)) {
            fprintf(file_2, "%d", 1);
        }
        else {
            fprintf(file_2, "%d", 0);
        }

    fclose(file_1);
    fclose(file_2);
    return 0;
}
