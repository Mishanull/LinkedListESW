
#include <stdio.h>

#include "student.h"
#include "studentList.h"

void printStudentInfo(student_t student)
{
	printInfo(student);
}
void printAllStudentsInfo( student_list list)
{
	printAllStudentDetails(list);
}
student_t searchStudentByID(student_list list,int id)
{
	getStudentById(list, id);
}student_t searchStudentByLastName(student_list list, char* lastName)
{
	student_t student = NULL;
	for (int i = 0; i < numberOfStudents(list); i++)
	{
		student = getStudent(list);
		if ((*student).lastName == lastName)
		{
			return student;
		}
	}
	return student;
}
void handler_addStudent(student_list list, student_t student)
{
	addStudent(list, student);
}