/**
 * @file cb_10_student management with structs
 * @brief Student management system: id, name and three grades.
 * @author Andres Benitez
 * @date 2026-13-09
 */

#include <stdio.h>
#include <stdlib.h>

#define PASSING_GRADE 60.0

typedef struct {
    int id;
    char name[50];
    float grades[3];
    float average;
} Student;

void calculateAverage(Student *s) {
    float sum = 0;
    for (int i = 0; i < 3; i++) sum += s->grades[i];
    s->average = sum / 3.0;
}

int main() {
    int n;
    printf("Ingrese el numero de estudiantes: ");
    scanf("%d", &n);

    Student *students = (Student *) malloc(n * sizeof(Student));
    if (students == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nEstudiante %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Nombre: ");
        scanf("%s", students[i].name);
        printf("Notas (3): ");
        for (int j = 0; j < 3; j++) scanf("%f", &students[i].grades[j]);

        calculateAverage(&students[i]);
    }

    printf("\n--- Promedios ---\n");
    for (int i = 0; i < n; i++) {
        printf("ID %d - %s: promedio = %.2f\n",
               students[i].id, students[i].name, students[i].average);
    }

    printf("\n--- Estudiantes aprobados (promedio >= %.0f) ---\n", PASSING_GRADE);
    for (int i = 0; i < n; i++) {
        if (students[i].average >= PASSING_GRADE) {
            printf("ID %d - %s\n", students[i].id, students[i].name);
        }
    }

    free(students);
    return 0;
}