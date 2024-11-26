//
// Created by work on 27.11.2024.
//

#ifndef C_VM_OBJECT_H
#define C_VM_OBJECT_H

enum ObjectType {
    NUMBER,
    STRING
};

typedef struct Object {
    enum ObjectType type;
    unsigned int size;
    unsigned char* chars;
} Object;

Object* Object_new();
void Object_init(Object* obj, enum ObjectType, unsigned int size, char* data);
void Object_initEmpty(Object* obj, enum ObjectType type, unsigned int initSize);
Object* Object_copy(Object* source, unsigned int newObjSize);
void Object_free(Object*);

#endif //C_VM_OBJECT_H
