//
// Created by work on 27.11.2024.
//

#ifndef C_VM_TEST_NUMBERS_H
#define C_VM_TEST_NUMBERS_H

#include <stdbool.h>
#include "stdio.h"

#define assert(form, message) if(!(form)) { printf(message); return false;}
#define TEST(index, name) bool TEST_##index() { printf("\n-----------TEST-----------\n"); printf(name);
#define ENDTEST printf("\n---------SUCCESS----------\n"); return true; }
#define CALL_TEST(index) TEST_##index();

#include "Numbers.h"

TEST(NEW, "Hello, world")
    Object* number = Number_new();
    assert(number->size == 1, "Invalid number size!")
    assert(number->chars[0] == 0, "Invalid chars value!")
ENDTEST

TEST(SUM_1, "Sum of 1 and 2 is 3")
    Object* left = Number_new();
    Object* right = Number_new();
    left->chars[0] = 1;
    right->chars[0] = 2;

    Object* sum = Number_sum(left, right);
    assert(sum->chars[0] == 3, "Invalid chars value");
    assert(sum->size == 2, "Invalid sum size");
ENDTEST

TEST(SUM_2, "Sum of 255 and 1 is equal 256")
    Object* left = Number_new();
    Object* right = Number_new();
    left->chars[0] = (char)255;
    right->chars[0] = 1;

    Object* sum = Number_sum(left, right);
    assert(sum->chars[0] == 0 && sum->chars[1] == 1, "Invalid chars value in sum 2 values with overriding");
    assert(sum->size == 2, "Invalid sum size");
ENDTEST

bool TEST_Numbers_sum_3() {
    Object* left = Number_new();
    Object* right = Number_new();
    left->chars[0] = (char)255;
    right->chars[0] = 1;

    Object* sum = Number_sum(left, right);
    assert(sum->chars[0] == 0 && sum->chars[1] == 1, "Invalid chars value in sum 2 values with overriding");
    assert(sum->size == 2, "Invalid sum size");
    return true;
}

bool TEST_NUMBERS_ALL() {
    bool result;
    result = CALL_TEST(NEW);
    result &= CALL_TEST(SUM_1);
    result &= CALL_TEST(SUM_2);
    result &= TEST_Numbers_sum_3();
    return result;
}



#endif //C_VM_TEST_NUMBERS_H
