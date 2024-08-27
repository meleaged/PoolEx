#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL;  // Указатель на массив
    int value;
    int size = 0;  // Текущий размер массива

    printf("Введите числа (окончите ввод -1):\n");

    // Цикл для ввода чисел
    while (1) {
        scanf("%d", &value);
        if (value == -1) {
            break;  // Выход из цикла, если введено -1
        }

        // Увеличиваем размер массива
        int *temp = realloc(arr, (size + 1) * sizeof(int));
        if (temp == NULL) {
            free(arr);  // Освобождаем память в случае неудачи
            perror("Ошибка выделения памяти");
            return EXIT_FAILURE;
        }

        arr = temp;         // Обновляем указатель на массив
        arr[size] = value;  // Сохраняем введенное значение
        size++;             // Увеличиваем размер
    }

    // Суммируем элементы
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    // Выводим сумму
    printf("Сумма элементов массива: %d\n", sum);

    // Освобождаем память
    free(arr);
    return 0;
}