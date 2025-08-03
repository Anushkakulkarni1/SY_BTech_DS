#include <stdio.h>

int main() {
    int n = 5, temp;
    int player1[5], player2[5];

    printf("Enter scores of player1:\n");
    for (int l = 0; l < n; l++) {
        scanf("%d", &player1[l]);
    }

    printf("Enter scores of player2:\n");
    for (int v = 0; v < n; v++) {
        scanf("%d", &player2[v]);
    }

    // Sort player1 scores using bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (player1[j] > player1[j + 1]) {
                temp = player1[j];
                player1[j] = player1[j + 1];
                player1[j + 1] = temp;
            }
        }
    }

    printf("Scores of player1 sorted in ascending order:\n");
    for (int a = 0; a < n; a++) {
        printf("%d\n", player1[a]);
    }

    // Sort player2 scores
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (player2[j] > player2[j + 1]) {
                temp = player2[j];
                player2[j] = player2[j + 1];
                player2[j + 1] = temp;
            }
        }
    }

    printf("Scores of player2 sorted in ascending order:\n");
    for (int a = 0; a < n; a++) {
        printf("%d\n", player2[a]);
    }

    // Compare highest scores
    if (player1[n - 1] > player2[n - 1]) {
        printf("Player1 is the Winner!!!\n");
    } else if (player1[n - 1] == player2[n - 1]) {
        printf("There is a tie!!!\n");
    } else {
        printf("Player2 is the Winner!!!\n");
    }

    return 0;
}
