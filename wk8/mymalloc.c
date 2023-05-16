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

void coalesce(node_t* prev, node_t* next) {
    if (prev == NULL || !prev->avail || !next->avail) {
        return;
    }
    prev->next = next->next;
    prev->next->prev = prev;
}

void alloc_more(node_t* last) {
    void* ptr = sbrk(PAGE_SIZE);
    node_t* end = (node_t*) (ptr + PAGE_SIZE - sizeof(node_t));
    end->avail = false;
    end->next = NULL;
    end->prev = last;
    last->next = end;
    last->avail = true;
    coalesce(last->prev, last);
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

    for (;;) {
        if (node->next == NULL) {   // Reached last node
            alloc_more(node);
            continue;
        } else if (space(node) < size) {
            node = node->next;
            continue;
        } else {    // Found a spot
            break;
        }
    }
    
    // Device if we need to split the node
    if (space(node) > size + sizeof(node_t)) {
        node_t* mid = (node_t*) (((void*) node) +
        sizeof(node_t) + size);
        mid->avail = true;
        mid->next = node->next;
        mid->prev = node;
        node->next = mid;
    }

    node->avail = false;
    return ((void*) node + sizeof(node_t));
}


void myfree(void* ptr) {
    node_t* node = (node_t*) (ptr - sizeof(node_t));
    node->avail = true;
    coalesce(node, node->next);
    coalesce(node->prev, node);
}

int main() {
    void* p = mymalloc(10);
    myfree(p);
}