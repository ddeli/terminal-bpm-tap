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
int main(void) {

    printf("Tap multiple times on any key to calculate tempo\n");
    printf("\n");
    printf("Press \"q\" to quit\n");

    while (!IS_PRESSED) {
        if (_kbhit()) { // Check if a key has been pressed
            char ch = _getch();
            begin = clock();
            IS_PRESSED = 1;
            break;
        }
    }

    while (1) {
        if (_kbhit()) {
            char ch = _getch();
            end = clock();

            double calculated_bpm = 1/((double)(end - begin) / CLOCKS_PER_SEC) * 60 ;

            printf("--------------- BPM : %f\n", calculated_bpm);
            printf("--------------- TapIndex : %f\n", taps[tapindex]);

            end = 0;
            begin = 0;
            begin = clock();
            if (ch == 113) { // 113 is the ASCII code for 'q'
                break;
            }
        }
    }

    return 0;
}
