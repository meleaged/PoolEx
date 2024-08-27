#include <stdio.h>
#include <stdlib.h>

void sort(int *arr, int size) {
    // Простой алгоритм сортировки (например, сортировка пузырьком)
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                // Обмен значениями
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int *arr = NULL;
    int size = 0;
    int num;

    printf("Введите последовательность чисел (для завершения введите -1):\n");

    while (1) {
        scanf("%d", &num);
        if (num == -1) {
            break;
        }
        // Увеличиваем размер массива
        int *temp = realloc(arr, (size + 1) * sizeof(int));
        if (temp == NULL) {
            // Выделение памяти не удалось
            free(arr);
            printf("Ошибка выделения памяти\n");
            return 1;
        }
        arr = temp;
        arr[size] = num;
        size++;
    }

    // Сортируем массив
    sort(arr, size);

    // Вывод отсортированного массива
    printf("Отсортированный массив:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Освобождаем память
    free(arr);

    return 0;
}