#include <stdio.h>
#include <time.h>
#include <conio.h>

int UPPER_BOUND = 10;
int IS_PRESSED = 0;

clock_t begin;
clock_t end;

double calculated_pbm = -1.0;
int main(void) {

    printf("Tap on any key to calculate tempo\n");
    printf("\n");
    printf("Press \"q\" to quit\n");

    while (!IS_PRESSED) {
        if (_kbhit()) { // Check if a key has been pressed
            clock_t begin = clock();
            IS_PRESSED = 1;
            break;
        }
    }
    while (1) {
        if (_kbhit()) {
            clock_t end = clock();

            double bpm_count = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("bpm_count: %f\n",bpm_count);

            printf("--------------- BPM : %d ---------------\n", "TEST");
            clock_t begin = clock();
            char ch = _getch(); // Get the key without echoing it
            printf("You pressed: %d\n", ch);
            if (ch == 113) { // 113 is the ASCII code for 'q'
                break;
            }
        }
    }

    return 0;
}
