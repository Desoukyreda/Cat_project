#include"student.h"
#include"Admin.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include"methods.h"

enum {false,true};
char default_pass[MAX_PASSWORD_SIZE] ="1234";

static char *pass_admin;
static int size_of_student = 0;


void add_default_adminpass_infile()
{
    FILE *f =fopen("admin_pass.txt","r");
    if(f!=NULL)
    {
        fscanf(f,"Admin_pass : %s",default_pass);
        fclose(f);
    }else
    {
        FILE *f_p = fopen("admin_pass.txt","w");

    if(f_p == NULL)
    {
        printf("\nCan't open file :(\n");

    }else
    {
    fprintf(f_p,"Admin_pass : %s","1234");
    fclose(f_p);
    }
    }


}

int login ()
{
    FILE *f_ptr = fopen("admin_pass.txt","r");
    if(f_ptr == NULL)
    {
        printf("\nCan't open file :(\n");

    }else
    {
    fscanf(f_ptr,"Admin_pass : %s",default_pass);
    fclose(f_ptr);
    }

  char pass [MAX_PASSWORD_SIZE];

int check = 0;
printf("\n\nHi admin \n");
    while(check != 3)
    {
    printf("enter your password : ");
    int i = 0 ;
    do{
    pass[i] = getch();
    if(pass[i-1]!='\r') {
        printf("*");
    }
    i++;
    }while(pass[i-1]!='\r' && i<=MAX_PASSWORD_SIZE-1);

     pass[i-1]='\0';
     pass_admin = (char *)malloc(strlen(pass)+1);
     strcpy(pass_admin,pass);
     if(strcmp(pass_admin,default_pass) != 0)
     {
         if(check<3)
         printf("\n password is not correct .. Try again !\n");
         check++;
         free(pass_admin);
     }else{
         printf("\n\n_____________:) Welcome in our project :) ______________ \n\n");
     return true;
     }
    }
    printf("Try again in later time :(");
    return false ;
}




void add_student(struct student_info **head)
{

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
    char name[MAX_NAME_SIZE];
        printf("\nenter name of student : ");
        fflush(stdin);
        fgets(name,MAX_NAME_SIZE,stdin);
        name[strlen(name)-1]='\0';
        ptr->name = (char *)malloc(strlen(name)+1);
        strcpy(ptr->name,name);

        char password[MAX_PASSWORD_SIZE];
        do
        {
        printf("enter password of student (consist of 10 character for maximam ) : ");
        fgets(password,MAX_PASSWORD_SIZE,stdin);
        if(strlen(password)>11)
        {
            printf("\nDon't exceed about 10 character :(\n");
        }
        }while(strlen(password)>MAX_PASSWORD_SIZE);
        password[strlen(password)-1]='\0';
        ptr->pass = (char *)malloc(strlen(password)+1);
        strcpy(ptr->pass,password);

        int ch = 0;
        do
        {
            int id;
            printf("enter ID (digits only): ");
            scanf("%d",&id);
             ch = check(*head,id);
            if(ch!=0)
            {
                printf("\nThis ID %d already exist .. Try again :(\n",ptr->id);
            }else ptr->id =id;
        }while(ch!=0);

        do
        {
        printf("enter gender of student : ");
        scanf("%7s",ptr->gender);
        if(strcmp(ptr->gender,"male") && strcmp(ptr->gender,"female"))
        {
            printf("\nwrong in your writing , Try again\n");
        }
        }while(strcmp(ptr->gender,"male") && strcmp(ptr->gender,"female"));

        printf("enter age of student : ");
        scanf("%d",&(ptr->age));

        do
        {
            printf("enter total grade of student : ");
            scanf("%d",&(ptr->grade));
            if(ptr->grade>MAX_GRADE||ptr->grade<MIN_GRADE)
            {
                printf("\nWrong grade , Try again :(\n");
            }
        }while(ptr->grade>MAX_GRADE||ptr->grade<MIN_GRADE);


    size_of_student++;
}




