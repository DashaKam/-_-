#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int number, len, f;
    struct list * next;
}list;

list * c_l(int number, int len, int  f) {
    list *l = malloc(sizeof(list));
    l->number = number;
    l->len = len;
    l->f = f;
    l->next = NULL;
    return l;
}

int s_1 (int * ar, int s, int n){
    for(int i = 0; i < n+1; i++)
        if (ar[i] == s)
            return 1;
    return 0;
}

int in_list(list * head, int number){
    for (list * i = head; i->next; i = i->next){
        if (i->number == number)
            return 1;
    }
    return 0;
}

void add(list* head,int number,int len,int f){
    list * l = c_l(number,len,f);
    while ((head->next)&&(head->next->len < l->len))
        head = head->next;
    l->next = head->next;
    head->next = l;
}

void delete_element(list * head, int number){
    for (list * i = head; i->next->next; i = i->next){
        if (i->next->number == number) {
            i->next = i->next->next;
            free(i->next);
            return ;
        }
    }
}

void vary_len(list * head, int len2, int number){
    for(list * i = head; i->next; i = i->next){
        if(i->number == number){
            if(i->len > len2) {
                i->len = len2;
                while ((head->next)&&(head->next->len < i->len))
                    head = head->next;
                list * l = i;
                delete_element(head,i->number);
                l->next = head->next;
                head->next = l;
                return;
            }
        }
    }
}

void delete_list(list * head){
    for(list * i = head; i->next; i = i->next)
        free(i);
}

int ret_f(list * head, int number ){
    for(list * i = head; i->next; i = i->next){
        if(i->number == number)
            return i->f;
    }
    return 0;
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

    if (file_1 == NULL)
        return -1;
    int s, fi, number_of_vertexs, number_of_rib, type;
    fscanf(file_1, "%d %d %d %d %d", &s, &fi, &number_of_vertexs, &number_of_rib, &type);

    int length = 0;

     if((type == 1)||(type == 2)) {
         int masive[number_of_rib*2][3];
         while (!(feof(file_1))) {
            fscanf(file_1, "%d %d %d", &masive[length][0], &masive[length][1], &masive[length][2]);
            length++;
        }

        list *h = c_l(s, 0, 1);
        list *n = h;
        while (n) {
            for (int i = 0; i < length; i++) {
                if (masive[i][0] == n->number) {
                    if ((in_list(h, masive[i][1])) && (ret_f(h, masive[i][1]))) {
                        vary_len(h, n->len + masive[i][2], masive[i][1]);
                    };
                    if (!in_list(h, masive[i][1])) {
                        add(h, masive[i][1], n->len + masive[i][2], 1);
                    }
                }
            }
            n->f = 0;
            n = n->next;
        }
        for (list *i = h; i->next; i = i->next) {
            if (i->number == fi)
                fprintf(file_2,"%d", i->len);
        }
        delete_list(h);
    }

    if((type == 3)||(type == 4)) {
        int masive[number_of_rib*2][3];
        while (!(feof(file_1))) {
            fscanf(file_1, "%d %d", &masive[length][0], &masive[length][1]);
            length++;
        }

        int d[number_of_vertexs], v[number_of_vertexs],  k = 0, i = 0;
        for (int t = 0; t < i + 1; t++) {
            s = d[t];
            for (int j = 0; j < length; j++)
                if (masive[j][0] == s) {
                    if (!(s_1(v, masive[j][1], k)) && !(s_1(d, masive[j][1], i))) {
                        i++;
                        d[i] = masive[j][1];
                    }
                }
            v[k] = s;
            k++;
        }

        if (s_1(v, fi, k))
            fprintf(file_2,"%s", "true");
        else
            fprintf(file_2,"%s", "false");
    }

    fclose(file_1);
    fclose(file_2);
    return 0;
}
