#include <stdio.h>

int main() {
char str[100];
int capitalize_next = 1;

fgets(str, sizeof(str), stdin);

for (int i = 0; str[i] != '\0'; i++) {
if (str[i] == ' ') {
capitalize_next = 1;
} else if (capitalize_next && str[i] >= 'a' && str[i] <= 'z') {
str[i] = str[i] - ('a' - 'A');
capitalize_next = 0;
} else {
capitalize_next = 0;
}
}

printf("%s", str);

return 0;
}
