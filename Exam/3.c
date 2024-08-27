 
#include <stdio.h>
#include <string.h>

void remove_last_occurrence(char *str, const char *substr) {
    char *pos = strstr(str, substr);  // находим последнее вхождение подстроки
    if (pos != NULL) {
        size_t len = strlen(substr);
        memmove(pos, pos + len, strlen(pos + len) + 1);  // сдвигаем оставшуюся часть строки
    }
}

char *strrstr(const char *haystack, const char *needle) {
    char *result = NULL;
    char *last = strstr(haystack, needle);
    while (last != NULL) {
        result = last;                    // запоминаем текущее вхождение
        last = strstr(last + 1, needle);  // ищем следующее вхождение
    }
    return result;  // возвращаем последнее вхождение
}

int main() {
    char str[100];
    char substr[50];

    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;  // удаляем символ новой строки

    printf("Введите подстроку для удаления: ");
    fgets(substr, sizeof(substr), stdin);
    substr[strcspn(substr, "\n")] = 0;  // удаляем символ новой строки

    remove_last_occurrence(str, substr);

    printf("Результат: %s\n", str);

    return 0;
}
