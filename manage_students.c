void manageStudents(){
  int StudentsCount;
  Student students[100];
  int choice;
  do{
    printf("Choices : \n");
    printf("1-Read Studnets : \n");
    printf("91-Exit : \n");
    printf("Your Choice : \n");
    scanf("%d",&choice);
   switch(choice){
    case 1 : {
        printf("Enter number of Students : ");
        scanf("%d", &studentCount);
        readStudents(student,studentCount);
    } break;
    case 2 :{
        displayStudents(students,studentCount);
    }break;
    case 3 :{
        printf("Thank you for using app....\n");
    }break;
   }   
}while(choice != 91)
}
