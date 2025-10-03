// алгоритм Кнута-Морисса-Пратта (O(n + m))

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int length(char *s) {
    int k = 0;
    while (s[k] != '\0') {
        k++;
    }

    return k;
}

void compute_lps(char *pattern, int len_p, int *lps) {
    int l = 0;
    int i = 0;
    lps[i++] = 0;

    while (i < len_p) {
        if (pattern[i] == pattern[l]) {
            lps[i++] = ++l;
        } else {
            if (l) {
                l = lps[l - 1];
            } else {
                lps[i++] = 0;
            }
        }
    }
}

void kmp(char *text, char *pattern) {
    int len_p = length(pattern);
    int len_t = length(text);

    int i = 0;
    int j = 0;

    int f = 0;

    int *lps = (int *)malloc(sizeof(int) * len_p);
    compute_lps(pattern, len_p, lps);

    while (i < len_t) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == len_p) {
            printf("%d %d\n", ++f, i - j);
            j = lps[j - 1];
        } else if (i < len_t && text[i] != pattern[j]) {
            if (j) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    if (!f) {
        printf("Not found!\n");
    }
}

int main() {
    char text[] = "abadcabadad";
    char pattern[] = "abada";

    kmp(text, pattern);
    return 0;
}