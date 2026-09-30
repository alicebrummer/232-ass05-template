
#include <stdio.h>
#include <iostream>
#include <format>
#ifndef UNITY_H
#define UNITY_H
#include "unity.h"
#include "code.hpp"
#endif
using namespace std;

// ============================================================
// Test Declarations — implemented in tests.cpp
// ============================================================

// STAGE 0
void test_printLegacyData_int(void);
void test_printLegacyData_double(void);

// STAGE 1
void test_createTwoStructNodes_links_correctly(void);

// STAGE 2
void test_createTwoClassNodes_links_correctly(void);

// STAGE 3
void test_createTwoTemplateNodes_links_correctly(void);

// STAGE 4
void test_linkedList_addFirst_updates_counter(void);
void test_linkedList_addLast_places_at_end(void);
void test_linkedList_deleteValue_removes_variant(void);
void test_linkedList_destroyList_clears_all(void);
void test_linkedList_deleteFirst(void);
void test_linkedList_deleteLast(void);
void test_linkedList_printList(void);

// ============================================================
// Required by Unity Framework
// ============================================================
void setUp(void)    {}
void tearDown(void) {}

// ============================================================
// Main Test Runner
// ============================================================
// class Node
// {
//     public: int value;
//     public: Node * nextPtr;


// };

// struct Struct
// {
//     int i;
//     double d;
//     char * cPtr;
// };

// struct Node
// {
//     int value;
//     Node * nextPtr;

// };






// union LegacyData
// {
//     int i;
//     double d;
//     char * cPtr;
// };



// template <typename T> // Static typing compile- time
// class classNodeT
// {
//     public: T value;
//     public: classNodeT = NULL;
// };

int main(void) 
{

    LegacyData data;
    data.i = 5;

    string test = printLegacyData(data, 'i');

    // Node node;
    // node.value = 5;
    // node.nextPtr = NULL;

    // classNodeT<int> nodeT;
    // nodeT.value = 5;
    // classNodeT<string> nodeT2;

    // nodeT2.value = "hello world";

    // cout << nodeT.value << endl;
    // cout << nodeT2.value << endl;

    // std::string formatted_str = std::format("my name is Alice {:.2}", name num ); << std endl;

    //printf("%d\n", sizeof(LegacyData));
    // LegacyData var;
    // var.d = 3.0;
    // printf("%d\n", var.d);
    // printf("%d\n", var.i);

    //printf("%d\n", sizeof(Struct));
}
//{
//     UNITY_BEGIN();

//     // ========== STAGE 0 ==========
//     RUN_TEST(test_printLegacyData_int);
//     RUN_TEST(test_printLegacyData_double);

//     // ========== STAGE 1 ==========
//     RUN_TEST(test_createTwoStructNodes_links_correctly);

//     // ========== STAGE 2 ==========
//     RUN_TEST(test_createTwoClassNodes_links_correctly);

//     // ========== STAGE 3 ==========
//     RUN_TEST(test_createTwoTemplateNodes_links_correctly);

//     // ========== STAGE 4 ==========
//     RUN_TEST(test_linkedList_addFirst_updates_counter);
//     RUN_TEST(test_linkedList_addLast_places_at_end);
//     RUN_TEST(test_linkedList_deleteValue_removes_variant);
//     RUN_TEST(test_linkedList_destroyList_clears_all);
//     RUN_TEST(test_linkedList_deleteFirst);
//     RUN_TEST(test_linkedList_deleteLast);
//     RUN_TEST(test_linkedList_printList);

//     int result = UNITY_END();
//     return result;
// }