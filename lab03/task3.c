#include <stdio.h>

#define MAX_TEXT 255

int main(void)
{
    char str[MAX_TEXT + 1];

    printf("Enter text (up to 255 characters):\n");

    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Input error.\n");
        return 1;
    }

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }

        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = (char)(str[i] - ('a' - 'A'));
        }
    }

    printf("Result: %s\n", str);

    return 0;
}