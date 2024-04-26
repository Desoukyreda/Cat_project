#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"student.h"
#include"Admin.h"

//struct node *ptr2 = *head;
static int option,ID;
static int check_ID;
//========================================================================================================================================================/
  struct node * creatnode(struct info data){

  struct node* newnode=(struct node *)malloc(sizeof(struct node));
  newnode -> data=data;
  newnode ->next=NULL;
  return newnode;

  };
//==========================================================================================================================================================/
  void insertnode(struct node **head,struct info data){
    struct node *newnode = creatnode(data);
    if(*head ==NULL){
        *head=newnode;
       // printf("\nin insert %d\n",(*head)->data.id);
        return;
    }
     struct node* current = *head;
     while(current -> next != NULL){
        current = current->next;
     }
     current->next =newnode;

  }

//==========================================================================================================================================================/
   void freeList( struct node **head ){
     struct node * current = *head;
     while( current != NULL){
     struct node * next =current-> next;
        free(current);
        current=next;
     }
        *head=NULL;}

//==========================================================================================================================================================/
  void readFormFile(struct node **head){

   FILE *file =fopen("input.txt","r");
   if(file ==NULL){
    printf("Failed to open the file.\n");
     return;
   }

   struct info data;
   char name[50],pass[MAX_PASSWORD_SIZE];
   char gender[10];
   while(fscanf(file,"%51[^,],%11[^,],%d,%d,%9[^,],%d\n",name,pass,&data.id,&data.age,data.gender,&data.grade) != EOF){
     printf("\nin read file\n");
     data.name = (char *)malloc(strlen(name)+1);
     strcpy(data.name,name);
     data.pass = (char *)malloc(strlen(pass)+1);
     strcpy(data.pass,pass);
     insertnode(head,data);
   }

   fclose(file);

  }
//==========================================================================================================================================================/
void savedata2(struct node *ptr)
{
    FILE *f_ptr = fopen("input.txt","w");
    if(f_ptr==NULL)
    {
        printf("\nCan't open a file :(\n");
        return;
    }
   // fprintf(f_ptr,"St info :name , password , ID , age , grade , gender .\n");
    while(ptr!=NULL)
    {
        fprintf(f_ptr,"%s,%s,%d,%d,%s,%d\n",ptr->data.name,ptr->data.pass,ptr->data.id,ptr->data.age,ptr->data.gender,ptr->data.grade);
        ptr = ptr->next;
    }
    fclose(f_ptr);
    printf("\nDone saving\n");
}


//==========================================================================================================================================================/
int check2(struct node *ptr,int id)
{
    if( ptr == NULL )
    {
        printf("\nThere isn't exist any student :(\n");
        return 0;
    }
    int i = 1;
    while(ptr!=NULL)
    {
        if(ptr->data.id == id )
        {
            return i;
        }else
        {
            ptr = ptr->next;
            i++;
        }
    }
    return 0;
}


 int idcheck(struct node *head, int id){

    check_ID = check2(head,id);
    if( check_ID ==0){
        printf(" 'Incorrect ID... Try again'\n ");
        return 0;
    }else
    return id;
 }
//==========================================================================================================================================================/
 void viewfunc(struct node *ptr2,int id){
     while(ptr2!=NULL)
    {
        if(ptr2->data.id == id )
        {
           // printf("\n%d %d",ptr2->data.id,id);
            break;
        }else
        {
            ptr2 = ptr2->next;
        }
    }

    printf("\nFor student : %s\n",ptr2->data.name);
    printf("Password : %s\n",ptr2->data.pass);
    printf("Age : %d\n",ptr2->data.age);
    printf("Total grade : %d\n",ptr2->data.grade);

 }
//==========================================================================================================================================================/
  void edit_name_func( struct node*ptr2,int id){
    char newname[MAX_NAME_SIZE];
    while(ptr2!=NULL)
    {
        if(ptr2->data.id == id )
        {
            break;
        }else
        {
            ptr2 = ptr2->next;
        }}
        printf("\nEnter your new name : ");
        fflush(stdin);
        fgets(newname,sizeof(newname),stdin);
        newname[strlen(newname)-1]='\0';
        strncpy(ptr2->data.name,newname,strlen(newname)+1);
}
//==========================================================================================================================================================/
  void edit_pass_func( struct node *ptr2,int id){
    char newpassw[MAX_PASSWORD_SIZE];
    while(ptr2!=NULL)
    {
        if(ptr2->data.id == id )
        {
            break;
        }else
        {
            ptr2 = ptr2->next;
        }}
        printf("\nEnter your new password : ");
        fflush(stdin);
        fgets(newpassw,MAX_PASSWORD_SIZE,stdin);
        newpassw[strlen(newpassw)-1]='\0';
        strncpy(ptr2->data.pass,newpassw,sizeof(newpassw));
  }
//==========================================================================================================================================================/

int student()
{  int id;
   struct node * linkedlist =NULL;
   readFormFile(&linkedlist);

   //=================inserting information from file.======================//
   printf("\t\t\t\t\t\t 'Student Mode' \n\n");
   if(linkedlist == NULL)
   {
       printf("There are no students yet.\n");
       //begin();
   }
   else{
    printf("Choose what you want to do:\n");
    printf(" 1-View your record\n 2-Edit your password\n 3-Edit your name\n ");
    scanf("%d",&option);

  ;
    printf("Enter your ID : ");
    scanf("%d",&ID);
    switch(option){
    case 1:
        id= idcheck(linkedlist,ID);
        viewfunc(linkedlist,id);
        break;
    case 2:
         id= idcheck(linkedlist,ID);
        edit_pass_func(linkedlist,id);
        savedata2(linkedlist);
        break;
    case 3:
         id= idcheck(linkedlist,ID);
        edit_name_func(linkedlist,id);
        savedata2(linkedlist);

        break;
    default:
        printf("Wrong choice");

    }

    printf("\n\n\t\t\t\t\t\tDone!\n");
      }

    return 0;}
