/****---------------------------------------
***   2.3
***   带头结点的线性表的定义与各项操作
***   
**    
************************************--------******/


#ifndef _BASICLIST5_H
#define _BASICLIST5_H


#include "systemtype.h"

#include "basicList6.h"


#ifndef  poly

typedef int  ElemType;

#endif

#ifdef poly

typedef struct 
term{
	float coef; //系数
	int   expn; //指数
}term,ElemType;

#endif



typedef struct LNode_s{
	ElemType		data;
	struct LNode_s	*next;
}LNode_s,*Link_s,*Position_s;

typedef struct{
	Link_s head,tail;     //头指针和尾指针
	int  len;          //线性表的元素长度
}LinkList_s;


Status InitList_s(LinkList_s *L)
{//1构造一个空的线性表L
	Link_s p;
	p = (Link_s)malloc(sizeof(LNode_s)); /* 产生头结点*/
	if(!(p)) /* 存储分配失败 */
	 exit(OVERFLOW);
	(p)->next= NULL; /* 指针域指向头结点 */

	L->head =p;
	L->tail =p;
	L->len  = NULL;


	return OK;
}

Status MakeNode(Link_s *s,ElemType e)
{//2分配由p指向值为e的节点，并返回OK，若分配失败，返回ERROR
	Link_s p;
	
	p = (Link_s)malloc(sizeof(LNode_s)); /* 产生头结点*/
	if(!(p)) /* 存储分配失败 */
	 return ERROR;
	(p)->next= NULL; /* 指针域指向头结点 */

	p->data = e;
	*s=p;
	return OK;
}

void FreeNode(Link_s *p)
{//3释放p所指的节点
	free(*p);
	*p = NULL;
}

Status DestroyList(LinkList_s *L)
{//4销毁线性表L，L将不再存在，并释放L占用的内存

}

Status ClearList(LinkList_s  *L)
{//5将线性表L重置为空表，并释放原来链表的节点空间
}



Status InsFirst(Link_s *h,Link_s s)
{//6已知h指向线性链表的头结点，将s所指的节点插入在第一个节点之前
	//插入后头结点指向s，节点地址不变但是节点内容已被修改，返回其值即可
	Link_s p;
	p= *h;
	s->next = p->next;
	p->next = s;

	return OK;
}

Status DelFirst(Link_s h,Link_s *q)
{//7已知h指向线性链表的头结点，删除表中的第一个节点并以q返回其节点

	Link_s tn;

	if(!(h->next))   //如果表是空表，则无法返回其值
		return ERROR;

	tn = h->next;
	h->next=h->next->next; //连接第二个节点到头结点

	MakeNode(q,tn->data);   //将这个节点用q返回
	FreeNode(&tn);       //释放这个节点的内存
	return OK;
	//因为要返回节点的地址，不可以直接将节点占用的内存释放

}

Status Append(LinkList_s *L,Link_s s)
{//8将指针s所指的一串节点（一个链表的子表或其本身）链接在线性链表L的最后一个节点
 //之后，并改变链表L的尾指针指向新的尾节点
	L->tail->next = s;      //直接将L的尾节点指向s，默认s自带尾节点
	while(s->next)
	{
		s=s->next;  //查找s的尾节点
	}
	L->tail = s;   //更新L的尾节点
	
}

Status Remove_s(LinkList_s *L,Link_s *q)
{//9删除线性链表L中的尾节点并以q返回，改变L的尾指针指向新的尾节点

}

Status InsBefore(LinkList_s *L ,Link_s *p,Link_s s)
{//10已知p指向线性链表L中的一个节点，将s所指节点插入在p所指的节点之前
	//并修改指针p指向新插入的节点
}

Status InsAfter(LinkList_s *L,Link_s *p,Link_s s)
{//11已知p指向线性链表L中的一个节点，将s所指的节点插入在P所致的节点之后
//并修改p指针
}

Status SetCurElem(Link_s *p,ElemType e)
{//12已知p指向表中的一个节点，用e更新p所指的节点中的元素数据值
	(*p)->data = e;
	return OK;
}

ElemType GetCurElem(Link_s p)
{//13已知p指向表中的一个节点，返回p所指的节点中的数据元素的值
	return p->data;
}

