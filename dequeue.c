#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

// --- Insertion Operations ---

void insertFront(int val) {
    // Check for full condition
    if (front == 0 && rear == MAX - 1) {
        printf("Deque full! Cannot insert %d.\n", val);
        return;
    }
    // Check if there is space to move back in a linear array
    if (front == 0 && rear != -1) {
        printf("Front boundary reached. Cannot insert %d at front.\n", val);
        return;
    }
    // Initialization
    if (front == -1) {
        front = rear = 0;
    }
    // Normal move backward
    else {
        front--;
    }
    deque[front] = val;
    printf("Inserted %d at front.\n", val);
}

void insertRear(int val) {
    // Check for full condition
    if (front == 0 && rear == MAX - 1) {
        printf("Deque full! Cannot insert %d.\n", val);
        return;
    }
    // Initialization
    if (rear == -1) {
        front = rear = 0;
    }
    // Normal move forward
    else {
        rear++;
    }
    deque[rear] = val;
    printf("Inserted %d at rear.\n", val);
}

// --- Deletion Operations ---

int deleteFront() {
    if (front == -1) {
        printf("Deque empty!\n");
        return -1;
    }
    int val = deque[front];
    // Reset if last element
    if (front == rear) {
        front = rear = -1;
    }
    // Normal move forward
    else {
        front++;
    }
    return val;
}

int deleteRear() {
    if (rear == -1) {
        printf("Deque empty!\n");
        return -1;
    }
    int val = deque[rear];
    // Reset if last element
    if (front == rear) {
        front = rear = -1;
    }
    // Normal move backward
    else {
        rear--;
    }
    return val;
}

void display() {
    if (front == -1) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque elements (Front to Rear): ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

int main() {
    printf("--- Double-Ended Queue (Deque) Demo ---\n");

    insertRear(100);
    insertFront(90);
    insertFront(80);
    display();

    printf("Deleted Front: %d\n", deleteFront());
    display();
    
    printf("Deleted Rear: %d\n", deleteRear());
    display();

    insertRear(200);
    insertRear(300);
    insertRear(400); // Should show full or boundary message
    display();
    
    insertFront(70); // Should show front boundary reached
    
    return 0;
}
