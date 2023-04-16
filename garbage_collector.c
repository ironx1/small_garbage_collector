//
// Created by akaan on 16.04.2023.
//

#include "garbage_collector.h"
#include <stdlib.h>
#include <stdio.h>

//Function to create and initialize a new garbage collector object
GarbageCollector *new_gc(){
    GarbageCollector *gc = malloc(sizeof(GarbageCollector));
    gc->i = gc->length = 0;
    gc->list = gc->address = 0;
    return gc;
}

//memory allocation function
void *mem_alloc(void *adrsOfPtr, int size, int objSize, GarbageCollector *gc){
    gc->list = malloc(++gc->length*sizeof(void*));
    gc->list[gc->i++] = adrsOfPtr;
    gc->address = malloc(objSize*size);
    return gc->address;
}

//Function to assign a pointer to another pointer
void *assign(void *addressOfDest, void *address, GarbageCollector *gc){
    gc->list = realloc(gc->list,++gc->length*sizeof(void*));
    gc->list[gc->i++] = addressOfDest;
    return address;
}

//Function to check if assigned pointers are null or not equal
void check(GarbageCollector *gc, int (*isNull)(void*,void*)){
    if(gc->address==NULL) return;
    int flag=0;
    for (int i = 0; i < gc->length; ++i) {
        if(isNull(gc->list[i], gc->address)>0) flag++;
    }
    if(flag==gc->length&&flag!=0){
        free(gc->address);
        free(gc->list);
        free(gc);
        printf("memory freed");
        return;
    }
    printf("list is not null");
}
