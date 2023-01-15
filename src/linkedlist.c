#include <stdlib.h>
#include <string.h>

#include "../include/linkedlist.h"

/**
 * Initializes a LinkedList struct.
 *
 * @param this The struct to be initialized
 */
void LinkedList_init(struct LinkedList * this) {
    this->size = 0;
    this->head = NULL;
}

/**
 * Initializes a Node struct.
 *
 * @param this The struct to be initialized
 * @param data The data to be stored in the Node
 */
void Node_init(struct Node * this, const char * data) {
    strcpy(this->data, data);
    this->next = NULL;
}

/**
 *
 * @brief Adds a new node to the linked list
 *
 * This function creates a new node with the given data, and adds it to the
 * end of the linked list.
 *
 * @param llist pointer to the linked list
 * @param data data to be stored in the new node
 *
 * @example
 *  struct LinkedList * myList = createLinkedList();
 *  addNode(myList, "Hello World");
 *  addNode(myList, "Hello Again");
 *
 * Output:
 *  A linked list with two nodes, the first one containing "Hello World"
 *  and the second one "Hello Again"
 *
 */
void addNode(struct LinkedList * llist, char * data) {
    struct Node * new_node = (struct Node *) malloc(sizeof(struct Node));
    struct Node * current = llist->head;

    Node_init(new_node, data);

    if (llist->head == NULL) {
        llist->head = new_node;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    llist->size++;
}

/**
 *
 * @brief Inserts a new node with given data at a specified position in the
 * linked list
 *
 * This function creates a new node with the given data and insert it at a
 * specified position in the linked list.
 *
 * @param llist pointer to the linked list
 * @param data data to be stored in the new node
 * @param index position in the linked list where the new node should be inserted
 *
 * @example
 *  struct LinkedList llist;
 *  LinkedList_init(llist);
 *  addNode(&llist, "Hello World");
 *  addNode(&llist, "Hello Again");
 *  insertNodeAt(&llist, "Inserted Node", 1);
 *
 * Output:
 *  A linked list with three nodes, the first one containing "Hello World",
 *  the second one "Inserted Node" and the third one "Hello Again"
 *
 */
void insertNodeAt(struct LinkedList * llist, char * data, int index) {
    struct Node * new_node = (struct Node *) malloc(sizeof(struct Node));
    struct Node * current = llist->head;

    Node_init(new_node, data);

    if (index == 0) {
        new_node->next = current;
        llist->head = new_node;
    }

    if (index >= 0 && index <= llist->size) {
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    llist->size++;
}

/**
 *
 * @brief Removes a node from the linked list with a specified data
 *
 * This function removes the first node from the linked list that contains
 * the specified data.
 *
 * @param llist pointer to the linked list
 * @param data data to be removed
 *
 * @example
 *  struct LinkedList llist;
 *  LinkedList_init(llist);
 *  addNode(&llist, "Hello World");
 *  addNode(&llist, "Hello Again");
 *  removeNode(&llist, "Hello World");
 *
 * Output:
 *  A linked list with one node containing "Hello Again"
 *
 */
void removeNode(struct LinkedList * llist, const char * data) {
    struct Node * current = llist->head;
    struct Node * previous = (struct Node *) malloc(sizeof(struct Node));

    Node_init(previous, "NULL");

    if (llist->size == 0) {
        return;
    }

    if (llist->size == 1 && current->data == data) {
        llist->head = NULL;
        free(current);
        llist->size--;

        return;
    }

    while (current != NULL) {
        if (strcmp(current->data, data) == 0) {
            previous->next = current->next;
            free(current);
            llist->size--;
            return;
        }
        previous = current;
        current = current->next;
    }
}