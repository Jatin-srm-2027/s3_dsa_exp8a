#include <stdio.h>
#include <stdbool.h>

#define MAX 100 // Maximum size of the queue

typedef struct {
    int front, rear, size;
    int array[MAX];
} Queue;

// Initialize the queue
void initializeQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// Check if the queue is full
bool isFull(Queue *q) {
    return q->size == MAX;
}

// Check if the queue is empty
bool isEmpty(Queue *q) {
    return q->size == 0;
}

// Enqueue operation
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->array[q->rear] = value;
    q->size++;
}

// Dequeue operation
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1; // Return a sentinel value
    }
    int value = q->array[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return value;
}

// Traverse the queue
void traverseQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    int i = q->front;
    for (int count = 0; count < q->size; count++) {
        printf("%d ", q->array[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Queue q;
    initializeQueue(&q);
    int choice, value;

    do {
        printf("\nArray-Based Queue Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;
            case 3:
                printf("Queue contents: ");
                traverseQueue(&q);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
