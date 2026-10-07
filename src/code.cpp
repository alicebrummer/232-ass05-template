// ============================================================
// CSCI 232 Assignment 05 – Evolution of Data Structures
// Student Implementation
// ============================================================
// Author: [Alice Brummer]
// ============================================================

#include "code.hpp"
#include <iostream>
#include <format>

// ============================================================
// STAGE 0: Legacy C Union
// ============================================================

/// Converts a LegacyData union to a formatted string.
/// Format specs:
/// 'i' -> integer value as string (e.g., "42")
/// 'd' -> double value formatted to 2 decimal places (e.g., "3.14")
/// 'c' -> string pointer content (or "nullptr" if cPtr is null)
/// default -> "unknown"

std::string printLegacyData(LegacyData data, char type) 
{
    std::string result = "unknown";

    if(type == 'i')
        result = std::format("{}", data.i );
    if(type == 'd')
        result = std::format("{}", data.d );
    if(type == 'c')
        if(data.cPtr != NULL)
            result = std::format("{}", data.cPtr );
            
    return result;
}

    

// ============================================================
// STAGE 1: C-Style Struct
// ============================================================

/// Initializes a structNode with value, type indicator, and nullptr nextPtr.
void initStructNode(structNode* nPtr, LegacyData val, char type) {
    nPtr->value = val;
    nPtr->nextPtr = NULL;
    nPtr->typeData = type;
}

/// Dynamically allocates two structNodes.
/// Node 1: int 5 ('i')
/// Node 2: double 3.14 ('d')
/// Links Node 1 -> Node 2 -> nullptr
/// Returns pointer to Node 1.
structNode* createTwoStructNodes() {
    structNode* a = new structNode;
    LegacyData t;
    t.i = 5;
    initStructNode(a, t, 'i');


    structNode* b = new structNode;
    LegacyData e;
    e.d = 3.14;
    initStructNode(b, e, 'd');

    a->nextPtr = b;
    return a;
}

// ============================================================
// STAGE 2: Early C++ Class (Classic Constructor)
// ============================================================

/// Constructor: Assign fields inside curly braces.
/// DO NOT use member initializer lists here!

// uncomment the following code to implement the classNode constructor

classNode::classNode(LegacyData val, char type) {
    {
        if(type == 'i')
            value.i = val.i;    //int i = (int)3.0 + 1;
                             //value = val;        // value is a struct
                                //.. 'c' 'd'
        if(type == 'c')
            value.cPtr = val.cPtr;
        if(type == 'd')
            value.d = val.d;
        typeData = type;
        nextPtr = NULL;
    }
//     // TODO: Assign value, typeData, and set nextPtr to nullptr
}

/// Dynamically allocates two classNodes (int 5, double 3.14) and links them.
classNode* createTwoClassNodes() {
    LegacyData x;
    LegacyData y;
    x.i = 5;
    y.d = 3.14;

    classNode* s = new classNode(x, 'i');
    classNode* t = new classNode(y, 'd');
    s->nextPtr = t;
    return s;
}

// ============================================================
// STAGE 3: C++98 Templates
// ============================================================

/// Dynamically allocates two classNodeT<int> objects (int 5, int 3) and links them.
classNodeT<int>* createTwoTemplateNodes() {

    classNodeT<int>* k = new classNodeT<int>(5);
    classNodeT<int>* r = new classNodeT<int>(3);

    k->nextPtr = r;
    // TODO: Instantiate classNodeT<int> nodes using new, link them, and return head
    return k;
}

// Function:
// int sum(int a, int b)
// {
//     return a+b;
// }

//Method:
// class Math


// ============================================================
// STAGE 4: C++17 Variant and LinkedList Manager
// ============================================================

// uncomment the following code to implement the LinkedList methods

// LinkedList::LinkedList() {
//     // TODO: Initialize headPtr to nullptr and counter to 0
// }

// LinkedList::~LinkedList() {
//     // TODO: Clean up memory by calling destroyList()
// }
//uncoment the following code to implement the LinkedList methods

// void LinkedList::destroyList() {
//     // TODO: Iterate through list, delete all nodes, and reset counter to 0
// }

// int LinkedList::addFirst(classNodeVariant* newNodePtr) {
//     // TODO: Prepend node to the front of list, increment counter
//     // Return -1 if newNodePtr is nullptr, 0 on success
//     return -1;
// }

// int LinkedList::addLast(classNodeVariant* newNodePtr) {
//     // TODO: Append node to the end of list, increment counter
//     // Return -1 if newNodePtr is nullptr, 0 on success
//     return -1;
// }

// int LinkedList::deleteFirst() {
//     // TODO: Delete first node, update headPtr, decrement counter
//     // Return -1 if list is empty, 0 on success
//     return -1;
// }

// int LinkedList::deleteLast() {
//     // TODO: Find second-to-last node, delete last node, decrement counter
//     // Return -1 if list is empty, 0 on success
//     return -1;
// }

// int LinkedList::deleteValue(ModernData targetValue) {
//     // TODO: Traverse list, find node matching targetValue, unlink and delete it
//     // Decrement counter
//     // Return 0 if found and removed, -1 if not found or list is empty
//     return -1;
// }

// int LinkedList::printList() {
//     // TODO: Iterate through list and print each variant value to std::cout
//     // Use std::holds_alternative or std::get
//     // Return -1 if list is empty, 0 on success
//     return -1;
// }

// int LinkedList::listLength() {
//     // TODO: Return node count
//     return 0;
// }