#include <stdio.h>
#include <string.h>

void remove_last_occurrence(char *str, const char *sub) {
    char *last_occurrence = NULL;
    size_t sub_len = strlen(sub);

    // Найти последнее вхождение подстроки
    char *current = str;
    while ((current = strstr(current, sub)) != NULL) {
        last_occurrence = current;
        printf("current %s\n", current);
        current += sub_len;  // Перемещаемся дальше для поиска следующих вхождений
    }

    // Если нашли последнее вхождение, удаляем его
    if (last_occurrence != NULL) {
        memmove(last_occurrence, last_occurrence + sub_len, strlen(last_occurrence + sub_len) + 1);
    }
}

int main() {
    char str[100];
    char sub[50];
    fgets(str, 100, stdin);
    fgets(sub, 50, stdin);
    str[strcspn(str, "\n")] = 0;
    sub[strcspn(sub, "\n")] = 0;
    remove_last_occurrence(str, sub);
    printf("После удаления последнего вхождения подстроки: %s\n", str);

    return 0;
}
