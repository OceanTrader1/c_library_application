/**
 * @file linkedlist.h
 * @brief A simple implementation of a singly linked list
 *
 * The LinkedList struct contains a head pointer and a size variable.
 * The Node struct contains a data field and a next pointer.
 *
 * The following functions are provided for manipulation of the linked list:
 * - void LinkedList_init(struct LinkedList * this)
 *    Initializes the linked list by setting the size to 0 and the head pointer to NULL
 * - void Node_init(struct Node * this, const char * data)
 *    Initializes a new node with the given data and sets the next pointer to NULL
 * - void removeNode(struct LinkedList * llist, const char * data)
 *    Removes the node containing the given data from the list
 * - void addNode(struct LinkedList * llist, char * data)
 *    Adds a new node containing the given data to the end of the list
 * - void insertNodeAt(struct LinkedList * llist, char * data, int index)
 *    Inserts a new node containing the given data at the specified index in the list
 */

#ifndef LIBRARY_LINKEDLIST_H
#define LIBRARY_LINKEDLIST_H
#endif

struct Node {
    char data[100];  // the hashed value
    struct Node * next;
};

struct LinkedList {
    int size;
    struct Node * head;
};

void LinkedList_init(struct LinkedList * this);

void Node_init(struct Node * this, const char * data);

void removeNode(struct LinkedList * llist, const char * data);

void addNode(struct LinkedList * llist, char * data);

void insertNodeAt(struct LinkedList * llist, char * data, int index);