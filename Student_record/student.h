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
  void idcheck(void);
  void viewfunc( struct student_info *ptr2);
  void edit_pass_func( struct student_info *ptr2);
  void edit_name_func(struct studdent_info *ptr2);

#endif // STUDENT_H_INCLUDED
