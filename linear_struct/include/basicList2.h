/***
**   单链表的定义与基本操作 
	
**   
***
**
***********************/


#ifndef  __BASICLIST2_H
#define  __BASICLIST2_H

#include "systemtype.h"

//单链表的存储结构定义
typedef struct LNode{
	ElemT data;
	struct LNode *next;

}LNode,*LinkList;

//用于自动生成线性表，不需要每次都输入
 Status InitList_CL(LinkList *L)
 { /* 操作结果：构造一个带节点的空的线性表L */
   *L=(LinkList)malloc(sizeof(LNode)); /* 产生头结点*/
   if(!*L) /* 存储分配失败 */
     exit(OVERFLOW);
   (*L)->next= NULL; /* 指针域指向头结点 */
   return OK;
 }

//算法2.8 
//单链表中取出位置I的元素
Status GetElem_L(LinkList L,int i,ElemT *e)
{
	//L为带头结点的单链表的头指针
	//当第i个元素存在时，赋值给E并回传，否则返回ERROR
	int j;
	LinkList p;   
	p = L->next;  //初始化临时指针和计数器，从第一个元素开始找
	j=1;
	while(p&&j<i) //当p非0时，不是尾节点，p=0，即p=null，为尾节点
	{
		p=p->next;
		j++;
	}
	if(!p||j>i)return ERROR;
	*e = p->data;
	return OK;

} //GetElem_L

//算法2.9
//在L中第i个位置前插入e
Status ListInsert_L(LinkList *L ,int i,ElemT e)
{
	//在带头结点的单链表L中的第i个位置之前插入元素e
	LinkList p,s;
	int j=0;
	p=*L;                  //从头结点开始
	while(p&&j<i-1)     //因为位置i可能是1，即第一个元素，所以j从0开始，遍历找到位置i-1个节点
	{
		p=p->next;
		j++;
	}
	if(!p||j>i-1)  //if i-1大于表长，while中的j<i-1 恒为1,假如i的输入值为负数，或者0，也是非法的
	{
		printf("请求的位置是非法的 \r\n");
		return ERROR;
	}

	s =(LinkList)malloc(sizeof(LNode));  //定义节点后，需要分配内存，否则无法操作
	s->data = e;
	s->next =p->next;
	p->next = s;
	return OK;
}

//算法2.10
//在L中删除第i个元素并用e返回其值
Status ListDel_L(LinkList *L,int i,ElemT *e)
{//在带头结点的单链表L中删除第i个元素并用e返回其值
	LinkList p,q;
	int j=1;
	p=(*L)->next;   //注意起始位置，从第一个元素开始
	while(p&&j<i-1)      //找到第i个节点的前驱，将P指向它
	{
		p=p->next;
		j++;
	}
	if(!p||j>i-1)
	{
		printf("请求的位置是非法的 \r\n");
		return ERROR;
	}
	q=p->next;            //q就是第i个节点的地址
	p->next = q->next;    //将i+1和i-1连起来
	*e = q->data;         
	free(q);			//这样q就是多余的了，删掉,释放内存
	return OK;
}

//算法2.11
//创建一个
void CreatList_L(LinkList *L,int n)
{//逆序输入n个元素值建立带头结点的单链表L，采用头插法
	int i;
	LinkList p;
	(*L)=(LinkList)malloc(sizeof (LNode));
	if(!L)
	{
		printf("内存分配失败 \r\n");
		exit(OVERFLOW);  //fail to allot
	}
	(*L)->next = NULL ;  //建立头结点，分配内存

	printf("请输入%d个整数,用回车分隔\r\n",n);
	for(i=n;i>0;i--)
	{
		p = (LinkList)malloc(sizeof(LNode));
		if(!p)
		{
			printf("内存分配失败 \r\n");
			exit(OVERFLOW);  //fail to allot
		}
		scanf_s("%d",&(p->data));
		p->next = (*L)->next;
		(*L)->next =p;
	}
	printf("\r\n");
}  //CreatList_L

//采用尾插法建立一个单链表
void CreatLinkList_Tail(LinkList *L,int n)
{
//顺序输入n个元素值建立带头结点的单链表L，采用尾插法
	int i;
	LinkList p,q;
	(*L)=(LinkList)malloc(sizeof (LNode));
	if(!L)
	{
		printf("内存分配失败 \r\n");
		exit(OVERFLOW);  //fail to allot
	}
	(*L)->next = NULL ;  //建立头结点，分配内存
	p=(*L);        //获取头结点的地址

	printf("请输入%d个整数,用回车分隔\r\n",n);
	for(i=n;i>0;i--)
	{
		q=(LinkList)malloc(sizeof(LNode));
		if(!q)
		{
			printf("内存分配失败 \r\n");
			exit(OVERFLOW);  //fail to allot
		}	
		scanf_s("%d",&(q->data));
		p->next =q;                   //先将头结点连接
		p=p->next;
	}
	q->next = NULL;    //修复尾指针的值

	printf("\r\n");
}




//遍历单链表，输出其值
Status LinkListTraverse(LinkList L,void(*vi)(ElemT))
{//遍历输出带头结点的单链表值
	LinkList p;
	int j=1;
	p=L->next;
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