Status ListEmpty(LinkList_s L)
{//14若L为空表，返回ture，否则返回false
	if(L.head->next)
		return FALSE;
	else 
		return TURE;
}

int ListLength_s(LinkList_s L)
{//15返回线性表L中的元素个数
	return L.len;
}


Position_s GetHead(LinkList_s L)
{//16返回线性表L中头结点的位置
	return L.head;
}

Position_s GetLast(LinkList_s L)
{//17返回线性表L中最后一个节点的位置
	return L.tail;
}

Position_s PriorPos(LinkList_s L ,Link_s p)
{//18 已知p指向线性表L中的一个节点，返回p所指的直接前驱的位置
	//若无前驱，返回NULL
	Link_s t;
	if(p=L.head)
		return NULL;
	t = L.head;
	while(t->next != p)   //找到L中p节点的前驱
		t=t->next;
	return t;

}

Position_s NextPos(LinkList_s L ,Link_s p)
{//19 已知p指向线性表L中的一个结点，返回p指向的节点的直接后继位置
	//若无后继，则返回NULL

	Position_s t;
	if(p->next)
	{	
		t = p->next;
		return t;
	}
	else 
		return NULL;

}

Status LocatePos(LinkList_s L,int i,Link_s *p)
{//20 返回指示线性表中第i个节点的位置并返回OK，i值不合法时返回ERROR
	int j;
	Link_s temp;
	if(i<0)return ERROR; //i有效值为0到表长，i=0的时候返回表头
	else if(i==0){*p = L.head;return OK;}

	//if(ListEmpty(L)&&i>0)      //对于空表，元素个数为0，直接返回错误
	//{
	//	printf("所求表是空表");
	//	return ERROR;
	//}  

	temp = L.head;
	for(j=0;j<=i;j++); //从表头开始找
	{
		if(temp->next)   //查找一直到表尾
			temp=temp->next;
		else //如果到了表尾
		{
			if(j<i)  //i超过了表长
			{
				printf("i值超过范围");
				return ERROR;
			}
		}
	}

	*p = temp;   //返回找到位置的地址
	return OK;
}  

Position_s LocateElem(LinkList_s L,ElemType e,Status (*compare)(ElemType,ElemType))
{//21 返回线性表L中第一个与e满足compare()判定关系的元素位置
	//若不存在这样的元素，返回NULL
	Link_s p;
	p= L.head;
	if(p->next == 0)  return NULL;  //空表无法查询
	while((p->next)&&(!(*compare)(p->data,e)))  //想等或者查找到表尾时退出
	{
		p=p->next;
	}

	if(!(*compare)(p->data,e))  //没找到e的相等项
		return NULL;
	else 
		return p;       //p就是要找的项

}

//22 算法2.20
//  插入元素
Status ListInsert_s(LinkList_s *L,int i,ElemType e)
{//在带头结点的单链表L的第i个元素之前插入元素e
	Link_s h,s;
	if(!LocatePos(*L,i-1,&h)) return ERROR; //获得第i个节点，地址赋给h
	if(!MakeNode(&s,e)) return ERROR;
	InsFirst(&h,s);  //在h的前面插入s，这里不严谨地认为是插入第i个节点开始的链表的头结点前面
	if((*L).len == NULL)  //如果L本来是个空表，则处理一下尾指针
	{
		L->tail = s;   //对于空表，这里h成了尾节点
	}
	(*L).len++;     //表长加一
	return OK;
}

#ifndef poly
int compare(ElemType a,ElemType b)  //判断a和b是否是非递减关系,是则返回1，否则返回0
{
	int temp;
	temp = (a <= b)?1:0;
	return temp;
}
#endif


//遍历单链表，输出其值
Status LinkListTraverse_s(LinkList_s L,void(*vi)(ElemType))
{//遍历输出带头结点的单链表值
	Link_s p;
	int j=1;
	p = L.head->next;
	if(!p)
	{
		printf("empty LinkList");
		return ERROR;
	}
	while(p)
	{
		vi(p->data);		
		p=p->next;

	}
	printf("\r\n");
	return OK;
}

#endif




