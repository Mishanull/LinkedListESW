#pragma once
#include <stdlib.h>
#include <stdint.h>
typedef struct linkedList_st* linkedList_t;
typedef enum  listReturnCode{
	OK,
	EMPTY,
	NOT_FOUND,
	FULL,
	FOUND
} listReturnCode;
typedef struct linkedListNode_st* linkedList_iterator_t;
 linkedList_t linkedList_create(void);
  listReturnCode linkedList_destroy(linkedList_t self);
 void* linkedList_pull(linkedList_t self);
 listReturnCode linkedList_push(linkedList_t self,void* item);
listReturnCode linkedList_containsItem(linkedList_t self,void* item);
 listReturnCode linkedList_removeItem(linkedList_t self, void* item);
  void* linkedList_peekItemByIndex(linkedList_t self, uint16_t index);
  uint16_t linkedList_length(linkedList_t self);
  void linkedList_clear(linkedList_t self);
  linkedList_iterator_t linkedList_getIterator(linkedList_t list);
  void* linkedList_iteratorNext(linkedList_t list, linkedList_iterator_t* iterator);
