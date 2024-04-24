#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
#define stringsize 30
#define default_pass 1234
#define MAX_NAME_SIZE 51
#define MAX_PASSWORD_SIZE 11

#define MAX_GRADE 100
#define MIN_GRADE 0


int begin();
int login();
int check(struct student_info *,int );
void add_student(struct student_info **);
void view_student_record(struct student_info*);
void remove_student(struct student_info ** );
void admin(struct student_info **);
void remove_first(struct student_info **);
void tofree(struct student_info **);
void save_data(struct student_info *);
void ViewAllRecords();
void EditAdminPassword();
void Editstudentgrade();

#endif // ADMIN_H_INCLUDED
