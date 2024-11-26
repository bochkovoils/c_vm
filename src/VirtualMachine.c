//
// Created by work on 26.11.2024.
//

#include <malloc.h>
#include "VirtualMachine.h"
#include "stdio.h"
#include "error.h"
#include "stdlib.h"


Chunk* Chunk_new() {
    Chunk* result = malloc(sizeof(Chunk));
    if(result == NULL) {
        return NULL;
    }
    result->size = 0;
    result->capacity = 0;
    return result;
}

void Chunk_delete(Chunk* chunk) {
    Chunk_clear(chunk);
    free(chunk);
}

void Chunk_clear(Chunk* chunk) {
    if(chunk->size != 0)
        free(chunk->data);
    chunk->data = NULL;
    chunk->size = 0;
    chunk->capacity = 0;
}

VirtualMachine* VM__new() {
    return 0;
}

void VM__delete(VirtualMachine* vm) {}