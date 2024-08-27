#include <stdio.h>

int main() {
    int a, b, c;

    // Считываем три целых числа
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("Invalid input\n");
        return 1;
    }

    // Логическое выражение (пример: (a > b) && (b < c))
    // Поменяйте логическое выражение на нужное вам
    int result = (a > b) && (b < c);

    // Выводим 0 или 1 в зависимости от значения result
    printf("%d\n", result);

    return 0;
}