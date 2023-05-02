#include <stdio.h>
#include <stdlib.h>
// A node in a tree
typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} tree_t;
tree_t *make_node(int value, tree_t *left, tree_t *right) {
    tree_t *node = (tree_t *)malloc(sizeof(tree_t));
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}
// add_tree takes a tree_t** since it has to change the
// original value of the tree
void add_tree(tree_t **t, int value) {
    if (*t == NULL) {
        *t = make_node(value, NULL, NULL);
    } else if (value < (*t)->value) {
        add_tree(&((*t)->left), value);
    } else {
        add_tree(&((*t)->right), value);
    }
}
// print tree using an in-order traversal
void print_tree(tree_t *t) {
    if (t == NULL) {
        // do nothing
    } else {
        print_tree(t->left);
        printf(" %d ", t->value);
        print_tree(t->right);
    }
}
// Return leftmost value of the tree
int find_leftmost(tree_t *t) {
    for (; t->left != NULL; t = t->left)
        ;
    return t->value;
}
// delete the node with the value
void delete_node(tree_t **t, int value) {
    if ((*t)->value == value) {
        // This is the node to delete
        if ((*t)->left == NULL && (*t)->right == NULL) {
            // The node to delete has no children
            free(*t);
            *t = NULL;
        } else if ((*t)->left == NULL) {
            // The node has only a right child
            // The right child takes over
            tree_t *right = (*t)->right;
            free(*t);
            *t = right;
        } else if ((*t)->right == NULL) {
            // The node has only a left child
            // The left child takes over
            tree_t *left = (*t)->left;
            free(*t);
            *t = left;
        } else {
            // The node has two children
            int leftvalue = find_leftmost((*t)->right);
            delete_node(&((*t)->right), leftvalue);
            // replace value in current node
            (*t)->value = leftvalue;
        }
    } else if (value < (*t)->value) {
        // must delete in the left tree
        delete_node(&((*t)->left), value);
    } else {
        // must delete in the right tree
        delete_node(&((*t)->right), value);
    }
}
// delete and free the whole tree
void free_tree(tree_t **t) {
    if (*t == NULL) {
        return;
    } else {
        free_tree(&((*t)->left));
        free_tree(&((*t)->right));
        free(*t);
        *t = NULL;
    }
}

void delete_tree(tree_t **t, int value) {
    if (value < (*t)->value) {
        delete_tree(&((*t)->left), value);
    } else if (value > (*t)->value) {
        delete_tree(&((*t)->right), value);
    } else {
        // Found the node to delete
        if ((*t)->left == NULL && (*t)->right == NULL) {
            // leaf node - no children
            free_tree(t);
        } else if ((*t)->left == NULL) {
            // Has one right child
            tree_t* right = (*t)->right;
            free(*t);
            *t = right;
        } else if ((*t)->right == NULL) {
            // Has one left child
            tree_t* left = (*t)->left;
            free(*t);
            *t = left;
        } else {
            // Has two children
            tree_t* leftchild = (*t)->left;
            tree_t* rightsubtree = (*t)->left->right;
            (*t)->left->right = (*t)->right;
            free(*t);
            *t = leftchild;
            attach_leftmost(&((*t)->right), rightsubtree);
        }
    }
}

void attach_leftmost(tree_t** t, tree_t* subtree) {
    if (*t == NULL) {
        *t = subtree;
    } else {
        attach_leftmost(&((*t)->left), subtree);
    }
}

int main() {
    // tree_t* t = make_node(42, NULL, NULL);
    tree_t *t1 = NULL;  // make an empty tree
    add_tree(&t1, 42);  // add a value to a tree
    add_tree(&t1, 17);
    add_tree(&t1, 55);
    add_tree(&t1, 50);
    add_tree(&t1, 20);
    add_tree(&t1, 20);
    print_tree(t1);
    printf("\n");
    delete_tree(&t1, 42);
    print_tree(t1);
    free_tree(&t1);
}