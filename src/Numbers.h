//
// Created by work on 27.11.2024.
//

#ifndef C_VM_NUMBERS_H
#define C_VM_NUMBERS_H

#include <stdbool.h>
#include "Object.h"
#include "string.h"

bool Object_isNumber(Object* obj);

Object* Number_new();
Object* Number_sum(Object* left, Object* right);
Object* Number_mul(Object* left, Object* right);
Object* Number_sub(Object* left, Object* right);
char*   Number_makeString(Object* number);

#endif //C_VM_NUMBERS_H
