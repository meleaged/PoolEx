#include <stdio.h>

int main() {
    char str[100];         // Массив для ввода строки
    int digits[10] = {0};  // Массив для отслеживания уникальных цифр
    int unique_count = 0;  // Счетчик уникальных цифр

    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);  // Чтение строки

    // Проходим по каждому символу в строке
    for (int i = 0; str[i] != '\0'; i++) {
        // Проверяем, является ли символ цифрой
        if (str[i] >= '0' && str[i] <= '9') {
            int digit = str[i] - '0';  // Преобразуем символ в цифру
            // Если цифра еще не встречалась, увеличиваем счетчик
            if (digits[digit] == 0) {
                digits[digit] = 1;  // Помечаем, что цифра встречалась
                unique_count++;     // Увеличиваем счетчик уникальных цифр
            }
        }
    }

    printf("Количество уникальных цифр в строке: %d\n", unique_count);

    return 0;
}