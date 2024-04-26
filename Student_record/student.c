#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"student.h"
#include"Admin.h"
#define MAX_NAME_SIZE 51
#define MAX_PASSWORD_SIZE 11
#define MAX_GRADE 100
#define MIN_GRADE 0
struct node *ptr2 ;
static int option,ID;
static int check_ID;
/*========================================================================================================================================================*/
  struct node * creatnode(struct info data){

  struct node* newnode=(struct node *)malloc(sizeof(struct node));
  newnode -> data=data;
  newnode ->next=NULL;
  return newnode;

  };
/*==========================================================================================================================================================*/
  void insertnode(struct node **head,struct info data){
    struct node *newnode = creatnode(data);
    if(*head ==NULL){
        *head=newnode;
        return;
    }
     struct node* current = *head;
     while(current -> next != NULL){
        current = current->next;
     }
     current->next =newnode;

  }

/*==========================================================================================================================================================*/
   void freeList( struct node **head ){
     struct node * current = *head;
     while( current != NULL){
     struct node * next =current-> next;
        free(current);
        current=next;
     }
        *head=NULL;}

/*==========================================================================================================================================================*/
  void readFormFile(const char* fileName,struct node **head){

   FILE *file =fopen(fileName,"r");
   if(file ==NULL){
    printf("Failed to open the file.\n");
     return;
   }
   struct info data;
   while(fscanf(file,"%51[^,],%11[^,],%d,%d,%d,%10[^,]",&data.name,&data.pass,&data.id,&data.age,&data.grade,&data.gender) == 6){
      insertnode(head,data);
   }

   fclose(file);

  }
/*==========================================================================================================================================================*/
void savedata2(struct node *ptr)
{
    FILE *f_ptr = fopen("input.txt","w");
    if(f_ptr==NULL)
    {
        printf("\nCan't open a file :(\n");
        return;
    }
    fprintf(f_ptr,"St info :name , password , ID , age , grade , gender .\n");
    while(ptr!=NULL)
    {
        fprintf(f_ptr,"%s,%s,%d,%d,%d,%s\n",ptr->data.name,ptr->data.pass,ptr->data.id,ptr->data.age,ptr->data.grade,ptr->data.gender);
        ptr = ptr->next;
    }
    fclose(f_ptr);
    printf("\nDone saving\n");
}


/*==========================================================================================================================================================*/


 void idcheck(int ID){
     Mylabel:
    int check_ID = check(*ptr2,ID);
    if( check_ID ==0){
        printf(" 'Incorrect ID... Try again'\n ");
   } else
    return;}
/*==========================================================================================================================================================*/
 void viewfunc(struct node *ptr2){
     while(ptr2!=NULL)
    {
        if(ptr2->data.id == ID )
        {
            break;
        }else
        {
            ptr2 = ptr2->next;
        }
    }

    printf("\n\tFor student : %s\n",ptr2->data.name);
    printf("Password : %s\n",ptr2->data.pass);
    printf("Age : %d\n",ptr2->data.age);
    printf("Total grade : %d\n",ptr2->data.grade);

 }
/*==========================================================================================================================================================*/
  void edit_name_func( struct node*ptr2){
    char newname[MAX_NAME_SIZE];
    while(ptr2!=NULL)
    {
        if(ptr2->data.id == ID )
        {
            break;
        }else
        {
            ptr2 = ptr2->next;
        }}
        printf("Enter your new name:\n\n");
        fgets(newname,sizeof(newname),stdin);
        strncpy(ptr2->data.name,newname,sizeof(newname));
}
/*==========================================================================================================================================================*/
  void edit_pass_func( struct node *ptr2){
    char newpassw[MAX_PASSWORD_SIZE];
    while(ptr2!=NULL)
    {
        if(ptr2->data.id == ID )
        {
            break;
        }else
        {
            ptr2 = ptr2->next;
        }}
        printf("Enter your new password:\n\n");
        fgets(newpassw,sizeof(newpassw),stdin);
        strncpy(ptr2->data.pass,newpassw,sizeof(newpassw));
  }
/*==========================================================================================================================================================*/
int student()
{  int ID;
   struct node *ptr,*ptr3;
   struct node * linkedlist =NULL;
   readFormFile("input.txt",&linkedlist);
   //=================inserting information from file.======================//
   printf("\t\t\t\t\t\t 'Student Mode' \n\n");
  /* if(size_of_student == 0)
   {
       printf("There are no students yet.\n");
       begin();
   }
   else{*/
    printf("Choose what you want to do:\n");
    printf(" 1-View your record\n 2-Edit your password\n 3-Edit your name\n ");
    scanf("%d",&option);
    printf("Enter your ID:\n");
    scanf("%d",&ID);
     idcheck(ID);

    switch(option){
    case 1:
        viewfunc(&ptr);
         savedata2(&ptr3);
        break;
    case 2:
        edit_pass_func(&ptr);
        savedata2(&ptr3);
        break;
    case 3:
        edit_name_func(&ptr);
        savedata2(&ptr3);

        break;
    default:
        printf("Wrong choice");

    }

    printf("/n/n/t/t/t/t/t/tDone!/n");


    return 0;
   }
