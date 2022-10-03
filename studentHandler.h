#pragma once
#include "student.h"
#include "studentList.h"

void printStudentInfo(student_t student);
void printAllStudentsInfo(student_list list);
student_t searchStudentByID(student_list list,int id);
student_t searchStudentByLastName(student_list list,char* lastName);
void handler_addStudent(student_list list,student_t student);