#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
    if (argc != 3) {
        fprintf(stderr, "Notkun: %s n k\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int k = atoi(argv[2]);

    if (n <= 0 || k <= 0) {
        fprintf(stderr, "n og k verða að vera jákvæðar heiltölur.\n");
        return 1;
    }

    int *a = calloc(n, sizeof(int));
    if (a == NULL) {
        perror("calloc");
        return 1;
    }

    srand(time(0)); /* tryggir að slembirunan breytist milli keyrslna */ 


    int interations = k * n; 
    for (int i = 0; i < interations; i++) {
        int r = rand() % n; /* slembitala á bilinu [0 .. n-1] */
        a[r] += 1;
    }

    int holfCount = 0; 
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            holfCount++;
        }
    }
    double fraction = 100.0 * holfCount / n;

    printf("Eftir %d ítranir eru %d hólf ennþá 0, eða %.1f%%\n", 
            interations, holfCount, fraction);

    free(a);
    return 0; 
}   