#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL;  // Массив для хранения чисел
    int size = 0;     // Текущий размер массива
    int number;       // Вводимое число

    // Чтение последовательности чисел
    printf("Введите числа (введите -1 для завершения):\n");
    while (1) {
        scanf("%d", &number);
        if (number == -1) {
            break;  // Завершение ввода
        }
        // Расширение массива
        arr = realloc(arr, (size + 1) * sizeof(int));
        if (arr == NULL) {
            fprintf(stderr, "Ошибка выделения памяти\n");
            return 1;  // Завершение программы в случае ошибки
        }
        arr[size] = number;
        size++;
    }

    if (size == 0) {
        printf("Последовательность пуста.\n");
        free(arr);
        return 0;  // Если последовательность пуста
    }

    // Поиск наибольшего и наименьшего значений
    int minIndex = -1, maxIndex = -1;
    int minValue = __INT_MAX__, maxValue = -1;

    for (int i = 0; i < size; i++) {
        if (arr[i] >= 0) {
            if (arr[i] < minValue) {
                minValue = arr[i];
                minIndex = i;
            }
            if (arr[i] > maxValue) {
                maxValue = arr[i];
                maxIndex = i;
            }
        }
    }

    // Меняем местами первый найденный минимальный и максимальный элемент
    if (minIndex != -1 && maxIndex != -1 && minIndex != maxIndex) {
        int temp = arr[minIndex];
        arr[minIndex] = arr[maxIndex];
        arr[maxIndex] = temp;
    }

    // Вывод результата
    printf("Результат:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Освобождение памяти
    free(arr);
    return 0;
}