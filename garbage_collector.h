//
// Created by akaan on 16.04.2023.
//

#ifndef SMALLGARBAGECOLLECTOR_GARBAGE_COLLECTOR_H
#define SMALLGARBAGECOLLECTOR_GARBAGE_COLLECTOR_H

//This macro creates a control function for the given type to check if ptr list is null.

#define ISNULL(type)                            \
int isNull_##type(void* obj, void* ptr){        \
    type **p##type = (type**)obj;               \
    if(*p##type==NULL||*p##type!=ptr) return 1; \
    return 0;                                   \
}

typedef struct gc GarbageCollector;

struct gc
{
    int i,length;   //index and length of array.
    void **list;    //array of pointers
    void *address;  //address of allocated memory.
};

GarbageCollector *new_gc();
void *mem_alloc(void *adrsOfPtr, int size, int objSize, GarbageCollector *gc);
void *assign(void *addressOfDest, void *address, GarbageCollector *gc);
void check(GarbageCollector *gc, int (*isNull)(void*,void*));
#endif //SMALLGARBAGECOLLECTOR_GARBAGE_COLLECTOR_H
