/****
***  线性表的指针实现 链表
**
**
**
***/
#include "list_index.h"


LIST_I L_index;


position_i End_I(LIST_I Li)
{
	position_i q;
	q = Li;
	while(q->next != 0)
	{
		q=q->next;

	}

	return q;
}


void Insert_I(ElemType x,position_i po)
{
	position_i temp;
	temp = po->next;
	po->next = new celltype;
	po->next->elem = x;
	p->next->next = temp;

}

