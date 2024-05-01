#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED


int login();
int check_string(char*);
void add_student(struct student_info **);

void remove_student(struct student_info ** );
void admin(struct student_info **);
void remove_first(struct student_info **);

void ViewAllRecords(struct student_info *);
void EditAdminPassword(struct student_info **);
void Editstudentgrade(struct student_info **);
void add_default_adminpass_infile();


#endif // ADMIN_H_INCLUDED
