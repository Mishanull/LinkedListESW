#include "studentList.h"

#include <stdio.h>

#include "linkedList.h"

student_list studentList_create()
{
	student_list newList = linkedList_create();
	return newList;
}
listReturnCode addStudent(student_list self, student_t student)
{
	linkedList_push(self, student);
}
student_t getStudent(student_list self, student_t student)
{

	return linkedList_pull(self);
}
listReturnCode removeStudent(student_list self, student_t student)
{
	return linkedList_removeItem(self, student);
}
uint16_t numberOfStudents(student_list self)
{
	return linkedList_length(self);
}
void printAllStudentDetails(student_list self)

{
	linkedList_iterator_t iterator = linkedList_getIterator(self);
	for (int i = 0; i < numberOfStudents(self); i++)
	{
		printf("%d) ", (i + 1));
		printInfo((student_t)linkedList_iteratorNext(self, &iterator));
	}
}
student_t getStudentById(student_list self, int id)
{
	linkedList_iterator_t iterator = linkedList_getIterator(self);
	student_t aux = NULL;
	for (int i = 0; i < numberOfStudents(self); i++)
	{
		aux = (student_t)linkedList_iteratorNext(self, &iterator);
		if(( *aux ).studentID==id)
		{
			return aux;
		}
	}
	return NULL;
}