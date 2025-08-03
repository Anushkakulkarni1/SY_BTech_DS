#include <stdio.h>
int main() {
    int i, j, n = 5;
    int cards[5];
    int key;
    printf("Enter the numbers:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", & cards[i]);
    }
    // Insertion Sort
    for (i = 1; i < n; i++) {
        key = cards[i];
        j = i - 1;
        while (j >= 0 && cards[j] > key) {
            cards[j + 1] = cards[j];
            j--;
        }
        cards[j + 1] = key;
    }
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", cards[i]);
    }
    printf("\n");
    return 0;
}

