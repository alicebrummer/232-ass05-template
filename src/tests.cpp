#ifndef UNITY_H
#define UNITY_H
#include "unity.h"
#endif

#include "code.hpp"
#include <sstream>
#include <iostream>

// ============================================================
// STAGE 0 Tests
// ============================================================

/// Create a LegacyData union with an int (42). Call printLegacyData.
/// Verify the returned string matches "42".
void test_printLegacyData_int(void) 
{
    LegacyData b;
    b.i= 42;

    std::string s = printLegacyData(b, 'i');
    TEST_ASSERT_TRUE_MESSAGE(s=="42", "s wasn't 42");
}

/// Create a LegacyData union with a double (3.14). Call printLegacyData.
/// Verify the returned string matches "3.14".
void test_printLegacyData_double(void) 
{
    LegacyData b;
    b.d= 3.14;

    std::string s = printLegacyData(b, 'd');
    TEST_ASSERT_TRUE_MESSAGE(s=="3.14", "s wasn't 3.14");
}

// ============================================================
// STAGE 1 Tests
// ============================================================

/// Call createTwoStructNodes().
/// Verify head->value contains int 5 with type 'i', and head->nextPtr->value contains double ~3.14 with type 'd'.
/// Clean up allocated memory.
void test_createTwoStructNodes_links_correctly(void) 
{
    structNode* j = createTwoStructNodes();
    TEST_ASSERT_TRUE_MESSAGE(j->value.i == 5, "doesnt = 5");
    TEST_ASSERT_TRUE_MESSAGE(j->typeData == 'i', "doesnt = i");

    TEST_ASSERT_TRUE_MESSAGE(j->nextPtr->value.d == 3.14, "doesnt = 3.14");
    TEST_ASSERT_TRUE_MESSAGE(j->nextPtr->typeData == 'd', "doesnt = d");

    delete j->nextPtr;
    delete j;
    
}

// ============================================================
// STAGE 2 Tests
// ============================================================

/// Call createTwoClassNodes().
/// Verify head->value contains int 5 with type 'i', and head->nextPtr->value contains double ~3.14 with type 'd'.
/// Clean up allocated memory.
void test_createTwoClassNodes_links_correctly(void) 
{
    classNode* j = createTwoClassNodes();
    TEST_ASSERT_TRUE_MESSAGE(j->value.i == 5, "doesnt = 5");
    TEST_ASSERT_TRUE_MESSAGE(j->typeData == 'i', "doesnt = i");

    TEST_ASSERT_TRUE_MESSAGE(j->nextPtr->value.d == 3.14, "doesnt = 3.14");
    TEST_ASSERT_TRUE_MESSAGE(j->nextPtr->typeData == 'd', "doesnt = d");
    
    delete j->nextPtr;
    delete j;
    
}

// ============================================================
// STAGE 3 Tests
// ============================================================

/// Call createTwoTemplateNodes().
/// Verify head->value is 5 and head->nextPtr->value is 3.
/// Clean up allocated memory.
void test_createTwoTemplateNodes_links_correctly(void) 
{
    classNodeT<int>* z = createTwoTemplateNodes();
    TEST_ASSERT_TRUE_MESSAGE(z->value == 5, "z = 5");
    TEST_ASSERT_TRUE_MESSAGE(z->nextPtr->value == 3, "z = 5");

    delete z->nextPtr;
    delete z;
}

// ============================================================
// STAGE 4: LinkedList Tests
// ============================================================

/// Create a LinkedList. Add two nodes using addFirst.
/// Verify listLength() returns 2 after insertions.
void test_linkedList_addFirst_updates_counter(void) 
{
    LinkedList* x = new LinkedList();
    classNodeVariant* y = new classNodeVariant(1);
    classNodeVariant* v = new classNodeVariant(2);
    x->addFirst(y);
    x->addFirst(v);
    TEST_ASSERT_TRUE_MESSAGE(x->listLength() == 2, "list length = 2");
    
}

/// Create a LinkedList. Add nodes (10, then 20) using addLast.
/// Capture std::cout and verify elements appear in order ("10" before "20").
void test_linkedList_addLast_places_at_end(void) 
{
    LinkedList* x = new LinkedList();
    classNodeVariant* y = new classNodeVariant(10);
    classNodeVariant* v = new classNodeVariant(20);
    x->addLast(y);
    x->addLast(v);
    TEST_ASSERT_TRUE_MESSAGE(y->nextPtr == v, " y = v");
    
}
/// Create a LinkedList with an int, double, and string.
/// Call deleteValue() with the double value (3.14).
/// Verify list length decreases to 2 and second call returns -1.
void test_linkedList_deleteValue_removes_variant(void) 
{

    LinkedList* x = new LinkedList();
    classNodeVariant* y = new classNodeVariant(1);
    classNodeVariant* v = new classNodeVariant(3.14);
    classNodeVariant* z = new classNodeVariant("test");
    x->addLast(y);
    x->addLast(v);
    x->addLast(z);
    x->deleteValue(3.14);
    int b = x->deleteValue(3.14);
    TEST_ASSERT_TRUE_MESSAGE(x->listLength() == 2, "list length = 2");
    TEST_ASSERT_TRUE_MESSAGE(b == -1, "list length = 2");
}





/// Create a LinkedList and insert three nodes.
/// Call destroyList().
/// Verify listLength() becomes 0.
void test_linkedList_destroyList_clears_all(void) 
{
    LinkedList* x = new LinkedList();
    classNodeVariant* y = new classNodeVariant(1);
    classNodeVariant* v = new classNodeVariant(2);
    classNodeVariant* z = new classNodeVariant(5);

    x->destroyList();
    TEST_ASSERT_TRUE_MESSAGE(x->listLength() == 0, "list length = 0");
}





/// Create a LinkedList with nodes (10, 20, 30).
/// Call deleteFirst().
/// Verify listLength() becomes 2 and operation returns 0.
void test_linkedList_deleteFirst(void) 
{
    LinkedList* x = new LinkedList();
    classNodeVariant* y = new classNodeVariant(10);
    classNodeVariant* v = new classNodeVariant(20);
    classNodeVariant* z = new classNodeVariant(30);
    x->addLast(y);
    x->addLast(v);
    x->addLast(z);
    x->deleteFirst();

    TEST_ASSERT_TRUE_MESSAGE(x->listLength() == 2, "list length = 2");
}




/// Create a LinkedList with nodes (10, 20, 30).
/// Call deleteLast().
/// Verify listLength() becomes 2 and operation returns 0.
void test_linkedList_deleteLast(void) 
{
    LinkedList* x = new LinkedList();
    classNodeVariant* y = new classNodeVariant(10);
    classNodeVariant* v = new classNodeVariant(20);
    classNodeVariant* z = new classNodeVariant(30);
    x->addLast(y);
    x->addLast(v);
    x->addLast(z);
    x->deleteLast();
    TEST_ASSERT_TRUE_MESSAGE(x->listLength() == 2, "list length = 30");
}




/// Create a LinkedList with nodes (1, 2.5, "test").
/// Redirect std::cout buffer and call printList().
/// Verify printed output contains "1", "2.5" (or "2.50"), and "test".
void test_linkedList_printList(void) 
{
    LinkedList* x = new LinkedList();
    classNodeVariant* y = new classNodeVariant(1);
    classNodeVariant* v = new classNodeVariant(2.5);
    classNodeVariant* z = new classNodeVariant("test");
    x->printList();
    std::cout << "1" << "2.5" << "test" << std::endl;
    TEST_ASSERT_TRUE_MESSAGE(0, "TODO: Implement this test");
    
}