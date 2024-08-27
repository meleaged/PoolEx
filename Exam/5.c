#include <stdio.h>
#include <stdlib.h>  // Используем stdlib.h вместо malloc.h

void swapFirstAndLastDigit(int arr[], int size) {
    if (size < 2) {
        return;  // Нечего менять, если всего одна или нет цифр
    }

    // Меняем местами первую и последнюю цифру
    int temp = arr[0];
    arr[0] = arr[size - 1];
    arr[size - 1] = temp;
}

int main() {
    int count = 0;
    int *arr = NULL;  // Начинаем с NULL
    printf("Введите последовательность чисел, заканчивающуюся -1:\n");

    // Ввод последовательности
    while (1) {
        int num;
        scanf("%d", &num);
        if (num == -1) {
            break;  // Завершаем ввод, если введен -1
        }

        count++;
        int *arr_new = realloc(arr, count * sizeof(int));
        if (arr_new == NULL) {
            free(arr);  // Освобождаем старую память в случае ошибки
            fprintf(stderr, "Ошибка при выделении памяти\n");
            return 1;  // Выйти с ошибкой
        }
        arr = arr_new;         // Обновляем указатель на массив
        arr[count - 1] = num;  // Заполняем массив
    }

    // Меняем местами первую и последнюю цифры
    swapFirstAndLastDigit(arr, count);

    // Выводим измененную последовательность
    printf("Измененная последовательность:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);  // Освобождаем память после работы с массивом
    return 0;
}