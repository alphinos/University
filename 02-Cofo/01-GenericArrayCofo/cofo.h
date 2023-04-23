#ifndef _GCOFO_H_
#define _GCOFO_H_

typedef struct _gcofo_{
    int numItems;
    int maxItems;
    int curr;
    void* *items;
} gCofo;

gCofo *gCofCreate(int max_items);
int gCofInsert(gCofo *cofo, void* item);
void* gCofRemove(gCofo *cofo, void* key, int (*cmp)(void*, void*));
void* gCofQuery(gCofo *cofo, void* key, int (*cmp)(void*, void*));
void* gCofGetFirst(gCofo *cofo);
void* gCofGetNext(gCofo *cofo);
int cofDestroy(gCofo *cofo);

#endif