#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

 struct student_info
{
    char *name;
    char *pass;
    int age;
    char gender[10];
    int grade;
    int id;
    struct student_info *link;
};

#endif // STUDENT_H_INCLUDED
