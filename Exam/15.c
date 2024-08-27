#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[256];  // Массив для хранения строки
    printf("Введите строку: ");
    fgets(input, sizeof(input), stdin);  // Считываем строку

    // Удаляем символ новой строки, если он есть
    input[strcspn(input, "\n")] = 0;

    // Определяем разделитель (пробел)
    char *token = strtok(input, " ");

    printf("Лексемы:\n");
    while (token != NULL) {
        printf("%s\n", token);      // Выводим текущую лексему
        token = strtok(NULL, " ");  // Получаем следующую лексему
    }

    return 0;
}