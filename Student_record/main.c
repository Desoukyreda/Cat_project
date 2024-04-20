#include <stdio.h>
#include <stdlib.h>
#include"student.h"
#include"Admin.h"
int main()
{
    int mode = began();

    student_info *st;
    switch(mode)
    {
    case 1:
     admin();
     break;
    case 2:
     student();
     break;
    }
}
