
/**
**  线性表的指针实现 单链表 
**/

#ifndef __LIST_INDEX_H
#define __LIST_INDEX_H

#include "basictype.h"

typedef struct cellType{
	ElemType elem;
	struct cellType *next;
}cellType,*LinkList;


void scanLinkList(LinkList Li);
LinkList CreatList1(LinkList Li);


typedef struct cellType *LIST_I;
typedef struct cellType *position_i;



LinkList CreatList1(LinkList Li);



extern LIST_I L_index;

#endif
