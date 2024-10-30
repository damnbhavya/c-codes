#include <stdio.h>
#include <stdlib.h>

enum Color { RED, BLACK };

struct node {
    int data;
    enum Color color;
    struct node *l, *r, *parent;
};

struct node* newnode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->color = RED;
    newNode->l = newNode->r = newNode->parent = NULL;
    return newNode;
}

void leftRotate(struct node** root, struct node* x) {
    struct node* y = x->r;
    x->r = y->l;

    if (y->l != NULL) {
        y->l->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == NULL) {
        *root = y;
    } else if (x == x->parent->l) {
        x->parent->l = y;
    } else {
        x->parent->r = y;
    }

    y->l = x;
    x->parent = y;
}

void rightRotate(struct node** root, struct node* x) {
    struct node* y = x->l;
    x->l = y->r;

    if (y->r != NULL) {
        y->r->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == NULL) {
        *root = y;
    } else if (x == x->parent->r) {
        x->parent->r = y;
    } else {
        x->parent->l = y;
    }

    y->r = x;
    x->parent = y;
}

void fixViolation(struct node** root, struct node* z) {
    while (z != *root && z->parent->color == RED) {
        if (z->parent == z->parent->parent->l) {
            struct node* y = z->parent->parent->r;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->r) {
                    z = z->parent;
                    leftRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(root, z->parent->parent);
            }
        } else {
            struct node* y = z->parent->parent->l;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->l) {
                    z = z->parent;
                    rightRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}

void insert(struct node** root, int data) {
    struct node* newNode = newnode(data);
    struct node* y = NULL;
    struct node* x = *root;

    while (x != NULL) {
        y = x;
        if (newNode->data < x->data)
            x = x->l;
        else
            x = x->r;
    }

    newNode->parent = y;
    if (y == NULL) {
        *root = newNode;
    } else if (newNode->data < y->data) {
        y->l = newNode;
    } else {
        y->r = newNode;
    }

    fixViolation(root, newNode);
}

void inorderTraversal(struct node* root) {
    if (root == NULL) return;
    inorderTraversal(root->l);
    printf("%d(%s) ", root->data, root->color == RED ? "R" : "B");
    inorderTraversal(root->r);
}

int main() {
    struct node* root = NULL;

    int data[] = {10, 20, 30, 15, 25, 5, 1};
    for (int i = 0; i < 7; i++) {
        insert(&root, data[i]);
    }

    printf("Inorder Traversal of Created Red-Black Tree:\n");
    inorderTraversal(root);

    return 0;
}
