#include <stdio.h>
#include <conio.h>

#define MAX 10

// Function declarations
void create();
void insert();
void deletion();
void search();
void display();

// Global variables
int b[MAX], n = 0;

// Main function
void main() {
    int ch;
    char g = 'y';
    
    do {
        printf("\n Main Menu");
        printf("\n 1. Create \n 2. Delete \n 3. Search \n 4. Insert \n 5. Display \n 6. Exit \n");
        printf("\n Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                return; // Exit the program
            default:
                printf("\n Enter the correct choice:");
        }

        printf("\n Do you want to continue (y/n): ");
        scanf(" %c", &g);
    } while (g == 'y' || g == 'Y');

    getch();
}

// Create function
void create() {
    printf("\n Enter the number of elements: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("\n Exceeds maximum limit of %d", MAX);
        n = 0;
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("\n Enter the element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

// Deletion function
void deletion() {
    int pos;
    printf("\n Enter the position you want to delete: ");
    scanf("%d", &pos);

    if (pos >= n || pos < 0) {
        printf("\n Invalid location");
    } else {
        for (int i = pos; i < n - 1; i++) {
            b[i] = b[i + 1];
        }
        n--;
        printf("\n The elements after deletion are:");
        display();
    }
}

// Search function
void search() {
    int e, found = 0;
    printf("\n Enter the element to be searched: ");
    scanf("%d", &e);

    for (int i = 0; i < n; i++) {
        if (b[i] == e) {
            printf("\n Value %d is in position %d", e, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\n Value %d is not in the list", e);
    }
}

// Insert function
void insert() {
    int pos, p;
    if (n >= MAX) {
        printf("\n The list is full");
        return;
    }

    printf("\n Enter the position you need to insert: ");
    scanf("%d", &pos);

    if (pos > n || pos < 0) {
        printf("\n Invalid location");
    } else {
        for (int i = n; i > pos; i--) {
            b[i] = b[i - 1];
        }
        printf("\n Enter the element to insert: ");
        scanf("%d", &p);
        b[pos] = p;
        n++;
        printf("\n The list after insertion is:");
        display();
    }
}

// Display function
void display() {
    printf("\n The elements of the list ADT are:");
    for (int i = 0; i < n; i++) {
        printf("\n%d", b[i]);
    }
}