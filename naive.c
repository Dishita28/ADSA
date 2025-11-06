#include <stdio.h>
#include <string.h>

void naiveStringMatch(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    int i, j;
    int found = 0;

    // Slide the pattern over text one by one
    for (i = 0; i <= n - m; i++) {
        // Check for match
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }

        // If pattern is found
        if (j == m) {
            printf("Pattern found at position %d\n", i + 1); // +1 for human counting
            found = 1;
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

    naiveStringMatch(text, pattern);

    return 0;
}
