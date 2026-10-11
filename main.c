#include <stdio.h>
#include <time.h>

int UPPER_BOUND = 10;

int main(void) {

    clock_t begin = clock();

    for (int i = 0; i < UPPER_BOUND; ++i) {
        printf("Tap here...!\n");
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent: %f\n", time_spent);


    return 0;
}
