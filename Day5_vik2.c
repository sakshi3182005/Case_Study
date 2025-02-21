void manageStudents();
int main()
{
    manageStudents();
    return 0;
}
void manageStudents(){
    int studentCount;
    Student students[100];
    int choice;
    do{
        printf("Choice:\n");
        printf("1-Read Students\n");
        printf("2-Display Students\n");
        printf("91-Exit\n");
        printf("Your Choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Enter the number of students:");
                scanf("%d",&studentCount);
                readStudents(students,studentCount);
            }break;
             case 2:{
                displayStudents(students,studentCount);
            }break;
             case 3:{
                printf("Thank you for using this..\n");
            }break;
        }
    }(while choice != 91)
}
