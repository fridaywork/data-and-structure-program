/****
**  静态链表的基本操作
**  链表游标化
**
************************************/


#ifndef __BASICLIST_H
#define __BASICLIST_H

#include "systemtype.h"

//静态表的声明宏
#define MAXSIZE 100

typedef struct{

	ElemT data;
	int   cur;

}component,SLinkList[MAXSIZE];

//算法2.13
//静态表的元素查找
int LocateElem_SL(SLinkList S,ElemT e)
{//在静态表中查找第1个值为e的元素
	//若找到，则返回它在L中的位置，否则返回0
	int i;
	i = S[0].cur;
	while(i&&S[i].data != e)
		i=S[i].cur;
	return i;
} //locate


//算法2.14
//将整个数组空间各个分量链成一个备用链表，space[0].cur 作为头指针
// “0”表示空指针
void InitSpace_SL(SLinkList space)	      //数组名本身就是一个地址，实际上传递数组名就是传递地址
{
//将整个数组空间各个分量链成一个备用链表，space[0].cur 作为头指针
// “0”表示空指针
	int i;
	for(i = 0;i<MAXSIZE-1;++i)
		space[i].cur = i+1;        //游标范围为1到maxsize 相当于内存地址

	space[MAXSIZE-1].cur = 0;      //尾节点指向NULL

}

//算法2.15
//模拟动态内存分配，在备用表中开辟空间给节点
int Malloc_SL(SLinkList space)
{///若备用链表为非空，则返回分配给节点的下标，否则返回0
	int i = space[0].cur;
	if(space[0].cur)
		space[0].cur = space[i].cur;
	return i;
}

//算法2.16
//释放空闲节点
void Free_SL(SLinkList space ,int k)
{//释放下标为K的空闲节点，将其回收到备用表中
	space[k].cur = space[0].cur;
	space[0].cur = k;

}



//在母空间内，输出其对应的静态表，输出其值
Status ListTraverse_SL(SLinkList S,int son,void(*vi)(ElemT))
{
	/*输入参数 母空间  子表头结点  遍历输出函数*/
   /* 操作结果：依次对L的每个数据元素调用函数vi()。一旦vi()失败，则操作失败 */
   /*           vi()的形参加'&'，表明可通过调用vi()改变元素的值 */
	int i;
	i=S[son].cur;
	while(i)        //i = 0 判断为表结束
	{
		vi(S[i].data);
		i = S[i].cur;
	}
	printf("\r\n");
	return OK;
}


#endif
