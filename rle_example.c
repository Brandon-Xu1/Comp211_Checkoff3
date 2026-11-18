/*
 * Compile: cc -std=c11 -Wall -Wextra rle_example.c -o rle_example
 * Run:     ./rle_example
 * Output:  (5,A) (2,B) (2,C) (1,D) (3,A)
 */
#include <stdio.h>

int main(void) {
    const char input[] = "AAAAABBCCDAAA";
    char current = input[0];
    int count = 1;

    for (int i = 1; input[i] != '\0'; i++) {
        if (input[i] == current) {
            count++;
        } else {
            printf("(%d,%c) ", count, current);
            current = input[i];
            count = 1;
        }
    }

    printf("(%d,%c)\n", count, current);
    return 0;
}
