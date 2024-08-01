#include <stdlib.h>
#include <assert.h>
#include <string.h>

int *failure(char *pattern) {
    int m = strlen(pattern);
    int *F = malloc(m * sizeof(int));
    assert(F != NULL);

    F[0] = 0;

    int i = 1;
    int j = 0;

    while (i < m) {
        if (pattern[i] == pattern[j]) {
            F[i++] = ++j;
        } else if (j > 0) {
            j = F[j-1];
        } else {
            F[i++] = 0;
        }
    }
    return F;
}

int kmp(char *text, char *pattern, int *F) {
    int i = 0, j = 0;
    while (i < strlen(text)) {
        if (text[i] == pattern[j]) {
            if (j == strlen(pattern)-1) {
                return i-j;
            } else {
                i++;
                j++;
            }
        } else if (j > 0) {
            j = F[j-1];
        } else {
            i++;
        }
    }
    return -1;
}
