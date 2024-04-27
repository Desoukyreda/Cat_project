#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"student.h"
#include"methods.h"

enum {false,true};
static int option,ID;
static int check_ID,check_pass;

//==========================================================================================================================================================/

  struct student_info * insertnode(struct student_info **head){
    struct student_info *ptr = *head;
    if(*head == NULL)
    {
        *head = (struct student_info *)malloc(sizeof(struct student_info));
        (*head)->link = NULL;
        ptr = *head;

    }else
    {

     struct student_info *current = (struct student_info *)malloc(sizeof(struct student_info));
     current->link = NULL;

     while(ptr->link!=NULL)ptr = ptr->link;

        ptr->link = current;

     ptr = current;
    }
    return ptr;
  }

//==========================================================================================================================================================/

  void readFormFile(struct student_info **head){

   FILE *file =fopen("input.txt","r");
   if(file ==NULL){
    printf("Failed to open the file.\n");
     return;
   }


   struct student_info *data;
   int id,age,grade;
   char name[MAX_NAME_SIZE],pass[MAX_PASSWORD_SIZE];
   char gender[10];
   while(fscanf(file,"%51[^,],%11[^,],%d,%d,%9[^,],%d\n",name,pass,&id,&age,gender,&grade) != EOF){
     data = insertnode(head);
     data->id = id;
     data->age = age;
     data->grade = grade;
     data->name = (char *)malloc(strlen(name)+1);
     strcpy(data->name,name);
     data->pass = (char *)malloc(strlen(pass)+1);
     strcpy(data->pass,pass);

     strcpy(data->gender,gender);
   }

   fclose(file);

  }

//==========================================================================================================================================================/
 int pass_check(struct student_info *ptr,char *pass)
 {
     if( ptr == NULL )
    {
        printf("\nThere isn't exist any student :(\n");
        return 0;
    }
    int i = 1;
    while(ptr!=NULL)
    {
        if(!strcmp(ptr->pass,pass))
        {
            return true;
        }else
        {
            ptr = ptr->link;
            i++;
        }
    }
    return false;
 }

 int id_pass_check(struct student_info *head){
   int id;
    printf("Enter your ID : ");
    scanf("%d",&id);
    check_ID = check(head,id);
    if( check_ID == false){
        printf("\n 'Incorrect ID... Try again'\n ");
        return 0;
    }else
    {
      char pass[MAX_PASSWORD_SIZE];
    printf("Enter your password : ");
    scanf("%s",pass);
    check_pass = pass_check(head,pass);
    if(check_pass == true){
        printf("\nDone login..\n\n");
        return id;
    }else
    {
        printf("\n 'Incorrect password... Try again'\n ");
        return false;}

    }

 }
//==========================================================================================================================================================/
 void viewfunc(struct student_info *ptr2,int id){
     while(ptr2!=NULL)
    {
        if(ptr2->id == id )
        {

            break;
        }else
        {
            ptr2 = ptr2->link;
        }
    }

    printf("\nFor student : %s\n",ptr2->name);
    printf("Password : %s\n",ptr2->pass);
    printf("Age : %d\n",ptr2->age);
    printf("Total grade : %d\n",ptr2->grade);

 }
//==========================================================================================================================================================/
  void edit_name_func( struct student_info *ptr2,int id){
    char newname[MAX_NAME_SIZE];
    while(ptr2!=NULL)
    {
        if(ptr2->id == id )
        {
            break;
        }else
        {
            ptr2 = ptr2->link;
        }}
        printf("\nEnter your new name : ");
        fflush(stdin);
        fgets(newname,sizeof(newname),stdin);
        newname[strlen(newname)-1]='\0';
        strncpy(ptr2->name,newname,strlen(newname)+1);
}
//==========================================================================================================================================================/
  void edit_pass_func( struct student_info *ptr2,int id){
    char newpassw[MAX_PASSWORD_SIZE];
    while(ptr2!=NULL)
    {
        if(ptr2->id == id )
        {
            break;
        }else
        {
            ptr2 = ptr2->link;
        }}
        printf("\nEnter your new password : ");
        fflush(stdin);
        fgets(newpassw,MAX_PASSWORD_SIZE,stdin);
        newpassw[strlen(newpassw)-1]='\0';
        strncpy(ptr2->pass,newpassw,sizeof(newpassw));
  }
//==========================================================================================================================================================/

int student(struct student_info **linkedlist)
{

   readFormFile(linkedlist);

   //=================inserting information from file.======================//
   printf("\t\t\t\t\t\t 'Student Mode' \n\n");
   if(linkedlist == NULL)
   {
       printf("There are no students yet.\n");

   }
   else{
        int id;
        int num =0;
        do{
           id = id_pass_check(*linkedlist);
           if(id != false)break;
           num++;
        }while(num < 3);



        while(1)
        {
    printf("Choose what you want to do:\n");
    printf(" 1-View your record\n 2-Edit your password\n 3-Edit your name\n 4-Quit program\n ");
    printf("\nyour choice : ");
    scanf("%d",&option);
    char op;
    switch(option){
    case 1:

        viewfunc(*linkedlist,id);
        printf("\n\nPress any key to continue...\n");
            getchar();
            getchar();
        break;
    case 2:

        edit_pass_func(*linkedlist,id);
        int i = 0;
       do{
        printf("Would you like to save changes (y/n): ");
        scanf("%c",&op);
        int i = 0 ;
        if(op =='y' || op=='Y')
        {
            save_data(*linkedlist);
            break;
        }
        else if(op == 'n' || op == 'N') {
                printf("\nDon't save changes \n");
                break;}
        else printf("invalid option..:( __Write (y/n)");
        if(i==1)
        {
            printf("\nWrong .. Try in later time :(");
        }
        i++;
        }while(i<2);
        printf("\n\nPress any key to continue...\n");
            getchar();
            getchar();
        break;
    case 3:

        edit_name_func(*linkedlist,id);

        do{
        printf("Would you like to save changes (y/n): ");
        scanf("%c",&op);
         i = 0 ;
        if(op =='y' || op=='Y')
        {
            save_data(*linkedlist);
            break;
        }
        else if(op == 'n' || op == 'N')
        {
             printf("\nDon't save changes \n");
            break;}
        else printf("invalid option..:( __Write (y/n)");
        if(i==1)
        {
            printf("\nWrong .. Try in later time :(");
        }
        i++;
        }while(i<2);
        printf("\n\nPress any key to continue...\n");
            getchar();
            getchar();
        break;
    case 4:
        tofree(linkedlist);
        printf("\n\n\t\t\t\t\t\tDone!\n");
        exit(1);
        break;
    default:
        printf("\nWrong choice..Try again:(\n");

    }

        }
      }

    return 0;}
