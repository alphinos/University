//Carlos Eduardo Veras Gomes - 3º período 

#ifndef _GCOFO_H_
#define _GCOFO_H_

#define TRUE 1
#define FALSE 0

typedef struct _gcofo_{
    int numItems;
    int maxItems;
    int curr;
    void* *items;
} gCofo;

gCofo *gCofCreate(int max_items);
int gCofInsert(gCofo *cofo, void* item);
void* gCofRemove(gCofo *cofo, void* key, int (*cmp)(void*, void*));
void* gCofRemoveByIndex(gCofo *cofo, int i);
void* gCofQuery(gCofo *cofo, void* key, int (*cmp)(void*, void*));
void* gCofGetFirst(gCofo *cofo);
void* gCofGetNext(gCofo *cofo);
int gCofDestroy(gCofo *cofo);

#endif