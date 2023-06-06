#include "sllist.h"
#include "IO.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int getMax(int i, int j){
    if (i > j){
        return i;
    } else {
        return j;
    }
}

int getMin(int i, int j){
    if (i < j){
        return i;
    } else {
        return j;
    }
}

typedef struct _queen_{
    int id;
    int i;
    int j;
} queen;

queen * createQueen(int id, int i, int j ){
    if ( i < 0 || j < 0 ){
        return NULL;
    }
    queen *q = (queen *) malloc ( sizeof(queen) );
    q->id = id;
    q->i = i;
    q->j = j;
    return q;
}

int destroyQueen(queen * q){
    if (q == NULL)
        return FALSE;
    free(q);
    return TRUE;
}

typedef struct _table_{
    int size;
    int len;
    sllist *queens;
    int *map;
} table;

table * createTable( int n ){
    if ( n < 5 )
        return NULL;
    table *tab = (table *) malloc( sizeof(table) );
    if (tab == NULL)
        return NULL;
    
    int *map = (int *) malloc( n * n * sizeof(int) );
    for (int i = 0; i < n * n; i++){
        map[i] = -1;
    }
    if (map == NULL)
        return NULL;

    tab->size = n;
    tab->len = 0;
    tab->queens = sllCreate();
    tab->map = map;
    return tab;
}

int destroyTable( table * tab ){
    if ( tab == NULL || tab->queens != NULL )
        return FALSE;
    free(tab->map);
    sllEmpty(tab->queens);
    sllDestroy(tab->queens);
    free(tab);
    return TRUE;
}

int fullfilMap(table *tab, unsigned long iter){
    if (tab == NULL){
        return -1;
    }

    int i, j, counter, foundm2, alocQ;

    queen *q;

    while ( tab->len < tab->size){
        i = tab->len;
        foundm2 = FALSE;
        alocQ = FALSE;
        counter = 0;
        for (j = 0; j < tab->size; j++){
            if (tab->map[i * tab->size + j] == -1 && alocQ == FALSE){
                tab->map[i * tab->size + j] = 0;
                q = createQueen(tab->len, i, j);
                sllInsertFirst(tab->queens, (void *) q);
                alocQ = TRUE;
            } else if (tab->map[i * tab->size + j] == -2){
                if ( alocQ == TRUE ){
                    tab->map[ q->i * tab->size + q->j ] = -1;
                    q = (queen *) sllRemoveFirst(tab->queens);
                    alocQ = FALSE;
                }
                tab->map[i * tab->size + j] = -1;
            }
            counter++;
        }

        if ( alocQ == FALSE ){
            q = (queen *) sllRemoveFirst(tab->queens);
            printf("Saindo rainha: i: %d j: %d\n\n", q->i, q->j);
            i = q->i;
            for (j = 0; j < tab->size; j++){
                if (tab->map[ i * tab->size + j ] == tab->len)
                    tab->map[ i * tab->size + j ] = -1;
            }

            j = q->j;
            for (i = tab->len; i < tab->size; i++){
                if (tab->map[ i * tab->size + j ] == tab->len)
                    tab->map[ i * tab->size + j ] = -1;
            }

            i = q->i;
            j = q->j;

            while ( i > 0 && j > 0){
                i--;
                j--;
            }

            while ( i < tab->size && j < tab->size ){
                if (tab->map[ i * tab->size + j ] == tab->len)
                    tab->map[ i * tab->size + j ] = -1;
                i++;
                j++;
            }

            i = q->i;
            j = q->j;

            while ( i > 0 && j < 4 ){
                i--;
                j++;
            }

            while ( i < tab->size && j > 0 ){
                if (tab->map[ i * tab->size + j ] == tab->len)
                    tab->map[ i * tab->size + j ] = -1;
                i++;
                j--;
            }

            tab->map[ q->i * tab->size + q->j ] = -2;
            tab->len--;

            printf("\n\ntab->len : %d\n\n", tab->len);

            printf("\n");
            printf("\n");
            for (int i = 0; i < tab->size; i++){
                for (int j = 0; j < tab->size; j++){
                    printf("%d ", tab->map[i * tab->size + j]);
                }
                printf("\n");
            }
            printf("\n");
            printf("\n");
            iter++;
            // sleep(1);
            destroyQueen(q);
            continue;
        }

        printf("i: %d j: %d\n\n", q->i, q->j);

        for (j = 0; j < tab->size; j++){
            if ( tab->map[ q->i * tab->size + j ] != -1 )
                continue;
            tab->map[ q->i * tab->size + j ] = tab->len + 1;
        }

        for (i = tab->len + 1; i < tab->size; i++){
            if ( tab->map[ i * tab->size + q->j ] != -1 )
                continue;
            tab->map[ i * tab->size + q->j ] = tab->len + 1;
        }

        i = q->i;
        j = q->j;

        while ( i > 0 && j > 0){
            i--;
            j--;
        }

        while ( i < tab->size && j < tab->size ){
            if ( ( i != q->i || j != q->j ) && tab->map[ i * tab->size + j ] == -1 )
                tab->map[ i * tab->size + j ] = tab->len + 1;
            i++;
            j++;
        }

        i = q->i;
        j = q->j;

        while ( i > 0 && j < 4 ){
            i--;
            j++;
        }

        while ( i < tab->size && j > 0 ){
            if ( ( i != q->i || j != q->j ) && tab->map[ i * tab->size + j ] == -1 )
                tab->map[ i * tab->size + j ] = tab->len + 1;
            i++;
            j--;
        }

        printf("\n\ntab->len : %d\n\n", tab->len + 1);

        printf("\n");
        printf("\n");
        for (int i = 0; i < tab->size; i++){
            for (int j = 0; j < tab->size; j++){
                printf("%d ", tab->map[i * tab->size + j]);
            }
            printf("\n");
        }
        printf("\n");
        printf("\n");

        tab->len++;
        iter++;
        continue;
    }

    return iter;
}

int main(){

    clock_t start_t, end_t;
    double total_t;
    start_t = clock();

    table *tab = createTable(50);

    for (int i = 0; i < tab->size; i++){
        for (int j = 0; j < tab->size; j++){
            printf("%d ", tab->map[i * tab->size + j]);
        }
        printf("\n");
    }

    printf("\n\n");

    unsigned long iter = fullfilMap(tab, 0ul);
    printf("Quantidade de iterações: %lu!\n", iter);
    printf("\n\n");
    for (int i = 0; i < tab->size; i++){
        for (int j = 0; j < tab->size; j++){
            printf("%d ", tab->map[i * tab->size + j]);
        }
        printf("\n");
    }

    free(tab->map);
    free(tab->queens);
    free(tab);

    end_t = clock();
    total_t = (double) (end_t - start_t) / CLOCKS_PER_SEC;
    printf("\n\nTempo total de execução do programa: %f!\n\n", total_t);

    return 0;
}