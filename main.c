#include <stdio.h>

#include "studentHandler.h"
#include "student.h"
#include "linkedList.h"

int main()
{
	student_t student1 = createStudent("John", "Doe", 2332, "North Korean");
	student_t student2 = createStudent("Jane", "Doe", 1794, "North Korean");
	student_t student3 = createStudent("Hunter", "Thompson", 8763, "American");
	student_list student_list = studentList_create();
	addStudent(student_list, student1);
	addStudent(student_list, student2);
	addStudent(student_list, student3);
	printAllStudentsInfo(student_list);
	printf("%d",numberOfStudents(student_list));
	student_t soughtStudent = searchStudentByID(student_list, 1238);
	if(soughtStudent!=NULL)
	{
		printInfo(soughtStudent);
	}

	return 0;
}