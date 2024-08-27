#include <stdio.h>

int main() {
    long long number;
    printf("Введите целое число: ");
    scanf("%lld", &number);

    // Преобразуем число в положительное значение.
    if (number < 0) {
        number = -number;
    }

    int max_digit = -1;  // Инициализируем переменную для максимальной цифры.

    // Находим максимальную цифру.
    while (number > 0) {
        int digit = number % 10;  // Получаем последнюю цифру.
        if (digit > max_digit) {
            max_digit = digit;  // Обновляем максимальную цифру.
        }
        number /= 10;  // Удаляем последнюю цифру.
    }

    printf("Максимальная цифра: %d\n", max_digit);
    return 0;
}