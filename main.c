#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

int UPPER_BOUND = 10;
int IS_PRESSED = 0;

clock_t begin;
clock_t end;

int tapindex = 0;
double taps[100];

double calculated_bpm = -1.0;
double average_bpm = 0.0;
int main(void) {

    printf("\e[1;1H\e[2J");
    printf("\n");
    printf("Tap multiple times on the space key to calculate tempo\n");
    printf("\n");
    printf("Press \"q\" to quit\n");
    printf("\n");
    printf("\n");

    while (!IS_PRESSED) {
        if (_kbhit()) { // Check if a key has been pressed
            char ch = _getch();
            if (ch == 32) {
                begin = clock();
                IS_PRESSED = 1;
                printf("   BPM Calculation started...");
                break;
            }

        }
    }

    while (1) {
        if (_kbhit()) {
            printf("\e[1;1H\e[2J");
            printf("\n");
            printf("Tap multiple times on the space key to calculate tempo\n");
            printf("\n");
            printf("Press \"q\" to quit\n");
            printf("\n");
            printf("\n");

            char ch = _getch();
            if (ch == 32) {

                end = clock();

                double calculated_bpm = 1/((double)(end - begin) / CLOCKS_PER_SEC) * 60 ;
                taps[tapindex] = calculated_bpm;

                tapindex++;
                for (int i = 0; i <= tapindex; i++) {
                    average_bpm = (average_bpm + taps[i]);
                }
                average_bpm =  average_bpm / tapindex;


                printf("   %f BPM\n", average_bpm);

                end = 0;
                begin = 0;


                if (tapindex >= 99) {
                    printf("\n");
                    printf("\n");
                    printf("100 Taps are enough !!!\n");
                    printf("\n");
                    printf("\n");
                    break;
                }
            }
            begin = clock();
            if (ch == 113) { // 113 is the ASCII code for 'q'
                break;
            }
        }
    }

    return 0;
}
