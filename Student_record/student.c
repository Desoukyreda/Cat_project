#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"student.h"
#include"Admin.h"

struct student_info *ptr2 = *head;
static int option,ID;
static int check_ID;

 void idcheck(void){
     Mylabel:
    printf("Enter your ID:\n");
    scanf("%d",&ID);
    check_ID = check(*head,ID);
    if( check_ID ==0){
        printf(" 'Incorrect ID... Try again'\n ");
    else
    return;}

 void viewfunc(struct student_info *ptr2){
     while(ptr2!=NULL)
    {
        if(ptr2->ID == ID )
        {
            break;
        }else
        {
            ptr2 = ptr2->link;
        }
    }

    printf("\n\tFor student : %s\n",ptr2->name);
    printf("Password : %s\n",ptr2->pass);
    printf("Age : %d\n",ptr2->age);
    printf("Total grade : %d\n",ptr2->grade);

 }

  void edit_name_func( struct student_info *ptr2){
    char newname[MAX_NAME_SIZE];
    while(ptr2!=NULL)
    {
        if(ptr2->ID == ID )
        {
            break;
        }else
        {
            ptr2 = ptr2->link;
        }}
        printf("Enter your new name:\n\n");
        fgets(newname,sizeof(newname),stdin);
        strncpy(ptr2->name,newname,sizeof(newname))
}

  void edit_pass_func( struct student_info *ptr2){
    char newpassw[MAX_PASSWORD_SIZE];
    while(ptr2!=NULL)
    {
        if(ptr2->ID== ID )
        {
            break;
        }else
        {
            ptr2 = ptr2->link;
        }}
        printf("Enter your new password:\n\n");
        fgets(newpassw,sizeof(newpassw),stdin);
        strncpy(ptr2->pass,newpassw,sizeof(newpassw))
  }

int student()
{

   printf("\t\t\t\t\t\t 'Student Mode' \n\n");
   if(size_of_student == 0)
   {
       printf("There are no students yet.\n");
       begin();
   }
   else{
    printf("Choose what you want to do:\n");
    printf(" 1-View your record\n 2-Edit your password\n 3-Edit your name\n ");
    scanf("%d",&option);
     idcheck();

    switch(option){
    case 1:
        viewfunc();
         save_data(*head);
        break;
    case 2:
        edit_pass_func();
        save_data(*head);
        break;
    case 3:
        edit_name_func();
        save_data(*head);

        break;
    default:
        printf("Wrong choice");

    }
      }

    return 0;}
