//
// Created by Timo Niemann on 11.06.24.
//
//-------------------------------------------------------------------------
// Warning this implementation is very simple and works by a LIFO principle
//-------------------------------------------------------------------------

#include <stdio.h>
#include "malloc.h"

// allocated as static (not the keyword, the keyword says don't delete this variable)
// so the initial MAX_HEAP_SIZE is stored as bytes (char = 1 byte) on the heap
static char heap[MAX_HEAP_SIZE];
// contains the size of allocated memory
static size_t allocated_size = 0;

void *malloc(size_t size) {
    // if we hae not enougth space return NULL
    if(size == 0 || allocated_size + size > MAX_HEAP_SIZE)
        return NULL;
    // get the address of the next free place
    void *ptr = heap + allocated_size;
    // increment allocated_size by the newly allocated size
    allocated_size += size;
    return ptr;
}

void free(void *ptr) {
    // the to free size would be the address of the heap - the address of the pointer to free
    // because the memory location is held together
    size_t size_to_free = heap - (char*)ptr;
    // decrement allocated_size -> the next malloc would return an "old" memory address
    allocated_size -= size_to_free;
}
