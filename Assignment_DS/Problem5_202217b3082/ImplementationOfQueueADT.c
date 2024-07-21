#include <stdio.h>
#include <stdlib.h>

#define n 5

void insert(int queue[], int *rear, int *j) {
    if (*rear == n) {
        printf("\n Queue is Full");
    } else {
        printf("\n Enter no %d: ", (*j)++);
        scanf("%d", &queue[(*rear)++]);
    }
}

void delete(int queue[], int *front, int *rear) {
    if (*front == *rear) {
        printf("\n Queue is empty");
    } else {
        printf("\n Deleted Element is %d", queue[(*front)++]);
    }
}

void display(int queue[], int front, int rear) {
    int i;
    printf("\n Queue Elements are:\n ");
    if (front == rear) {
        printf("\n Queue is Empty");
    } else {
        for (i = front; i < rear; i++) {
            printf("\n%d", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int queue[n], ch = 1, front = 0, rear = 0, i, j = 1;
    printf("Queue using Array");
    printf("\n1. Insertion \n2. Deletion \n3. Display \n4. Exit");

    while (ch) {
        printf("\nEnter the Choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insert(queue, &rear, &j);
                break;
            case 2:
                delete(queue, &front, &rear);
                break;
            case 3:
                display(queue, front, rear);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Wrong Choice: please see the options");
        }
    }
    return 0;
}