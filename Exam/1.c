 #include <stdio.h>

int main() {
    char array[4];
    char temp;
    for (int i = 0; i < 4; i++) {
        scanf("%c", &temp);
        array[i] = temp;
    }
    if (array[0] == '-') {
        printf("-%c%c%c", array[3], array[2], array[1]);
    } else {
        printf("%c%c%c", array[2], array[1], array[0]);
        }
    return 0;
}
