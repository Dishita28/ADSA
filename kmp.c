  #include <stdio.h>
#include <string.h>

// Function to compute the LPS (Longest Prefix Suffix) array
void computeLPSArray(char pattern[], int M, int lps[]) {
    int len = 0; // length of the previous longest prefix suffix
    int i = 1;
    lps[0] = 0; // first value is always 0

    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP pattern searching function
void KMPsearch(char text[], char pattern[]) {
    int N = strlen(text);
    int M = strlen(pattern);
    int lps[M];
    int i = 0; // index for text
    int j = 0; // index for pattern
    int found = 0;

    computeLPSArray(pattern, M, lps);

    while (i < N) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == M) {
            printf("Pattern found at position %d\n", i - j + 1);
            j = lps[j - 1];
            found = 1;
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    if (!found)
        printf("Pattern not found in the text.\n");
}

int main() {
    char text[100], pattern[50];

    printf("Enter the text: ");
    gets(text);

    printf("Enter the pattern to search: ");
    gets(pattern);

    KMPsearch(text, pattern);

    return 0;
}

AABAACAADAABAABA
AABA
