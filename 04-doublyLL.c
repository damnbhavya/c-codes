#include <stdio.h>
#include <stdlib.h>
struct node {
    int info;
    struct node *lpt;
    struct node *rpt;
};
struct node *first;
void display() {
    struct node *ptr;
    ptr = first;
    while (ptr != NULL) {
        printf("%d\t", ptr->info);
        ptr = ptr->rpt;
    }
    printf("\n");
}
void insertbeg() {
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->lpt = NULL;
    printf("Enter the element to be inserted: ");
    scanf("%d", &ptr->info);
    ptr->rpt = first;
    first->lpt = ptr;
    first = ptr;
    printf("Element inserted!");
    display();
}
void insertend() {
    struct node *new, *prev;
    new = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter new element: ");
    scanf("%d", &new->info);
    prev = first;
    while (prev->rpt != NULL)
        prev = prev->rpt;
    new->lpt = prev;
    prev->rpt = new;
    new->rpt = NULL;
    printf("Element inserted!");
    display();
}
void insertmid() {
    int data;
    struct node *new, *prev;
    new = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the given data: ");
    scanf("%d", &data);
    printf("\nEnter new element: ");
    scanf("%d", &new->info);
    prev = first;
    while (prev->info != data)
        prev = prev->rpt;
    new->lpt = prev;
    new->rpt = prev->rpt;
    prev->rpt = new;
    new->rpt->lpt = new;
    printf("Element inserted!");
    display();
}
void deletebeg() {
    struct node *ptr;
    ptr = first;
    first = ptr->rpt;
    first->lpt = NULL;
    free(ptr);
    printf("Element deleted!");
    display();
}
void deleteend() {
    struct node *ptr, *prev;
    ptr = first;
    while (ptr->rpt != NULL) {
        prev = ptr;
        ptr = ptr->rpt;
    }
    prev->rpt = NULL;
    free(ptr);
    printf("Element deleted!");
    display();
}
void deletemid() {
    struct node *prev = NULL, *ptr = first;
    int data;
    if (first == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    printf("\nEnter the element you need to delete: ");
    scanf("%d", &data);
    while (ptr != NULL && ptr->info != data) {
        prev = ptr;
        ptr = ptr->rpt;
    }
    if (ptr == NULL) {
        printf("Element not found.\n");
        return;
    }
    if (ptr == first) {
        first = ptr->rpt;
        if (first != NULL) {
            first->lpt = NULL;
        }
    } else {
        prev->rpt = ptr->rpt;
        if (ptr->rpt != NULL) {
            ptr->rpt->lpt = prev;
        }
    }
    free(ptr);
    printf("Element deleted!\n");
    display();
}
int main() {
    char ch, choice = '1';
    struct node *new, *curent;
    curent = (struct node *)malloc(sizeof(struct node));
    printf("Enter the 1st info of the linked list: ");
    scanf("%d", &curent->info);
    first = curent;
    curent->lpt = NULL;
    curent->rpt = NULL;
    do {
        new = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the next node's info: ");
        scanf("%d", &new->info);
        curent->rpt = new;
        new->lpt = curent;
        curent = new;
        printf("\nDo you want to add more elements?y/n:");
        fflush(stdin);
        scanf("%c", &ch);
    } while (ch == 'y');
    curent->rpt = NULL;
    if (ch == 'n')
        display();
    while (choice != '0') {
        fflush(stdin);
        printf("1. Insert at starting \n");
        printf("2. insert at end \n");
        printf("3. insert after the given data \n");
        printf("4. delete the first node \n");
        printf("5. delete the last node \n");
        printf("6. delete the node of given data");
        printf("7. Exit \n");
        printf("Your choice: ");
        choice = getchar();
        switch (choice) {
        case '1': insertbeg();
                break;
        case '2': insertend();
                break;
        case '3': insertmid();
                break;
        case '4': deletebeg();
                break;
        case '5': deleteend();
                break;
        case '6': deletemid();
                break;
        case '7': exit(0);
        default: printf("Invalid choice!");
        }
    }
}
