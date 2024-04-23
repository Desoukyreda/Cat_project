#include<stdio.h>
#include<stdlib.h>
#include"student.h"

int main()
{  static int option,ID;
   static char* passw
    printf("\t\t\t\t\t\t 'Student Mode' \n\n");
    printf("Enter your ID:\n");
    scanf("%d",&ID);
    printf("Enter your password");
    scanf(" %s",&passw);
    if(){
    printf("Choose what you want to do:\n");
    printf(" 1-View your record\n 2-Edit your password\n 3-Edit your name\n ");
    scanf("%d",&option);
    switch(option){
    case 1:
        viewfunc();
        break;
    case 2:
        edit_pass_func();
        break;
    case 3:
        edit_name_func();
        break;
    default:
        printf("Wrong choice");
    
    }}
    else{
        printf("Wrong password.");
    }

    return 0;
