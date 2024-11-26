//
// Created by work on 27.11.2024.
//

#include "Object.h"
#include <stdlib.h>
#include <minmax.h>

Object* Object_new() {
    Object* result = (Object*)malloc(sizeof(Object));
    return result;
}

void Object_init(Object* obj, enum ObjectType type, unsigned int size, char* data) {
    obj->chars = data;
    obj->type = type;
    obj->size = size;
}

void Object_initEmpty(Object* obj, enum ObjectType type, unsigned int initSize) {
    obj->type = type;
    obj->size = initSize;
    obj->chars = malloc(initSize);
    if(obj->chars == NULL) {
    }
    for(int i=0; i<initSize; i++) {
        obj->chars[i] = 0;
    }
}

Object* Object_copy(Object* source, unsigned int newObjSize) {
    Object* result = Object_new();
    Object_initEmpty(source, source->type, newObjSize);
    for(int i=0; i<min(source->size, newObjSize); i++) {
        result->chars[i] = source->chars[i];
    }
    return result;
}

void Object_free(Object* obj) {}
