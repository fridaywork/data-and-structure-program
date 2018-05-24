/*8
******
  
   第二章第1、2节内容
   包括：
   算法2.1 算法2.2 算法2.7
   需要用到的头文件 ：顺序表的基本操作定义文件
 
***
**
**
*****/

#include "basicList1.h"


//算法2.1 
//union 为共用体声明，无法作为函数名
void unite(SqList *La,SqList Lb)
{//功能：将所有在Lb中但是不在La中的元素插入到La中
	int LaLen,LbLen,i;
	ElemT e;
	LaLen = ListLength(*La); LbLen = ListLength(Lb);   //获取 a b线性表的长度

	for(i = 1;i<=LbLen;i++)
	{
		GetElem(Lb,i,&e);

		if(!LocateElem_Sq(*La,e,equal))ListInsert_Sq(La,++LaLen,e);
	}



}


//算法2.2 
//已知线性表La和Lb中的元素按值非递减排列
//合并La和Lb得到新的线性表Lc，Lc的数据元素也按值非递减排列
void MergeList(SqList La,SqList Lb,SqList *Lc)
{
	int LaLen,LbLen,i=1,j=1,k=0;
	ElemT ai,bj;

	InitList_Sq(Lc);
	LaLen = ListLength(La); LbLen = ListLength(Lb);   //获取 a b线性表的长度
	while((i <= LaLen)&&(j <= LbLen))                 //将线性表a b 中的元素分别非递减存入Lc
	{
		GetElem(La,i,&ai);
		GetElem(Lb,j,&bj);
		if(ai<=bj){ListInsert_Sq(Lc,++k,ai);++i;}
		else{ListInsert_Sq(Lc,++k,bj);++j;}
	}
	while(i<=LaLen)                                //将比较玩后还剩的元素继续存入Lc
	{
		GetElem(La,i++,&ai);
		ListInsert_Sq(Lc,++k,ai);
	}
	while(j<=LbLen)
	{
		GetElem(Lb,j++,&bj);
		ListInsert_Sq(Lc,++k,bj);

	}




}

//算法2.2 
//已知线性表La和Lb中的元素按值非递减排列
//合并La和Lb得到新的线性表Lc，Lc的数据元素也按值非递减排列
//使用更简易的算法完成合并顺序表的操作
void MergeList_easy(SqList La,SqList Lb,SqList *Lc)
{
	int LaLen,LbLen,i=1,j=1,k=0;
	ElemT *pa,*pb,*pc;
	ElemT *pa_last,*pb_last;
	InitList_Sq(Lc);
	pa = La.elem;
	pb = Lb.elem;
	pc = Lc->elem;

	pa_last = La.elem + La.length - 1;
	pb_last = Lb.elem + Lb.length - 1;

	while(pa<=pa_last && pb<=pb_last)
	{
		if(*pa<=*pb)*pc++=*pa++;
		else *pc++=*pb++;

		while(pa<=pa_last)*pc++ = *pa++;
		while(pb<=pb_last)*pc++ = *pb++;
	}

}

void print(ElemT *c)
{
   printf("%d ",*c);
}


int main(void)
{
	SqList L1,L2,L3,L4,L5,L6;
	int i;

	InitList_Sq(&L1);
	InitList_Sq(&L2);
	InitList_Sq(&L3);
	InitList_Sq(&L4);

	for(i=1;i<20;i++)
		ListInsert_Sq(&L1,i,i*2);
	for(i=1;i<10;i++)
		ListInsert_Sq(&L2,i,i+30);

	printf("L1的元素：");
	ListTraverse(L1,print);
	printf("\r\n");
	printf("L2的元素：");
	ListTraverse(L2,print);


	unite(&L1,L2);
	printf("组合完成后的L1：");
	ListTraverse(L1,print);


	for(i=1;i<10;i++)
		ListInsert_Sq(&L3,i,i*2);
	for(i=1;i<10;i++)
		ListInsert_Sq(&L4,i,i+5);

	printf("L3的元素：");
	ListTraverse(L3,print);
	printf("L4的元素：");
	ListTraverse(L4,print);

	MergeList(L3,L4,&L5);

	printf("拼接出来的L5：");
	ListTraverse(L5,print);

	MergeList_easy(L3,L4,&L6);
	printf("拼接出来的L6：");
	ListTraverse(L5,print);

	getchar();
}