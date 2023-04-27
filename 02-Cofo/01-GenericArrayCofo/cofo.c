// Discente: Carlos Eduardo Veras Gomes

#ifndef _COFO_C_
#define _COFO_C_

#include <stdio.h>
#include <stdlib.h>
#include "cofo.h"

gCofo *gCofCreate(int max_items){
    if (max_items <= 0)
        return NULL;
    gCofo *gcofo;
    gcofo = (gCofo*) malloc(sizeof(gCofo));
    if (gcofo == NULL){
        free(gcofo);
        return NULL;
    }
    gcofo->items = (void* *)malloc(sizeof(void*)*max_items);
    if (gcofo == NULL){
        free(gcofo);
        return NULL;
    }

    gcofo->numItems = 0;
    gcofo->maxItems = max_items;
    gcofo->curr = -1;
    return gcofo;
}

int gCofDestroy(gCofo *cofo){
    if (cofo == NULL)
        return FALSE;
    if (cofo->numItems != 0)
        return FALSE;
    free(cofo->items);
    free(cofo);
    return TRUE;
}

int gCofInsert(gCofo *cofo, void* item){
    if (cofo == NULL)
        return FALSE;
    if (cofo->numItems < cofo->maxItems)
        cofo->items[cofo->numItems] = item;
        cofo->numItems++;
        return TRUE;
    return FALSE;
}

void* gCofGetFirst(gCofo *cofo){
    void* elm;
    if (cofo == NULL)
        return NULL;
    if (cofo->numItems <= 0)
        return NULL;
    elm = cofo->items[0];
    cofo->curr = 0;
    return elm;
}

void* gCofGetNext(gCofo *cofo){
    void* elm;
    if (cofo == NULL)
        return NULL;
    if (cofo->numItems <= 0 || cofo->curr > cofo->numItems - 1)
        return NULL;
    cofo->curr++;
    elm = cofo->items[cofo->curr];
    return elm;
}

void* gCofQuery(gCofo *cofo, void* key, int (*cmp)(void*, void*)){
    if (cofo == NULL)
        return NULL;
    if (cofo->numItems <= 0)
        return NULL;
    int i, data, stat;
    i = 0;
    stat = cmp(cofo->items[i], key);
    while ( i < cofo->numItems && stat != TRUE ){
        i++;
        stat = cmp(cofo->items[i], key);
    }
    if (stat == TRUE)
        return cofo->items[i];
    return FALSE;
}

void* gCofRemove(gCofo *cofo, void* key, int (*cmp)(void*, void*)){
    if (cofo == NULL)
        return NULL;
    if (cofo->numItems <= 0)
        return NULL;
    int i;
    void* data;
    int stat;
    i = 0;
    stat = cmp(key, cofo->items[i]);
    while(i < cofo->numItems && stat != TRUE){
        i++;
        stat = cmp(key, cofo->items[i]);
    }
    if (stat == TRUE){
        data = cofo->items[i];
        for(int j = i; j < cofo->numItems; j++){
            cofo->items[j] = cofo->items[j + 1];
        }
        cofo->numItems--;
        return data;
    }
    return NULL;
}

void* gCofRemoveByIndex(gCofo *cofo, int i){
    if (cofo == NULL)
        return NULL;
    if (cofo->numItems <= 0)
        return NULL;
    if (i >= cofo->numItems)
        return NULL;
    void* data;
    data = cofo->items[i];
    for(int j = i; j < cofo->numItems; j++){
        cofo->items[j] = cofo->items[j + 1];
    }
    cofo->numItems--;
    return data;
}

#endif