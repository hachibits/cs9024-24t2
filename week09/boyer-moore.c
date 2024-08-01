#include <stdlib.h>
#include <string.h>

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int *lastOccurrence(char *pattern, char *alphabet) {
    int patternSize = strlen(pattern);
    int alphabetSize = strlen(alphabet);

    int *lastOccur = (int *)malloc(sizeof(int) * 256); // ascii characters

    for (int i = 0; i < 256; i++)
        lastOccur[i] = -1;

    for (int i = 0; i < patternSize; i++)
        lastOccur[(int)pattern[i]] = i;

    return lastOccur;
}

int BoyerMooreMatch(char *text, char *pattern, char *alphabet) {
    int *L = lastOccurrence(pattern, alphabet);
    int n = strlen(text);
    int m = strlen(pattern);
    int i = m - 1;
    int j = m - 1;

    while (i < n) {
        if (text[i] == pattern[j]) {
            if (j == 0) {
                free(L);
                return i;
            } else {
                i--;
                j--;
            }
        } else {
            i = i + m - MIN(j, 1 + L[(int)text[i]]);
            j = m - 1;
        }
    }

    free(L);
    return -1;
}
