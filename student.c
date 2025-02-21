#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int rollNo;
    char name[50];
    int maths, physics, chemistry, cs;
    int totalMarks;
    float percentage;
    char grade;
} Student;

char calculateGrade(float percentage) {
    if (percentage >= 90) {
        return 'A';
    } else if (percentage >= 80) {
        return 'B';
    } else if (percentage >= 70) {
        return 'C';
    } else if (percentage >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

int main() {
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    Student students[100]; 
    int studentCount = 0;

    while (fscanf(file, "%d %49s %d %d %d %d",
                  &students[studentCount].rollNo,
                  students[studentCount].name,
                  &students[studentCount].maths,
                  &students[studentCount].physics,
                  &students[studentCount].chemistry,
                  &students[studentCount].cs) == 6) {

        students[studentCount].totalMarks = students[studentCount].maths +
                                             students[studentCount].physics +
                                             students[studentCount].chemistry +
                                             students[studentCount].cs;

        students[studentCount].percentage = (float)students[studentCount].totalMarks / 4.0;

        students[studentCount].grade = calculateGrade(students[studentCount].percentage);

        studentCount++;
    }

    fclose(file);

    printf("--------------------------------------------------------\n");
    printf("| Roll No | Name                 | Maths | Physics | Chem  | CS    | Total | %%    | Grade |\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < studentCount; i++) {
        printf("| %-7d | %-18s | %-5d | %-7d | %-5d | %-5d | %-5d | %-5.2f | %-5c |\n",
               students[i].rollNo, students[i].name, students[i].maths,
               students[i].physics, students[i].chemistry, students[i].cs,
               students[i].totalMarks, students[i].percentage, students[i].grade);
    }

    printf("--------------------------------------------------------\n");

    return 0;
}
