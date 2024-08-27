#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL;  // динамический массив
    int size = 0;     // размер массива
    int num;

    printf("Введите числа, последовательность оканчивается на -1:\n");

    // Чтение ввода до -1
    while (1) {
        scanf("%d", &num);
        if (num == -1) {
            break;  // заканчиваем ввод
        }

        // Увеличиваем размер массива
        int *temp = realloc(arr, (size + 1) * sizeof(int));
        if (temp == NULL) {
            free(arr);
            printf("Ошибка выделения памяти!\n");
            return 1;
        }
        arr = temp;
        arr[size] = num;  // добавляем новое число
        size++;
    }

    // Проверка на случай пустого массива
    if (size == 0) {
        printf("Массив пуст!\n");
        free(arr);
        return 0;
    }

    // Сортировка в стиле 162534
    int *result = malloc(size * sizeof(int));  // массив на выходе
    if (result == NULL) {
        free(arr);
        printf("Ошибка выделения памяти для результатирующего массива!\n");
        return 1;
    }

    int left = 0;          // Указатель на начало
    int right = size - 1;  // Указатель на конец

    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            // Четные индексы - берем из начала
            result[i] = arr[left++];
        } else {
            // Нечетные индексы - берем из конца
            result[i] = arr[right--];
        }
    }

    // Вывод отсортированного результата
    printf("Результат сортировки: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Освобождение памяти
    free(arr);
    free(result);
    return 0;
}