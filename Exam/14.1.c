#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    char str[MAX_LEN];
    char prefix[MAX_LEN];
    char result[MAX_LEN * 2];  // Для хранения строки с префиксом

    // Запрос префикса у пользователя
    printf("Введите префикс: ");
    fgets(prefix, sizeof(prefix), stdin);
    prefix[strcspn(prefix, "\n")] = 0;  // Удаление символа новой строки

    // Запрос строки у пользователя
    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;  // Удаление символа новой строки

    // Формирование результирующей строки с префиксом
    strcpy(result, prefix);
    strcat(result, str);

    // Вывод результата
    printf("Результат: %s\n", result);

    return 0;
}