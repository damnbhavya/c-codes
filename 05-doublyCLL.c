#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* prev;
    struct node* next;
};
struct node* insertEnd(struct node* head, int data) {
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    if (head == NULL) {
        n->prev = n;
        n->next = n;
        return n;
    }
    struct node* last = head->prev;
    n->next = head;
    n->prev = last;
    head->prev = n;
    last->next = n;
    return head;
}
void displayList(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* current = head;
    printf("Forward: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");

    current = head->prev;
    printf("Backward: ");
    do {
        printf("%d ", current->data);
        current = current->prev;
    } while (current != head->prev);
    printf("\n");
}
int main() {
    struct node* head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    printf("Doubly Circular Linked List:\n");
    displayList(head);
    return 0;
}


