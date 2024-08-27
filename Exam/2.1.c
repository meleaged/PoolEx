#include <ctype.h>
#include <stdio.h>

#define MAX_LENGTH 1000

int main() {
    char str[MAX_LENGTH];

    printf("Введите строку:\n");
    fgets(str, sizeof(str), stdin);  // Чтение строки из ввода

    int i = 0;

    // Проверяем первый символ строки
    if (str[i] != '\0' && !isspace(str[i])) {
        str[i] = toupper(str[i]);
    }

    // Пробегаем по всем символам строки
    while (str[i] != '\0') {
        // Если текущий символ - пробел, пропускаем его
        if (str[i] == ' ') {
            // Проверяем следующий символ
            i++;
            if (str[i] != '\0' && !isspace(str[i])) {
                // Переводим в верхний регистр первый символ после пробела
                str[i] = toupper(str[i]);
            }
            continue;  // Переход к следующему символу
        }
        i++;
    }

    printf("Результат: %s", str);
    return 0;
}