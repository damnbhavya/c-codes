#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* link;
};
struct node* front = NULL;
struct node* rear = NULL;

void enqueue() {
    struct node* new = (struct node*)malloc(sizeof(struct node));
    printf("Enter value to add: ");
    scanf("%d", &new->data);
    new->link = NULL;
    if (rear == NULL && front == NULL)
        front = rear = new;
    else {
        rear->link = new;
        rear = new;
    }
}

void dequeue() {
    if (front == NULL)
        printf("Queue empty");
    if (front == rear) {
        struct node* temp = front;
        printf("Element deleted is: %d", temp->data);
        free(temp);
        front = rear = NULL;
    } else {
        struct node* temp = front;
        printf("Element deleted is: %d", temp->data);
        front = front->link;
        free(temp);
    }
}

void display() {
    struct node* temp = front;
    if (front == NULL)
        printf("Queue empty");
    else {
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->link;
        }
    }
    printf("\n");
}

int main() {
    int ch;
    while (1) {
        printf("\nOperations on Queue:");
        printf("\n1.Enqueue \n2.Dequeue \n3.Show queue");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            default: exit(0);
        }
    }
}