#include "linkedList.h"

typedef struct linkedListNode_st* node_t;
typedef struct linkedList_st {
	uint16_t size;
	node_t head;

}linkedList_st;

typedef struct linkedListNode_st {
	void* element;
	node_t next;
}linkedListNode_st;


linkedList_t linkedList_create() {
	linkedList_t linkedList = (linkedList_t)calloc(sizeof(linkedList_st),1);
	if (linkedList == NULL) {
		return NULL;
	}
	linkedList->head = NULL;
	return linkedList;
}
listReturnCode linkedList_push(linkedList_t self,void* item) {
	node_t newNode = (node_t)calloc(sizeof(linkedListNode_st),1);
	
	newNode->element = item;
	newNode->next = self->head;
	self->head = newNode;
	self->size++;
	return OK;
}
uint16_t linkedList_length(linkedList_t self) {
	if (self == NULL) {
		return -1;
	}
	return self->size;
}
void* linkedList_pull(linkedList_t self)
{
	if (self->head != NULL) {
		node_t pulledNode = self->head;
		self->head = self->head->next;
		self->size--;
		return pulledNode->element;
	}
	else return NULL;
}
listReturnCode linkedList_containsItem(linkedList_t self, void* item)
{
	if(self->size==0)
	{
		return EMPTY;
	}
	while(self->head->next!=NULL)
	{
		if (self->head->next->element == item)
		{
			return FOUND;
		}
		else self->head = self->head->next;
	}
	return NOT_FOUND;
}
void* linkedList_peekItemByIndex(linkedList_t self, uint16_t index)
{
	if(self==NULL || self->head==NULL)
	{
		return NULL;
	}
	for (int i = 0; i <=index; i++)
	{
		self->head = self->head->next;
		if (i == index)
			return self->head->element;
	}
}
 listReturnCode linkedList_removeItem(linkedList_t self, void* item)
{
	if (self == NULL || self->head == NULL)
	{
		return 	EMPTY;
	}
	else if(self->head->element == item)
	{
		return OK;
	}
	else {
		while (self->head->next != NULL)
		{

			if (self->head->next->element == item)
			{
				node_t aux = self->head->next;
				self->head->next = self->head->next->next;
				free(aux);
				self->size--;
				return OK;
			}
			else self->head = self->head->next;
		}
	}
	return NOT_FOUND;
}
 void linkedList_clear(linkedList_t self)
{
	
	if( self==NULL || self->head == NULL || linkedList_length(self) == 0 )
	{
		return;
	}
	else
	{
		while(self->head!=NULL)
		{
			node_t aux = self->head;
			self->head = self->head->next;
			free(aux);
			self->size--;
		}
	}
}
listReturnCode linkedList_destroy(linkedList_t self)
{
	if(self==NULL)
	{
		return EMPTY;
	}
	linkedList_clear(self);
	free(self);
	return OK;
}
linkedList_iterator_t linkedList_getIterator(linkedList_t self)
{
	if(self==NULL || self->size==0)
	{
		return NULL;
	}
	else
	{
		linkedList_iterator_t iterator =(linkedList_iterator_t) calloc(sizeof(linkedListNode_st), 1);
		if(iterator==NULL)
		{
			return NULL;
		}
		node_t aux = self->head->next;
		iterator->element = self->head->element;
		self->head = iterator;
		self->head->next = aux;
		return iterator;
	}
}
void* linkedList_iteratorNext(linkedList_t list, linkedList_iterator_t* iterator)
{
	void* element = NULL;
	if((*iterator)->element!=NULL)
	{
		element= (*iterator)->element;
		(*iterator) = (*iterator)->next;
	}
	return element;
}






