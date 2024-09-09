//
// Created by Timo Niemann on 11.06.24.
//
#include <stdio.h>
#include "malloc.h"

// contains the size of not allocated memory
static size_t free_size = MAX_HEAP_SIZE;
// allocated as static (not the keyword, the keyword says don't delete this variable)
// so the initial MAX_HEAP_SIZE is stored as bytes (char = 1 byte) on the heap
static char heap[MAX_HEAP_SIZE];

void *malloc(size_t size) {
    if(size == 0 || free_size < size)
        return NULL;
    free_size -= size;
    return heap - free_size;
}

void free(void *ptr) {
    // the free size would be the address of the heap - the address of the pointer to free
    // because the memory location is held together
    size_t size_to_free = heap - (char*)ptr;
    // increment the free size -> the next malloc would return an "old" memory address
    free_size += size_to_free;
}
