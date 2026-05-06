#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int odd_count = 0, even_count = 0;
    
    for (int i = 0; i < 10000; i++) {
        int random_number = (int)(10.0 * rand() / (RAND_MAX + 1.0));
        if (random_number % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }
    
    printf("Even: %.2f%%\n", (even_count / 10000.0) * 100);
    printf("Odd: %.2f%%\n", (odd_count / 10000.0) * 100);
    
    return 0;
}