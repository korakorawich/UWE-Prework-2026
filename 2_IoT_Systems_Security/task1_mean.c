#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    double sum = 0;
    
    for (int i = 0; i < 1000; i++) {
        int random_number = (int)(10.0 * rand() / (RAND_MAX + 1.0));
        sum += random_number;
    }
    
    printf("Mean Test Result: %.2f\n", sum / 1000.0);
    return 0;
}
