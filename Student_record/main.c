#include <stdio.h>
#include <stdlib.h>
#include"student.h"
#include"Admin.h"

int main()
{
    int mode = begin();

   struct student_info *st = NULL;
    //add_student(&st);
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
