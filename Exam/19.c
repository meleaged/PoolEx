#include <math.h>
#include <stdio.h>

typedef struct {
    float x;
    float y;
    float z;
} Vector;

float vector_length(const Vector *v) { return sqrt(v->x * v->x + v->y * v->y + v->z * v->z); }

int main() {
    int n;
    printf("Введите количество векторов: ");
    scanf("%d", &n);

    Vector vectors[n];

    // Ввод векторов
    for (int i = 0; i < n; i++) {
        printf("Введите вектор %d (X Y Z): ", i + 1);
        scanf("%f %f %f", &vectors[i].x, &vectors[i].y, &vectors[i].z);
    }

    float threshold;
    printf("Введите заданную величину: ");
    scanf("%f", &threshold);

    Vector sum = {0, 0, 0};

    // Вычисление суммы векторов с длиной больше заданной величины
    for (int i = 0; i < n; i++) {
        if (vector_length(&vectors[i]) > threshold) {
            sum.x += vectors[i].x;
            sum.y += vectors[i].y;
            sum.z += vectors[i].z;
        }
    }

    printf("Сумма векторов с длиной больше %.2f: (%.2f, %.2f, %.2f)\n", threshold, sum.x, sum.y, sum.z);

    return 0;
}