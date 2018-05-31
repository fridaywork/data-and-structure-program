/**
**    双向表的定义与基本操作
***
**
**
***********************************888*/




#ifndef  __BASICLIST4_H
#define  __BASICLIST4_H

#include "systemtype.h"


//  --------   线性表的双向链表存储结构   --------------------------
//包含元素、前驱指针，后续指针
typedef struct DuLNode{
	ElemT data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode, *DuLinkList;

//初始化一个双向循环链表，尾指针指向头结点
 Status InitList_DuL(DuLinkList *L)
 { /* 操作结果：构造一个带节点的空的线性表L */
   *L=(DuLinkList)malloc(sizeof(DuLNode)); /* 产生头结点*/
   if(!*L) /* 存储分配失败 */
     exit(OVERFLOW);
   (*L)->next= (*L); /* 指针域指向头结点 */
   (*L)->prior = (*L)->next;      //头结点的前驱指向末结点

   //规定：循环表的末指针指向头结点
   return OK;
 }

//DuLinkList GetElemP_DuL(DuLinkList L,int i) /* 另加 */
//{ /* 在双向链表L中返回第i个元素的位置指针(算法2.18、2.19要调用的函数) */
//	int j;      //这里并没有对i的值做非法判断处理
//	DuLinkList p=L;
//	for(j=1;j<=i;j++)
//	    p=p->next;
//	return p;
//}

 DuLinkList  GetElemP_DuL(DuLinkList L,int i)
 {//检查双向链表L中是否存在位置i
	 //如果存在，返回这个位置的地址，如果不存在，返回ERROR；
	 //条件：L为非空表  i的合法值为 1-表长
	 int j;
	 DuLinkList p,n;
	 p = L;
	 n = L->next;

	 if(i==1)  //i = 1 的时候，返回头指针的next
	 {
		 return  n;
	 }
	 else 
	 {
		 if(p==n)  //空表，也返回头指针的next
		 {
			 return  n;
		 }
		 else  //非空表 且 i 不等于0
		 {
			 j = 1;
			 while(p!=n && j<i)
			 {
				 n = n->next;   //n指针后移
				 j++;
			 }

			 if(p==n && j<i) //如果找到了表尾还是没有找到i
				 return ERROR;
			 else return n;
		 }
	 }
 }

 //算法2.19 
 //双链表 的元素插入
 Status ListInsert_DuL(DuLinkList *L,int i,ElemT e)
 {
	 //在带头结点的双循环链表L中第i个元素之前插入元素e
	 //i 的合法值为1<=i<=表长+1
	 DuLinkList s,p;
	 if(!(p = GetElemP_DuL(*L,i)))return ERROR;    //检验i的合法性，如果它合法，获得这个位置的地址
	 if(!(s = (DuLinkList)malloc(sizeof(DuLNode))))return ERROR;
	 s->data = e;
	 s->prior = p->prior;   //一共要修改四个指针
	 p->prior->next = s;
	 s->next = p;
	 p->prior = s;

	 return OK;
 }

 //算法2.19 
 //删除带头结点的双链表的第i个元素
Status ListDelete_DuL(DuLinkList *L,int i,ElemT *e)
{
	//删除带头结点的双链循环表的第i个元素，合法值为1<=i<=表长
	DuLinkList p;
	if(i==1)
		{ if(!(p = GetElemP_DuL(*L,i)))return ERROR;}
	else
		if(!(p = GetElemP_DuL(*L,i)))return ERROR;
	*e=p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return OK;
}

 //遍历双向表，输出其值
Status LinkListTraverse_DuL(DuLinkList L,void(*vi)(ElemT))
{//遍历输出带头结点的单链表值
	DuLinkList p,n;
	int j=1;
	p=L->next;
	n=L;
	if(n==p)
	{
		printf("empty LinkList");
		return ERROR;
	}
	while(n!=p)
	{
		vi(p->data);		
		p=p->next;

	}
	printf("\r\n");
	return OK;
}

#endif


