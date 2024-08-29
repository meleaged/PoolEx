#include <stdio.h>
#include <string.h>

void capitalize(char *str) {
int capitalize_next = 1; // Флаг для обозначения необходимости капитализации следующего символа

for (int i = 0; str[i] != '\0'; i++) {
if (str[i] == ' ') {
capitalize_next = 1; // Если символ - пробел, то следующий должен быть заглавным
} else if (capitalize_next && str[i] >= 'a' && str[i] <= 'z') {
str[i] = str[i] - ('a' - 'A'); // Переводим в верхний регистр
capitalize_next = 0; // Отключаем флаг до следующего пробела
} else {
capitalize_next = 0; // Если символ не пробел, сбрасываем флаг
}
}
}

int main() {
char str[100];

fgets(str, sizeof(str), stdin);

capitalize(str);

printf("%s", str);

return
