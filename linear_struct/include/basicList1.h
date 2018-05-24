/****
***
顺序表基本操作实现函数
在main函数中验证这些函数的有效性
算法2.3

**
********************/


#ifndef  __BASICLIST1_H
#define  __BASICLIST1_H

#include  "systemtype.h"
#include  "malloc.h"
#include  "stdlib.h"

//算法2.3  建立动态一维数组结构
#define LIST_INIT_SIZE   10  
#define LISTINCREMENT    10

typedef struct{
	ElemT  *elem;     //数组基址
	int    length;	//当前长度
	int    listsize;   //当前分配的存储容量
}SqList;

Status InitList_Sq(SqList *L)
{
	//构造一个空的顺序表L，以动态方式分配内存
	L->elem = (ElemT*)malloc(LIST_INIT_SIZE*sizeof(ElemT));
	if(!L->elem)exit(OVERFLOW);  //fail to allot
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}// InitList_Sq



//算法2.4 顺序表中插入元素
Status ListInsert_Sq(SqList *L,int i,ElemT  e)
{
	ElemT *newbase,*q,*p;
	//在顺序表L中第I个位置插入新元素E
	if(i<1 || i>L->length+1) return  ERROR;   //i是否合法
	if(L->length >= L->listsize){            //当前空间已满，增加分配  
		newbase = (ElemT*)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemT));
		if(!newbase)exit(OVERFLOW);
		L->elem = newbase;     //新基址传递
		L->listsize += LISTINCREMENT;
	}

	q= &(L->elem[i-1]);
	for(p =&(L->elem[L->length-1]);p>=q;--p)
		*(p+1)=*p;       //插入前先后移所有的元素
	*q = e;
	++L->length;
	return OK;
}//ListInsert_Sq


//算法2.5 删除顺序表中的元素
Status ListDelete_Sq(SqList *L,int i,ElemT  *e)
{
	ElemT *p,*q;
	//顺序表中删除第i个元素，并用e返回其值
	if(i<1 || i>L->length)return ERROR;
	p = &L->elem[i-1];   //获取元素地址
	*e=*p;   //获取元素值
	q=L->elem + L->length -1;  //获取表尾元素地址，用于前移元素
	for(p=p+1;p<=q;++p)*(p-1)=*p;
	L->length--;
	return OK;

}

//算法2.6  在顺序表中查找第一个与E相同的值

char equal(ElemT a,ElemT b)      
{//判断两个元素是否想等，是返回1，否返回0；
	char result;
	a=b?(result = 1):(result = 0);
	return result;
}
 int LocateElem(SqList L,ElemT e,Status(*compare)(ElemT,ElemT))
 { /* 初始条件：顺序线性表L已存在，compare()是数据元素判定函数(满足为1,否则为0) */
   /* 操作结果：返回L中第1个与e满足关系compare()的数据元素的位序。 */
   /*           若这样的数据元素不存在，则返回值为0。算法2.6 */
	 int  i;
	 ElemT *p;
	 i = 1;
	 p = L.elem;
	 while(i<=L.length && !(*compare)(*p,e))
	 {
		 p++;
		 i++;
	 }
	 if(i<= L.length)return i;
	 else return 0;
	 
 }

//遍历顺序表，输出其值

Status ListTraverse(SqList L,void(*vi)(ElemT*))
{
	/* 初始条件：顺序线性表L已存在 */
   /* 操作结果：依次对L的每个数据元素调用函数vi()。一旦vi()失败，则操作失败 */
   /*           vi()的形参加'&'，表明可通过调用vi()改变元素的值 */
	ElemT *p;
	int i;
	p=L.elem;
	for(i=1;i<=L.length;i++)
	{
		vi(p++);
	}
	printf(" \r\n");
	return OK;
}


#endif



