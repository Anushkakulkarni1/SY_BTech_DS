#include <stdio.h>

int main() {
    float temp[3][7], cityAvg[3], dayAvg[7];
    int c, d;

    printf("\nAnushka Abhay Kulkarni 824CE1102\n");
    printf("\nTemperature data for 3 cities over 7 days:\n");

    // Input temperatures
    for (c = 0; c < 3; c++) {
        printf("\nEnter temperatures for City %d for 7 days:\n", c + 1);
        for (d = 0; d < 7; d++) {
            printf("Day %d: ", d + 1);
            scanf("%f", &temp[c][d]);
        }
    }

    // Calculate city-wise average
    for (c = 0; c < 3; c++) {
        float sum = 0;
        for (d = 0; d < 7; d++) {
            sum += temp[c][d];
        }
        cityAvg[c] = sum / 7.0;
    }

    // Calculate day-wise average
    for (d = 0; d < 7; d++) {
        float sum = 0;
        for (c = 0; c < 3; c++) {
            sum += temp[c][d];
        }
        dayAvg[d] = sum / 3.0;
    }

    
    printf("\n\t\tTemperature Tracker (in Celsius)\n");
    printf("---------------------------------------------------------------\n");
    printf("Sr.No\tDay1\tDay2\tDay3\tDay4\tDay5\tDay6\tDay7\tCity Avg\n");
    printf("---------------------------------------------------------------\n");

    for (c = 0; c < 3; c++) {
        printf("%d\t", c + 1);
        for (d = 0; d < 7; d++) {
            printf("%.2f\t", temp[c][d]);
        }
        printf("%.2f\n", cityAvg[c]);
    }

    printf("---------------------------------------------------------------\n");
    printf("DayAvg\t");
    for (d = 0; d < 7; d++) {
        printf("%.2f\t", dayAvg[d]);
    }
    printf("\n");

    return 0;
}
