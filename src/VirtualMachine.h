//
// Created by work on 26.11.2024.
//

#ifndef C_VM_VIRTUALMACHINE_H
#define C_VM_VIRTUALMACHINE_H

struct Chunk_t {
    int     capacity;
    int     size;
    char*   data;
} typedef Chunk;

Chunk* Chunk_new    ();
void   Chunk_delete (Chunk* chunk);
void   Chunk_clear  (Chunk* chunk);

struct VirtualMachine_t {
    Chunk* chunks;
    int    size;
} typedef VirtualMachine;


VirtualMachine* VM__new();
void            VM__delete(VirtualMachine* vm);

#endif //C_VM_VIRTUALMACHINE_H
