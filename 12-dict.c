#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
int size = 0;
char keys[MAX_SIZE][100];
int values[MAX_SIZE];

int getIndex(char key[]){
    for (int i = 0; i < size; i++) {
        if (strcmp(keys[i], key) == 0) {
            return i;
        }
    }
    return -1;
}

void insert(char key[], int value){
    int index = getIndex(key);
    if (index == -1) {
        strcpy(keys[size], key);
        values[size] = value;
        size++;
    } else {
        values[index] = value;
    }
}

int get(char key[]){
    int index = getIndex(key);
    if (index == -1) {
        return -1;
    } else {
        return values[index];
    }
}

void printMap(){
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", keys[i], values[i]);
    }
}

int main(){
    int choice;
    char key[100];
    int value;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Get\n");
        printf("3. Print Map\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%s", key);
                printf("Enter value: ");
                scanf("%d", &value);
                insert(key, value);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%s", key);
                value = get(key);
                if (value == -1) {
                    printf("Key not found.\n");
                } else {
                    printf("Value: %d\n", value);
                }
                break;
            case 3:
                printf("Value of complete Map: \n");
                printMap();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
