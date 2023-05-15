#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node {
    bool avail;
    struct node* prev;
    struct node* next;
} node_t;

static void* HEAP_BASE = NULL;
static int HEAP_SIZE = 0;
#define PAGE_SIZE 4096

int space(node_t* node) {
    if (! node->avail) {
        return 0;
    } else {
        // cast to void* to return the number of bytes
        return ((void*) node->next - 
            ((void*) node) - sizeof(node_t));
    }
}

void* mymalloc(int size) {
    if (HEAP_BASE = NULL) {
        HEAP_BASE = sbrk(PAGE_SIZE);    // Pointer to start of mem
        HEAP_SIZE = PAGE_SIZE;

        node_t* head = (node_t*) HEAP_BASE;
        node_t* tail = (node_t*) 
            (HEAP_BASE + HEAP_SIZE - sizeof(node_t));

        head->prev = NULL;
        head->next = tail;
        head->avail = true;

        tail->prev = head;
        tail->next = NULL;
        tail->avail = false;
    }

    // Walk down the linked list and find a slot that is free + fits
    node_t* node = (node_t*) HEAP_BASE;
    while (node != NULL && space(node) < size) {
        node = node->next;
    }

    // Check if you hit the end of the memory / nodes
    if (node == NULL) {
        // Must call sbrk again
    } else {
        // Found a slot...
        node->avail = false;
    }
}
