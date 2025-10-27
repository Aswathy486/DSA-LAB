#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Function to add an element to the rear of the queue
void enqueue(int val) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert %d.\n", val);
        return;
    }
    // Initialize front for the very first element
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = val;
    printf("%d enqueued.\n", val);
}

// Function to remove an element from the front of the queue
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        return -1; // Indicate failure
    }
    int val = queue[front++];
    // Reset queue state if the last element was removed
    if (front > rear) {
        front = rear = -1;
    }
    return val;
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements (Front to Rear): ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    printf("--- Standard Queue Demo ---\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    printf("Dequeued element: %d\n", dequeue());
    display();

    enqueue(40);
    enqueue(50);
    enqueue(60); // Should show Overflow

    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());
    display();

    return 0;
}
