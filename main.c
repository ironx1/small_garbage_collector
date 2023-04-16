//
// Created by akaan on 16.04.2023.
//
#include "garbage_collector.h"
#include "string.h"

typedef struct person{
    char *name;
    int age;
}Person;

ISNULL(Person)
ISNULL(char)

int main(void){
    GarbageCollector *gc_person = new_gc();
    GarbageCollector *gc_name = new_gc();
    Person *p = mem_alloc(&p, 1, sizeof(Person), gc_person);
    p->name = mem_alloc(&p->name, 5, 1, gc_name);
    p->age = 34;
    strcpy(p->name, "kaan");
    p->name = NULL;
    p = NULL;
    check(gc_name,isNull_char);
    check(gc_person,isNull_Person);
}