#include "student.h"

#include <stdio.h>
#include <stdlib.h>



student_t createStudent(char* firstName, char* lastName, int studentID, char* nationality)
{
	student_t student = calloc(sizeof(student_st), 1);
	if(student==NULL)
	{
		return NULL;
	}
	student->firstName = firstName;
	student->lastName = lastName;
	student->studentID = studentID;
	student->nationality = nationality;
	return student;
}
void printInfo(student_t self)
{
	printf("Student name: %s %s\n", self->firstName, self->lastName);
	printf("\tStudent number: %d\n", self->studentID);
	printf("\tStudent nationality: %s\n", self->nationality);
}