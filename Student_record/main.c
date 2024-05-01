#include <stdio.h>
#include <stdlib.h>
#include"student.h"
#include"Admin.h"
#include "common_fun.h"

int main()
{

    int mode = begin();
   struct student_info *st = NULL;
    switch(mode)
    {
    case 1:
        add_default_adminpass_infile();
         int ch = login();
    if(ch == 0)
    {
        printf("\n\t\t\t        Failed login :(\n");
        return 0;
    }
     admin(&st);
     break;
    case 2:
     student(&st);
     break;
    }
}
