#include"student.h"
#include<stdlib.h>


static char *pass;
static int size_of_student;

int began()
{
printf("___________ Student Record System ___________");
    printf("\n\nChoose your mode : \n");
    printf("1- Admin mode \n");
    printf("2- Student mode \n");
    int choose;
    do
    {
    printf("your choose : ");
    scanf("%d",&choose);
    if(choose!=1&&choose!=2)printf("Wrong number .. Try again :(\n");
    else break;
    }while(choose!=1||choose!=2);

    return choose;
}

void init(student_info **ptr)
{
    *ptr = (student_info *)malloc(sizeof(student_info));
    size_of_student = 0;

}



