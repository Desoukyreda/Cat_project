#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"methods.h"
#include"student.h"

enum {false,true};

int begin()
{
     printf("\n\n");
    printf("\n\t\t\t        *************************************");
    printf("\n\t\t\t        *               WELCOME             *");
    printf("\n\t\t\t        *                  TO               *");
    printf("\n\t\t\t        *            Student Record         *");
    printf("\n\t\t\t        *              MANAGEMENT           *");
    printf("\n\t\t\t        *                SYSTEM             *");
    printf("\n\t\t\t        *************************************");
    printf("\n\n");

//printf("___________ Student Record System ___________");
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
    }while(choose!=1&&choose!=2);

    return choose;
}


int check(struct student_info *ptr,int id)
{
    if( ptr == NULL )
    {
        printf("\nThere isn't exist any student :(\n");
        return 0;
    }
    int i = 1;
    while(ptr!=NULL)
    {
        if(ptr->id == id )
        {
            return i;
        }else
        {
            ptr = ptr->link;
            i++;
        }
    }
    return false;
}

void view_student_record(struct student_info *ptr)
{
    if(ptr == NULL)
    {
        printf("\nThere isn't exist any student :(\n");
        return;
    }
    int id;
    printf("enter ID : ");
    scanf("%d",&id);
   int ch = check(ptr,id);
   if(ch > 0)
   {
    while(ptr!=NULL)
    {
        if(ptr->id == id )
        {
            break;
        }else
        {
            ptr = ptr->link;
        }
    }

    printf("\nFor student : %s\n",ptr->name);
    printf("Password : %s\n",ptr->pass);
    printf("Age : %d\n",ptr->age);
    printf("Total grade : %d\n",ptr->grade);
   }else
   {
       printf("\nThere isn't exist any student with this ID :(\n");
       return;
   }

}

void save_data(struct student_info *ptr)
{
    FILE *f_ptr = fopen("input.txt","w");
    if(f_ptr==NULL)
    {
        printf("\nCan't open a file :(\n");
        return;
    }

    while(ptr!=NULL)
    {
        fprintf(f_ptr,"%s,%s,%d,%d,%s,%d\n",ptr->name,ptr->pass,ptr->id,ptr->age,ptr->gender,ptr->grade);
        ptr = ptr->link;
    }
    fclose(f_ptr);
    printf("\nDone saving\n");
}


void tofree(struct student_info **head) {
    struct student_info *current = *head;
    struct student_info *next;

    while (current != NULL) {
        next = current->link;
        free(current);
        current = next;
    }


    *head = NULL;
}
