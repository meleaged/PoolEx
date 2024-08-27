#include <stdio.h>
#include <string.h>

#define PREFIX "-/"

int main() {
    char str[100];

    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);

    // Убираем символ новой строки, если он есть в конце строки
    str[strcspn(str, "\n")] = 0;

    if (strncmp(str, PREFIX, strlen(PREFIX)) == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}