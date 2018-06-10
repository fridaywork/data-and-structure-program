/***********8
**
*	抽象数据型Polynomial的实现
*   多项式加减法
*   多项式乘法运算
*
***
****************************/

#ifndef   _BASICLIST6_H
#define   _BASICLIST6_H



#define poly   //开启elemtype的编译开关

#include "basicList5.h"
#include "systemtype.h"



//typedef struct{
//	float coef; //系数
//	int   expn; //指数
//}term,ElemType;


typedef LinkList_s polynomial;


int cmp(term a,term b)
{//8 根据a的指数值 大于 等于 小于   b 返回 1，0，-1
	if(a.expn >b.expn)
		return 1;
	else if (a.expn==b.expn)
		return 0;
	else return -1;
}


Status same(term a,term b)
{
	int re;
	re = (a.expn == b.expn)?1:0;   //想等返回1，不相等返回0
	return re;
}

Status InitPolyn(polynomial *polyn)
{
	if(InitList_s(polyn))return OK;
}

//基本操作
void CreatPolyn(polynomial *polyn,int m)
{//1 输入m项的系数和指数，建立表示一元多项式的有序表poly
	int i;
	Link_s h,s;
	term e;
	InitList_s(polyn);
	h = GetHead(*polyn);  //获取头结点的地址
	e.coef = 0.0;
	e.expn = -1;
	SetCurElem(&h,e);
	for(i=1;i<=m;i++)   //依次输入n个非零项，这一版中确保每次输入的指数不同，否则为非法
	{
		printf("请按照 系数 指数 的格式依次输入%d个一元项\r\n",m);
		scanf("%f,%d",&e.coef,&e.expn);
		if(!LocateElem(*polyn,e,same))//当链表中不存在该指数的项时
		{
			if(MakeNode(&s,e)) InsFirst(&h,s); //生成节点并插入链表
		}
	}


}

void DestroyPolyn(polynomial *p)
{//2销毁多一元项式p
	p->head->next = NULL;  //将p置为空表，这不予考虑内存释放的事情
}

void PrintPolyn(polynomial p)
{//3 打印一元多项式p
	Link_s first;
	first = p.head->next;
	if(!first)
	{
		printf("the polynomial is empty");
	}
	
	while(first)
	{
		if(first->data.coef > 0 )
		{
			printf("+%0.2fX^%d ",first->data.coef,first->data.expn);
		}
		else if (first->data.coef == 0);
		else
		{
			printf("%0.2fX^%d ",first->data.coef,first->data.expn);

		}
		first = first->next;
	}
	printf("\r\n");
	
}

void PolynLength(polynomial p)
{//4 返回一元多项式p中的项数
}

//算法2.23
void Addpolyn(polynomial *pa,polynomial *pb)
{//5 完成多项抄自课本的算法只能适用于pb和pa的元素按照降序或者升序排序的情况下的多项式相加，假如不是如此，pb中的项只会处理第一项的合并
	Link_s ha,hb,qa,qb;
	term a,b,sum;

	ha = GetHead(*pa);
	hb = GetHead(*pb);   ///获取多项式a和多项式b的头结点
	qa = NextPos(*pa,ha); 
	qb = NextPos(*pb,hb); //获取第一个节点
	while(qa&&qb)      //qa和qb都不是null
	{
		a = GetCurElem(qa);
		b = GetCurElem(qb);
		switch(cmp(a,b))
		{
			case -1: //多项式PA中当前节点的指数值小
				ha = qa;
				qa = qa->next;
				break;
			case 0: //pa和pb的当前项指数想等
				sum = a;
				sum.coef = a.coef + b.coef ;
				if(sum.coef != 0.0)   //没有抵消，将相加的结果存入pa
				{
					SetCurElem(&qa,sum);
					ha = qa;
				}
				else  //抵消掉了，删除pa中的当前节点
				{
					DelFirst(ha,&qa);
					FreeNode(&qa);
				}
				DelFirst(hb,&qb);
				FreeNode(&qb);
				qb = NextPos(*pb,hb);
				qa = NextPos(*pa,ha);
				break;
			case 1:     //pb的当前节点指数值小
				DelFirst(hb,&qb);
				InsFirst(&ha,qb);
				FreeNode(&qb);
				ha = NextPos(*pa,ha);
				break;
		} //switch
					
	}//while 
	if(!ListEmpty(*pb))Append(pa,qb);  //链接Pb中的剩余节点
	FreeNode(&hb);
}

//算法2.23改进
void AddpolynFix(polynomial *pa,polynomial *pb)
{//5 完成多项式的相加运算 即 Pa = Pa+Pb 并销毁Pb
//对严奶奶的程序进行优化，将乱序的两个多项式a 和 b合并
//这个程序不再默认多项式是升序或者降序排列了
//这样需要比较pa和pb中的每一项
	Link_s ha,hb,qa,qb;
	term a,b,sum;

	ha = GetHead(*pa);
	hb = GetHead(*pb);   ///获取多项式a和多项式b的头结点
	qa = NextPos(*pa,ha); 
	qb = NextPos(*pb,hb); //获取第一个节点
	a = GetCurElem(qa);
	while(qb)      //需要对表多项式b遍历插入
	{
		
		b = GetCurElem(qb);
		//将pb中的元素与pa的元素逐个比较
		while(qa&&(!same(a,b)))
		{
			qa = qa->next;
			if(qa)
				a = GetCurElem(qa);
		}//while	

		if(same(a,b))
		{
				 //pa和pb的当前项指数相等
				sum = a;
				sum.coef = a.coef + b.coef ;
				if(sum.coef != 0.0)   //没有抵消，将相加的结果存入pa
				{
					SetCurElem(&qa,sum);
				}
				else  //抵消掉了，删除pa中的当前节点
				{
					DelFirst(ha,&qa);
					FreeNode(&qa);
				}
				DelFirst(hb,&qb);     //同时删除b中的对应节点
				FreeNode(&qb);				
		} 
		else      //当前项的指数不相等，直接将qb插入pa
		{
			DelFirst(hb,&qb);
			InsFirst(&ha,qb);
		//	ha = NextPos(*pa,ha); //默认插入的节点在新插入的节点之后
		}

		qb = NextPos(*pb,hb);
		qa = (*pa).head->next;
	}//while 
//	if(!ListEmpty(*pb))Append(pa,qb);  //链接Pb中的剩余节点
	FreeNode(&hb);
}

void Subtrctpolyn(polynomial *pa,polynomial *pb)
{//6 完成多项式的相减运算 即 Pa = Pa-Pb；并销毁Pb
	//总体上来说，相减和相加是差不多的
	//将P项的所有系数处理成相反数，然后再相加就可以了
}

void MultiplyPolyn(polynomial *pa,polynomial *pb)
{//7 完成多项式的相乘运算，Pa=Pa*Pb ，并销毁Pb

}



#endif
