#include <stdio.h>
#define EMPTY_SLOT -1
int main() {
    int hash[10];
    int n, key, i, index;
    for (i = 0; i < 10; i++)
        hash[i] = EMPTY_SLOT;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        index = key % 10;
        while (hash[index] !=EMPTY_SLOT)
            index = (index + 1) % 10;
        hash[index] = key;
    }
    printf("\nHash Table:\n");
    for (i = 0; i < 10; i++)
        printf("%d : %d\n", i, hash[i]);
    return 0;
}