#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int counts[10] = {0};
    
    for (int i = 0; i < 10000; i++) {
        int random_number = (int)(10.0 * rand() / (RAND_MAX + 1.0));
        counts[random_number]++;
    }
    
    for (int i = 0; i < 10; i++) {
        printf("Digit %d: %.2f%%\n", i, (counts[i] / 10000.0) * 100);
    }
    
    return 0;
}