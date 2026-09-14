/**
 * @file cb_08_grades and qualifications
 * @brief Assign a letter grade based on a numeric score.
 * @author Andres Benitez
 * @date 2026-13-09
 */

#include <stdio.h>

char getGrade(int score) {
    if (score >= 90 && score <= 100) return 'A';
    else if (score >= 80 && score < 90) return 'B';
    else if (score >= 70 && score < 80) return 'C';
    else if (score >= 60 && score < 70) return 'D';
    else return 'F';
}

int main() {
    int score;
    printf("Ingrese una nota (0-100): ");
    scanf("%d", &score);

    if (score < 0 || score > 100) {
        printf("Nota invalida.\n");
        return 1;
    }

    printf("Calificacion: %c\n", getGrade(score));

    return 0;
}