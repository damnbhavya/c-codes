#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node* link;
};
struct node* first;
void display() {
    struct node *ptr;
    ptr = first;
    while(ptr != NULL){
        printf("%d ", ptr->info);
        ptr = ptr->link;
    }
}
void insertbeg() {
    struct node *new;
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value to insert: ");
    scanf("%d", &new->info);
    new->link = first;
    first = new;
    printf("Node inserted\n");
    display();
}
void insertend() {
    struct node *new, *ptr;
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value to insert: ");
    scanf("%d", &new->info);
    new->link = NULL;
    if(first == NULL)
        first = new;
    else {
        ptr = first;
        while(ptr->link != NULL)
            ptr = ptr->link;
        ptr->link = new;
    }
    printf("Node inserted\n");
    display();
}
void insertmid() {
    struct node *new, *ptr;
    int val;
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value to insert: ");
    scanf("%d", &new->info);
    printf("Enter place value: ");
    scanf("%d", &val);
    ptr = first;
    while(ptr->info != val)
        ptr = ptr->link;
    new->link = ptr->link;
    ptr->link = new;
    printf("Node inserted\n");
    display();
}
void deletebeg() {
    struct node *ptr;
    ptr = first;
    first = first->link;
    free(ptr);
    printf("Node deleted\n");
    display();
}
void deleteend() {
    struct node *ptr, *temp;
    ptr = first;
    while(ptr->link != NULL){
        temp = ptr;
        ptr = ptr->link;
    }
    temp->link = NULL;
    free(ptr);
    printf("Node deleted\n");
    display();
}
void deletemid() {
    struct node *ptr, *temp;
    int data;
    printf("Enter the value to delete: ");
    scanf("%d", &data);
    ptr = first;
    while(ptr->info != data) {
        temp = ptr;
        ptr = ptr->link;
    }
    temp->link = ptr->link;
    free(ptr);
    printf("Node deleted\n");
    display();
}
int main() {
    int ch;
    while(1) {
        printf("\nOperations on linked list:");
        printf("\n1. Insert at beginning");
        printf("\n2. Insert at end");
        printf("\n3. Insert at middle");
        printf("\n4. Delete from beginning");
        printf("\n5. Delete from end");
        printf("\n6. Delete from middle");
        printf("\n7. Display");
        printf("\n8. Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: insertbeg();
                    break;
            case 2: insertend();
                    break;
            case 3: insertmid();
                    break;
            case 4: deletebeg();
                    break;
            case 5: deleteend();
                    break;
            case 6: deletemid();
                    break;
            case 7: display();
                    break;
            case 8: exit(0);
            default: printf("Invalid choice");
        }
    }
    return 0;
}


