#ifndef METHODS_H_INCLUDED
#define METHODS_H_INCLUDED

#define MAX_NAME_SIZE 51
#define MAX_PASSWORD_SIZE 11
#define MAX_GRADE 100
#define MIN_GRADE 0

struct student_info;

int begin();
int check(struct student_info *,int );
void view_student_record(struct student_info*);
void tofree(struct student_info **);
void save_data(struct student_info *);

#endif // METHODS_H_INCLUDED
