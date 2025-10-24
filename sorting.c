#include <stdio.h>

#define MAX 100

long long steps;

// Swap function that increments step count
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
    steps++; // count swap as a step
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    steps = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            steps++; // comparison
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    } 
    printf("Bubble Sort steps: %lld\nSorted array: ", steps);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    steps = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            steps++; // comparison
            if (arr[j] > key) {
                arr[j+1] = arr[j];
                steps++; // shift counted as step
                j--;
            } else {
                break;
            }
        }
        arr[j+1] = key;
        steps++; // insertion counted as step
    }
    printf("Insertion Sort steps: %lld\nSorted array: ", steps);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

// Quick Sort helper: partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        steps++; // comparison
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quick Sort recursive function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merge function to merge two sorted halves
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        steps++; // comparison
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
            steps++; // assignment
        } else {
            arr[k++] = R[j++];
            steps++; // assignment
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
        steps++;
    }

    while (j < n2) {
        arr[k++] = R[j++];
        steps++;
    }
}

// Merge Sort recursive function
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    int arr[MAX], b[MAX], ins[MAX], q[MAX], m[MAX];

    printf("Enter number of elements (max %d): ", MAX);
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        b[i] = ins[i] = q[i] = m[i] = arr[i]; // Copy array for each sort
    }

    bubbleSort(b, n);

    insertionSort(ins, n);

    steps = 0;
    quickSort(q, 0, n - 1);
    printf("Quick Sort steps: %lld\nSorted array: ", steps);
    for (int i = 0; i < n; i++) printf("%d ", q[i]);
    printf("\n");

    steps = 0;
    mergeSort(m, 0, n - 1);
    printf("Merge Sort steps: %lld\nSorted array: ", steps);
    for (int i = 0; i < n; i++) printf("%d ", m[i]);
    printf("\n");

    return 0;
}
