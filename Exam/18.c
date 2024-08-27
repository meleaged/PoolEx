#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Функция для добавления элемента в конец списка
void append(Node** head_ref, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    Node* last = *head_ref;  // Указатель на последний узел

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Рекурсивная функция для вывода списка в обратном порядке
void printReverse(Node* node) {
    if (node == NULL) {
        return;
    }
    printReverse(node->next);
    printf("%d ", node->data);
}

// Освобождение памяти, занимаемой списком
void freeList(Node* node) {
    while (node != NULL) {
        Node* temp = node;
        node = node->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int value;

    printf("Введите последовательность цифр, завершите -1:\n");
    while (1) {
        scanf("%d", &value);
        if (value == -1) {
            break;
        }
        append(&head, value);
    }

    printf("Список в обратном порядке: ");
    printReverse(head);
    printf("\n");

    // Освобождаем память
    freeList(head);

    return 0;
}