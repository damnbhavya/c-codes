#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* l;
    struct node* r;
};
struct node* newnode(int data) {
    struct node* new;
    new = (struct node*)malloc(sizeof(struct node));
    if (new == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new->data = data;
    new->l = NULL;
    new->r = NULL;
    return new;
}
struct node* insert(struct node* root, int data) {
    if (root == NULL)
        return newnode(data);
    if (data < root->data)
        root->l = insert(root->l, data);
    else if (data > root->data)
        root->r = insert(root->r, data);
    return root;
}
struct node* findmin(struct node* node) {
    struct node* cur = node;
    while (cur && cur->l != NULL)
        cur = cur->l;
    return cur;
}
struct node* delnode(struct node* root, int data) {
    if (root == NULL)
        return root;
    if (data < root->data)
        root->l = delnode(root->l, data);
    else if (data > root->data)
        root->r = delnode(root->r, data);
    else {
        if (root->l == NULL) {
            struct node* temp = root->r;
            free(root);
            return temp;
        } else if (root->r == NULL) {
            struct node* temp = root->l;
            free(root);
            return temp;
        }
        struct node* temp = findmin(root->r);
        root->data = temp->data;
        root->r = delnode(root->r, temp->data);
    }
    return root;
}
struct node* search(struct node* root, int data) {
    if (root == NULL || root->data == data)
        return root;
    if (data < root->data)
        return search(root->l, data);
    return search(root->r, data);
}
void inOrderTraversal(struct node* root) {
    if (root != NULL) {
        inOrderTraversal(root->l);
        printf("%d ", root->data);
        inOrderTraversal(root->r);
    }
}
int main() {
    struct node* root = NULL;
    int ch, data;
    do {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. In-order Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = delnode(root, data);
                break;
            case 3:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (search(root, data) != NULL)
                    printf("Element found in the BST.\n");
                else
                    printf("Element not found.\n");
                break;
            case 4:
                printf("In-order Traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 5:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (ch != 5);
    return 0;
}


