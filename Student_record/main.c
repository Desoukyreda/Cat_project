#include <stdio.h>
#include <stdlib.h>
#include"student.h"
#include"Admin.h"
int main()
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

    int mode = begin();
   struct student_info *st = NULL;
    switch(mode)
    {
    case 1:
         int ch = login();
    if(ch == 0)
    {
        printf("\n\t\t\t        Failed login :(\n");
        return 0;
    }
     admin(&st);
     break;
    case 2:
     //student();
     break;
    }
}
   
