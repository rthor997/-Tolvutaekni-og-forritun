#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* reverse_copy(const char* src, char* dst) {
    int n =strlen(src);
    for (int i = 0; i < n; i++) {
        dst[i] = src[n - 1 - i];
    }
    dst[n] = '\0';
    return dst;
}


char* reverse_inplace(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char tmp = str[i];
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = tmp;
    }
    return str;
}



int main() {
    const char* original = "Hallo Heimur!";
    char* buffer = malloc(strlen(original) + 1);
    char* inplace = malloc(strlen(original) + 1);

    strcpy(inplace, original);

    printf("Upprunalegur strengur: %s\n", original);

    /* reverse_copy */
    reverse_copy(original, buffer);
    printf("reverse_copy: %s\n", buffer);

    /* reverse_inplace */
    printf("Fyrir inplace: %s\n", inplace);
    reverse_inplace(inplace);
    printf("reverse_inplace: %s\n", inplace);

    free(buffer);
    free(inplace);
    return 0;
}
   