void remove_student(struct student_info **head)
{

    if(size_of_student == 0)
    {
        printf("\nThere is no student To remove \n");
    return;
    }

    struct student_info *current = (*head);
    struct student_info *ptr = NULL;

    int id;
    printf("enter ID : ");
    scanf("%d",&id);
   int ch = check(*head,id);
   if(ch > 0)
   {
    while(current!=NULL)
    {
        if(current->id == id)
        {
            if(ch==1)
            {
                (*head) = current->link;

            }else
            {
               (ptr)->link = current->link ;
            }

            current->id = -1e5;
            free(current);
            current = NULL;
            break;
        }else
        {
            ptr = current;
            current = current->link;
        }
    }
   }else
   {
       printf("\nThere isn't exist any student with this ID :(\n");
       return;
   }
    size_of_student--;
    printf("\nDone removing\n");
}



void ViewAllRecords(struct student_info *head){
   struct student_info* current = head;
    if (current == NULL) {
         printf("\n\t\t\t        =-=-=-=-=-=-=-=\n");
        printf("\n\t\t\t        THERE IS NO STUDENTS TO VIEW\n\n");
    } else {

        while (current!= NULL) {
             printf("\n\t\t        *********\n");
            printf("\n\t\t        Stud name is: %s \n",current->name);
             printf("\n\t\t        Stud age is: %d \n",current->age);
            printf("\n\t\t        Stud ID is: %d \n",current->id);
            printf("\n\t\t        Stud total grade is: %d\n",current->grade);
            printf("\n\t\t        Stud gender is: %s \n",current->gender);
            printf("\n\t\t        **********\n");
            current = current->link;
        }
    }
}

    void EditAdminPassword(struct student_info **head)
{
    char newpass[MAX_PASSWORD_SIZE] ;
     printf("\n\t\t        Please enter your new password :\n");
    printf("\n\t\t        ");
    scanf("%s", newpass);
  pass_admin = (char*)malloc(strlen(newpass)+1);
  strcpy(pass_admin,newpass);

  FILE *f_p = fopen("admin_pass.txt","w");
    if(f_p == NULL)
    {
        printf("\nCan't open file :(\n");
        return;
    }
    fprintf(f_p,"Admin_pass : %s",pass_admin);
    fclose(f_p);
    free(pass_admin);
    pass_admin = NULL;
     printf("\n\t\t       your password have changed successfully! \n");


}

void Editstudentgrade(struct student_info **head){
    int ID;
     int newGrade;
     printf("Enter student ID: ");
    scanf("%d",&ID );
    printf("Enter new grade 'between 0 and 100': ");
    scanf("%d", &newGrade);

    struct student_info* current = *head;
    while(current != NULL) {
        if (current->id == ID) {

            if (newGrade >= 0 && newGrade <= 100) {
                current->grade = newGrade;
                printf("Grade for student with ID %d has been updated to %d\n", ID, newGrade);
                return;
            } else {
                printf("Error: Grade should be between 0 and 100.\n");
                return;
            }
        }
        current = current->link;
    }
    printf("Student with ID %d not found.\n", ID);
}

void admin(struct student_info **head){


        printf("\n\t\t\t        =-=-=-=-=-=-=-=\n");
        printf("\n\t\t\t        [1]To Add Student Record \n");
        printf("\n\t\t\t        [2]To Remove Student Record \n");
        printf("\n\t\t\t        [3]To View Student Record \n");
        printf("\n\t\t\t        [4]To View All Records \n");
        printf("\n\t\t\t        [5]To Edit Admin Password \n");
        printf("\n\t\t\t        [6]To Edit Student Grade \n");
        printf("\n\t\t\t        [7]To Save data in file.txt \n");
        printf("\n\t\t\t        [8]To Quit  \n");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=\n");
        printf("\n\t\t\t        choose from 1:8\n");
        printf("\n\t\t\t        ");
        int achoice;
        scanf("%d", &achoice);
        switch(achoice){
        case 1:
            add_student(head);

            break;
        case 2:
            remove_student(head);
            break;
        case 3:
            view_student_record(*head);
            printf("\n\nPress any key to continue...\n");
            getchar();
            getchar();
            break;
        case 4:
            ViewAllRecords(*head);
            printf("\n\nPress any key to continue...\n");
            getchar();
            getchar();
            break;
        case 5:
            EditAdminPassword(head);
            break;
        case 6:
            Editstudentgrade(head);
            break;
        case 7:
           save_data(*head);
           printf("\n\nPress any key to continue...\n");
            getchar();
            getchar();
           break;
        case 8:
            tofree(head);
            printf("\n\t\t\t      Thanks for using our program :)\n");
          return;
        default :
            printf("\nWrong Number :(\n");
        }
  admin(head);
    }
