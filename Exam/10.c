#include <stdio.h>

// Определяем структуру для представления 3D-вектора
typedef struct {
    int x;
    int y;
    int z;
} Vector;

// Функция для вычисления скалярного произведения двух векторов
int dot_product(Vector v1, Vector v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }

int main() {
    Vector vec1, vec2;

    // Считываем первый вектор
    printf("Введите координаты первого вектора (x y z): ");
    scanf("%d %d %d", &vec1.x, &vec1.y, &vec1.z);

    // Считываем второй вектор
    printf("Введите координаты второго вектора (x y z): ");
    scanf("%d %d %d", &vec2.x, &vec2.y, &vec2.z);

    // Вычисляем и выводим скалярное произведение
    int result = dot_product(vec1, vec2);
    printf("Скалярное произведение векторов: %d\n", result);

    return 0;
}