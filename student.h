#pragma once
typedef struct student_st* student_t;
typedef struct student_st
{
	char* firstName;
	char* lastName;
	int studentID;
	char* nationality;
}student_st;

student_t createStudent(char* firstName, char* lastName, int studentID, char* nationality);
void printInfo(student_t self);