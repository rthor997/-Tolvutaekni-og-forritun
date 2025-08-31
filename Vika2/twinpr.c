#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*Skilar 1 ef k er frumtala */
int isprime(long k) {
    if (k < 2) return 0;
    if (k == 2) return 1;
    if (k % 2 == 0) return 0;

    long limit = (long) sqrt((double)k);
    for (long i = 3; i <= limit; i += 2) {
        if (k % i == 0 ) return 0;
    }
    return 1; 
}

int main(int argc, char *argv[]) {
      if (argc != 2) {
        fprintf(stderr, "Notkun: %s n\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]); /*Breytum stafinum á skipunarlínu í heiltölu */
    int count = 0;
    long p = 3;

    while (count < n) {
        if (isprime(p) && isprime(p+2)) {
            printf("%ld og %ld\n", p, p + 2);
            count++;    
        }
      p++;    
    }
    return 0;
}