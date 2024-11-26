//
// Created by work on 27.11.2024.
//
#include <minmax.h>
#include <malloc.h>
#include "Numbers.h"
#include "Object.h"

bool Object_isNumber(Object* obj) {
    return obj->type == NUMBER;
}

Object* Number_new() {
    Object* obj = Object_new();
    Object_initEmpty(obj, NUMBER, 1);
    return obj;
}

Object* Number_sum(Object* left, Object* right) {
    Object* result = Object_new();
    int rSize = max(left->size, right->size);
    if(left->chars[left->size-1] != 0 || right->chars[right->size-1] != 0)
        rSize += 1;
    Object_initEmpty(result, NUMBER, rSize);

    char rest = 0;
    int curPos;
    for(curPos=0; curPos < rSize; curPos++) {
        int bufres = 0;

        if(left->size > curPos) {
            bufres += left->chars[curPos];
        }
        if(right->size > curPos) {
            bufres += right->chars[curPos];
        }
        bufres += rest;
        if(bufres >= 256) {
            rest = 1;
            bufres %= 256;
        }
        result->chars[curPos] = (char)bufres;
    }
//    result->chars[curPos] += rest;

    return result;
}

Object* Number_mul(Object* left, Object* right) {}

Object* Number_sub(Object* left, Object* right) {}

char*   Number_makeString(Object* number) {
    int stringSize = number->size+1;
    char* result = malloc(stringSize);
    for(int i=0; i< number->size; i++) {
        result[i] = number->chars[i];
    }
    result[stringSize-1] = '\0';
    return result;
}
