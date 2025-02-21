#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    int rollNo;
    char name[50];
    int maths, physics, chemistry, cs;
    int totalMarks;
    float percentage;
    char grade;
} Student;


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


void readStudents(Student emp[], int n) {
    printf("Enter student details (RollNo, Name, Maths, Physics, Chemistry, CS):\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &emp[i].rollNo);
        printf("Name: ");
        scanf(" %s", emp[i].name); 
        printf("Maths: ");
        scanf("%d", &emp[i].maths);
        printf("Physics: ");
        scanf("%d", &emp[i].physics);
        printf("Chemistry: ");
        scanf("%d", &emp[i].chemistry);
        printf("CS: ");
        scanf("%d", &emp[i].cs);

        emp[i].totalMarks = emp[i].maths + emp[i].physics + emp[i].chemistry + emp[i].cs;
        emp[i].percentage = (float)emp[i].totalMarks / 4.0;
        calculateGrade(&emp[i]); 
        printf("\n");
    }
}


void displayStudents(Student emp[], int n) {
    printf("\n------------------------------------------------------------------\n");
    printf("%-10s %-20s %-7s %-7s %-7s %-7s %-7s %-7s %-7s\n", "Roll No", "Name", "Maths", "Physics", "Chem", "CS", "Total", "Percentage", "Grade");
    printf("------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-10d %-20s %-7d %-7d %-7d %-7d %-7d %-7.2f %-7c\n", emp[i].rollNo, emp[i].name, emp[i].maths, emp[i].physics, emp[i].chemistry, emp[i].cs, emp[i].totalMarks, emp[i].percentage, emp[i].grade);
    }
    printf("------------------------------------------------------------------\n");
}


void manageStudents() {
    int studentCount = 0;
    Student students[1000]; 
    int choice;

    do {
        printf("\nStudent Management Menu:\n");
        printf("1. Read Student Details\n");
        printf("2. Display Student Details\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of students: ");
                scanf("%d", &studentCount);
                readStudents(students, studentCount);
                break;
            case 2:
                if (studentCount > 0) {
                    displayStudents(students, studentCount);
                } else {
                    printf("No student data has been entered yet.\n");
                }
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
}

int main() {
    manageStudents(); 
    return 0;
}
