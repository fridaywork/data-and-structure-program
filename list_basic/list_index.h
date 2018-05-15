
/**
**  线性表的指针实现 单链表 
**/

#ifndef __LIST_INDEX_H
#define __LIST_INDEX_H

#include "basictype.h"

struct cellType{
	ElemType elem;
	struct cellType* next;
};


typedef struct cellType* LIST_I;
typedef struct cellType* position_i;


extern LIST_I L_index;

#endif
