#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int is_palindrome(const char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        // Пропускаем неалфавитные символы и приводим к нижнему регистру
        while (left < right && !isalnum(str[left])) left++;
        while (left < right && !isalnum(str[right])) right--;

        if (tolower(str[left]) != tolower(str[right])) {
            return 0;  // Не палиндром
        }

        left++;
        right--;
    }

    return 1;  // Палиндром
}

int main() {
    char str[MAX_LENGTH];

    printf("Введите строку: ");
    fgets(str, MAX_LENGTH, stdin);
    str[strcspn(str, "\n")] = 0;  // Удаляем символ новой строки

    if (is_palindrome(str)) {
        printf("Строка является палиндромом.\n");
    } else {
        printf("Строка не является палиндромом.\n");
    }

    return 0;
}