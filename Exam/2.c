#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char str[81];  // Массив для хранения строки
    char *ptr;

    printf("<< ");
    if (fgets(str, sizeof(str), stdin) == NULL) {  // Проверка на успешное считывание
        fprintf(stderr, "Ошибка при считывании строки.\n");
        return 1;  // Завершение программы с кодом ошибки
    }

    ptr = str;
    // Приведение первой буквы к верхнему регистру, если это буква
    if (isalpha(*ptr)) {
        *ptr = toupper(*ptr);
    }

    // Проход по строке и приведение первой буквы после пробела к верхнему регистру
    while (*ptr) {
        if (isblank(*(ptr - 1)) && isalpha(*ptr)) {
            *ptr = toupper(*ptr);
        }
        ++ptr;  // Переход к следующему символу
    }

    printf(">> %s", str);  // Вывод результата
    return 0;              // Успешное завершение программы
}