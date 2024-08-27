#include <stdio.h>
#define NMAX 20

struct Students {
    char first_name[NMAX];
    char last_name[NMAX];
    int semester_grade;
};

int input_number_of_students();
int input_names_and_grades(struct Students* array, int number_of_students);
int maximum_grade_of_students(struct Students* array, int number_of_students);
int count_top_grade_students(struct Students* array, int number_of_students, int maximum_grade_value);
void output_names_and_grades_of_top_students(struct Students* array, int number_of_students,
                                             int number_of_top_students, int maximum_grade_value);

int main() {
    int number_of_students = input_number_of_students();
    if (number_of_students > 0) {
        struct Students array[number_of_students];
        if (input_names_and_grades(array, number_of_students) == 0) {
            int maximum_grade_value = maximum_grade_of_students(array, number_of_students);
            int number_of_top_students =
                count_top_grade_students(array, number_of_students, maximum_grade_value);
            output_names_and_grades_of_top_students(array, number_of_students, number_of_top_students,
                                                    maximum_grade_value);
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int maximum_grade_of_students(struct Students* array, int number_of_students) {
    int maximum_grade_value = 0;
    for (int i = 0; i < number_of_students; i++) {
        if (maximum_grade_value < array[i].semester_grade) {
            maximum_grade_value = array[i].semester_grade;
        }
    }
    return maximum_grade_value;
}

int count_top_grade_students(struct Students* array, int number_of_students, int maximum_grade_value) {
    int counter = 0;
    for (int j = 0; j < number_of_students; j++) {
        if (array[j].semester_grade == maximum_grade_value) {
            counter++;
        }
    }
    return counter;
}
void output_names_and_grades_of_top_students(struct Students* array, int number_of_students,
                                             int number_of_top_students, int maximum_grade_value) {
    for (int i = 0; i < number_of_students; i++) {
        if (array[i].semester_grade == maximum_grade_value) {
            printf("%s %s %d", array[i].first_name, array[i].last_name, array[i].semester_grade);
            if (i < number_of_top_students) {
                printf(", ");
            }
        }
    }
}

int input_names_and_grades(struct Students* array, int number_of_students) {
    char endline;
    int return_case = 0;
    for (int i = 0; i < number_of_students; i++) {
        if (!scanf("%s%c", array[i].first_name, &endline) || endline != '\n') {
            return_case = 1;
            break;
        }
        if (!scanf("%s%c", array[i].last_name, &endline) || endline != '\n') {
            return_case = 1;
            break;
        }
        if (!scanf("%d%c", &array[i].semester_grade, &endline) || array[i].semester_grade < 0 ||
            endline != '\n') {
            return_case = 1;
            break;
        }
    }
    return return_case;
}

int input_number_of_students() {
    int number;
    char endline;
    if (!scanf("%d%c", &number, &endline) || endline != '\n') {
        number = -1;
    }
    return number;
}