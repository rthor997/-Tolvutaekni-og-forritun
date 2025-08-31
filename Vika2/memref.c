typedef struct {
    int a[8];
    double d;

} struct_t;


double fun(int i) {
    volatile struct_t s;
    s.d = 3.14;
    s.a[i] = 1073741824; /* Possibly out of bounds */
    return s.d;
}

int main() {
    for (int i = 0; i < 10; i++) {
        printf("fun(%d) --> %f\n", i, fun(i));
    }
    return 0;
    
}