#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int pairs[100] = {0};
    
    for (int i = 0; i < 10000; i++) {
        int first_digit = (int)(10.0 * rand() / (RAND_MAX + 1.0));
        int second_digit = (int)(10.0 * rand() / (RAND_MAX + 1.0));
        int pair_index = (first_digit * 10) + second_digit;
        pairs[pair_index]++;
    }
    
    for (int i = 0; i < 100; i++) {
        printf("Pair %02d: %.2f%%\n", i, (pairs[i] / 10000.0) * 100);
    }
    
    return 0;
}
