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


 //===========================================================FUNCTIONS PROTOTYPES=========================================================================/
  int id_pass_check(struct student_info*);
  void viewfunc( struct student_info *ptr2,int);
  void edit_pass_func( struct student_info *ptr2,int );
  void edit_name_func(struct student_info *ptr2,int);

  struct student_info* insertnode(struct student_info **head);

  void readFormFile(struct student_info **head);
  int pass_check(struct student_info *,char *);

  int student();


#endif // STUDENT_H_INCLUDED


