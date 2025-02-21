#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100 

typedef struct {
    int rollNo;
    char name[MAX_NAME_LENGTH];
    int maths, physics, chemistry, cs;
    int totalMarks;
    float percentage;
    char grade;
} Student;

void readStudentsFromStdin(Student *students, int *count); 
void displayStudents(const Student *students, int count);
void calculateGrade(Student *student);

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;

    readStudentsFromStdin(students, &studentCount); 

    if (studentCount > 0) {
        displayStudents(students, studentCount);
    }

    return 0;
}

void readStudentsFromStdin(Student *students, int *count) {
    *count = 0;
    printf("Enter student data (rollNo name maths physics chemistry cs), one student per line.\n");
    printf("Enter 'done' when finished:\n");


    char input[200]; 
    while (*count < MAX_STUDENTS) {
      fgets(input, sizeof(input), stdin); 

      if (strncmp(input, "done", 4) == 0) {
            break; 
      }

        if (sscanf(input, "%d %s %d %d %d %d",
                  &students[*count].rollNo, students[*count].name,
                  &students[*count].maths, &students[*count].physics,
                  &students[*count].chemistry, &students[*count].cs) != 6) {

            fprintf(stderr, "Invalid input format. Please try again.\n");
            continue; 
        }
        

        students[*count].totalMarks = students[*count].maths + students[*count].physics +
                                     students[*count].chemistry + students[*count].cs;
        students[*count].percentage = (float)students[*count].totalMarks / 400 * 100;
        calculateGrade(&students[*count]);
        (*count)++;
    }
}


void displayStudents(const Student *students, int count) {
    if (count == 0) {
        printf("No student data to display.\n");
        return;
    }

    printf("Roll No\tName\tMaths\tPhysics\tChem\tCS\tTotal\tPercentage\tGrade\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%.2f\t\t%c\n",
               students[i].rollNo, students[i].name, students[i].maths,
               students[i].physics, students[i].chemistry, students[i].cs,
               students[i].totalMarks, students[i].percentage, students[i].grade);
    }
}

void calculateGrade(Student *student) {
    if (student->percentage >= 90) {
        student->grade = 'A';
    } else if (student->percentage >= 80) {
        student->grade = 'B';
    } else if (student->percentage >= 70) {
        student->grade = 'C';
    } else if (student->percentage >= 60) {
        student->grade = 'D';
    } else {
        student->grade = 'F';
    }
}
