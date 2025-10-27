#include <stdio.h>
#define MAX 5

int cQueue[MAX];
int front = -1, rear = -1;

// Function to add an element to the rear of the circular queue
void enqueue(int val) {
    // Check for Overflow (Full condition)
    // Queue is full if front is immediately after rear (circularly)
    if (front == (rear + 1) % MAX) {
        printf("Circular Queue Overflow! Cannot insert %d.\n", val);
        return;
    }
    
    // Initialize front for the very first element
    if (front == -1) {
        front = 0;
    }
    
    // Move rear forward circularly and insert
    rear = (rear + 1) % MAX;
    cQueue[rear] = val;
    printf("%d enqueued.\n", val);
}

// Function to remove an element from the front of the circular queue
int dequeue() {
    // Check for Underflow (Empty condition)
    if (front == -1) {
        printf("Circular Queue Underflow!\n");
        return -1; // Indicate failure
    }
    
    int val = cQueue[front];
    
    // Check if this is the last element
    if (front == rear) {
        front = rear = -1; // Reset to empty state
    } 
    // Normal move forward circularly
    else {
        front = (front + 1) % MAX;
    }
    return val;
}

void display() {
    if (front == -1) {
        printf("Circular Queue is empty.\n");
        return;
    }
    
    int i = front;
    printf("Circular Queue elements: ");
    
    // Loop until the entire queue from front to rear is printed
    while (1) {
        printf("%d ", cQueue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    printf("--- Circular Queue Demo (MAX = %d) ---\n", MAX);
    
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    printf("Dequeued element: %d\n", dequeue()); // Dequeues 10
    display();
    
    enqueue(40);
    enqueue(50); 
    enqueue(60); // Should show Overflow (one slot is left empty to distinguish full/empty)
    display();

    printf("Dequeued element: %d\n", dequeue()); // Dequeues 20
    enqueue(60); // Insert 60 now possible as a slot is freed up
    display();

    printf("Dequeued element: %d\n", dequeue()); // Dequeues 30
    printf("Dequeued element: %d\n", dequeue()); // Dequeues 40
    printf("Dequeued element: %d\n", dequeue()); // Dequeues 50
    printf("Dequeued element: %d\n", dequeue()); // Dequeues 60
    
    printf("Dequeued element: %d\n", dequeue()); // Should show Underflow

    return 0;
}
