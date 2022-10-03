#pragma once
#include "student.h"
#include "linkedList.h"
typedef struct linkedList_st* student_list;
student_list studentList_create();
listReturnCode addStudent(student_list self,student_t student);
student_t getStudent(student_list self);
listReturnCode removeStudent(student_list self, student_t student);
uint16_t numberOfStudents(student_list self);
void printAllStudentDetails(student_list self);
student_t getStudentById(student_list self, int id);