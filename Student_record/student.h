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

struct info{

    char *name;
    char *pass;
    int age;
    char gender[10];
    int grade;
    int id;
};
 struct node
{
    struct info data;
    struct node*next;
};
 //===========================================================FUNCTIONS PROTOTYPES=========================================================================/
  int idcheck(struct node*);
  void viewfunc( struct node *ptr2,int);
  void edit_pass_func( struct node *ptr2,int );
  void edit_name_func(struct node *ptr2,int);
  struct node * creatnode(struct info data);
  void insertnode(struct node **head,struct info data);
  void freeList( struct node **head );
  void readFormFile(struct node **head);
  void savedata2(struct node *ptr);
  int student();
#endif // STUDENT_H_INCLUDED
