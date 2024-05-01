#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"student.h"
#include"common_fun.h"

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

    }else                                                                                         //Function to add new (struct student_info type) nodes
    {                                                                                                            //to a new linked list.

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
    printf("\n\n\n\t\t\t        XXXXX Failed to open the file.XXXXX\n\n\n");
     return;
   }


   struct student_info *data;
   int id,age,grade;
   char name[MAX_NAME_SIZE],pass[MAX_PASSWORD_SIZE];                                                 //Function to read the informatio from our .txt file
   char gender[10];                                                                                  //then store them into our perivious linked list.
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
        printf("\n\n\t\t\t   There isn't exist any student :(\n\n\n");
        return 0;
    }
    int i = 1;
    while(ptr!=NULL)
    {
        if(!strcmp(ptr->pass,pass))                                                               //Function to check the student password by accessing each 
        {                                                                                        //node and compare between the two strings whether they are 
            return true;                                                                                           //identical or not.
        }else
        {
            ptr = ptr->link;
            i++;
        }
    }
    return false;
 }
//=========================================================================================================================================================//
 int id_pass_check(struct student_info *head){
   int id;
    printf("\n\t\t\t        Enter your ID : ");
    scanf("%d",&id);
    check_ID = check(head,id);
    if( check_ID == false){
        printf("\n\t\t\t        'Incorrect ID... Try again'\n ");
        return 0;
    }else
    {                                                                  //Function to check the student ID,same as the perivious function(password check).
      char pass[MAX_PASSWORD_SIZE];                                   //allowing the student to try several times.
    printf("\n\t\t\t        Enter your password : ");                  
    scanf("%s",pass);
    check_pass = pass_check(head,pass);
    if(check_pass == true){
        printf("\n\t\t\t        Done login..\n\n");
        return id;
    }else
    {
        printf("\n\t\t\t        'Incorrect password... Try again'\n ");
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
            ptr2 = ptr2->link;                             //Function to allow student to see his record ,after entering his own password and id.
        }
    }
    printf("\n\t\t\t        ***********\n");
    printf("\n\t\t\t        For student : %s\n",ptr2->name);
    printf("\n\t\t\t        Password : %s\n",ptr2->pass);
    printf("\n\t\t\t        Age : %d\n",ptr2->age);
    printf("\n\t\t\t        Total grade : %d\n",ptr2->grade);

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
        {                                           //Function to allow student to edit his name , after entering his own password and id.
            ptr2 = ptr2->link;
        }}
        printf("\n\t\t\t       Enter your new name : ");
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
            ptr2 = ptr2->link;                           //Function to allow student to edit his password, after entering his own old password and id.
        }}
        printf("\n\n\t\t\t       Enter your new password : ");
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
       printf("\n\t\t\t       There are no students yet.\n");
                                                                    //The main function in the student mode , which first collects the information then
                                                                   //gives student diffrent options (Viewing record , Editing name ,Editing password )
   }                                                              // and after this proccess ends, it saves new information according to the student's desire.
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
    printf("\n\t\t\t        ************\n");
    printf("Choose what you want to do:\n");
    printf("\n\t\t\t      1-View your record \n\t\t\t      2-Edit your password\n\t\t\t      3-Edit your name\n\t\t\t      4-Quit program\n ");
    printf("\n\t\t\t       your choice : ");
    scanf("%d",&option);
    char op;
    switch(option){
    case 1:

        viewfunc(*linkedlist,id);
        printf("\n\n\t\t\t   Press any key to continue...\n");
            getchar();
            getchar();
        break;
    case 2:

        edit_pass_func(*linkedlist,id);
        int i = 0;
       do{
        printf("\n\n\t\t\t   Would you like to save changes (y/n): \n ");
        scanf("%c",&op);
        int i = 0 ;
        if(op =='y' || op=='Y')
        {
            save_data(*linkedlist);
            break;
        }
        else if(op == 'n' || op == 'N') {
                printf("\n\n\t\t\t    Don't save changes \n");
                break;}
        else printf("\n\n\n\t\t\t        XXXXX invalid option..:( __Write (y/n)XXXXX\n\n\n");
        if(i==1)
        {
            printf("\n\n\n\t\t\t        XXXXX Wrong .. Try in later time :(XXXXX\n\n\n");
        }
        i++;
        }while(i<2);
        printf("\n\n\t\t\t     Press any key to continue...\n");
            getchar();
            getchar();
        break;
    case 3:

        edit_name_func(*linkedlist,id);

        do{
        printf("\n\n\t\t\t    Would you like to save changes (y/n): \n");
        scanf("%c",&op);
         i = 0 ;
        if(op =='y' || op=='Y')
        {
            save_data(*linkedlist);
            break;
        }
        else if(op == 'n' || op == 'N')
        {
             printf("\n\n\t\t\t    Don't save changes \n");
            break;}
        else printf("\n\n\n\t\t\t        XXXXX invalid option..:( __Write (y/n)XXXXX\n\n\n");
        if(i==1)
        {
            printf("\n\n\n\t\t\t        XXXXX Wrong .. Try in later time :(XXXXX\n\n\n");
        }
        i++;
        }while(i<2);
        printf("\n\n\t\t\t     Press any key to continue...\n");
            getchar();
            getchar();
        break;
    case 4:
        tofree(linkedlist);
        printf("\n\n\t\t\t\t\t\t  Done!\n");
        exit(1);
        break;
    default:
        printf("\n\n\n\t\t\t        XXXXX Wrong choice..Try again:(XXXXX\n\n\n");

    }

        }
      }

    return 0;}
