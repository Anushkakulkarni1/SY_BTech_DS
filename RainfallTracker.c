#include <stdio.h>

int main() {
    float rainfall[3][4];
    float total = 0.0, avg = 0.0;

    
    printf("\nEnter rainfall data for 3 cities (in mm):\n");

    // Input data
    for (int c = 0; c < 3; c++) {
        printf("\nEnter data for City %d:\n", c + 1);
        for (int m = 0; m < 4; m++) {
            printf("Month %d: ", m + 1);
            scanf("%f", &rainfall[c][m]);
        }
    }

    // Report in tabular form 
    printf("\n\t\tRainfall Tracking Report (in mm)\n");
    printf("-------------------------------------------------------------\n");
    printf("S.No.\tCity\tMonth1\tMonth2\tMonth3\tMonth4\tAverage\n");
    printf("-------------------------------------------------------------\n");

    for (int c = 0; c < 3; c++) {
        total = 0.0;
        printf("%d\tCity %d", c + 1, c + 1);
        for (int m = 0; m < 4; m++) {
            printf("\t%.2f", rainfall[c][m]);
            total += rainfall[c][m];
        }
        avg = total / 4.0;
        printf("\t%.2f\n", avg);
    }

    printf("-------------------------------------------------------------\n");
    return 0;
}
