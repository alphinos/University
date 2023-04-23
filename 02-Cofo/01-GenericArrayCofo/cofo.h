#ifndef _GCOFO_H_
#define _GCOFO_H_

typedef struct _gcofo_{
    int numItems;
    int maxItems;
    int curr;
    void* *items;
} gCofo;

#ifdef _GCOFO_C

gCofo *gCofCreate(int max_items);
int gCofInsert(gCofo *cofo, void* item);
void* gCofRemove(gCofo *cofo, void* key);
void* gCofQuery(gCofo *cofo, void* key);
void* gCofGetFirst(gCofo *cofo);
void* gCofGetNext(gCofo *cofo);
int cofDestroy(gCofo *cofo);

#else

extern gCofo *gCofCreate(int max_items);
extern int gCofInsert(gCofo *cofo, void* item);
extern void* gCofRemove(gCofo *cofo, void* key);
extern void* gCofQuery(gCofo *cofo, void* key);
extern void* gCofGetFirst(gCofo *cofo);
extern void* gCofGetNext(gCofo *cofo);
extern int cofDestroy(gCofo *cofo);

#endif

#endif