
#include "basicList1.h"

#include "basicList2.h"
#include "basicList3.h"
#include "basicList4.h"
#include "basicList5.h"


void print(ElemT *c)
{
   printf("%d ",*c);
}

void view(ElemT e)
{
   printf("%d  ",e);
}
//使用条件编译进行调试，以避免多余的文件产生
//#define shunxubiao
#define danlianbiao
//#define jingtaibiao
//#define shuangxiangbiao

int main(void)
{
	int i;
#ifdef  shunxubiao
	SqList Li;
	int po,scan;
	ElemT temp;
	InitList_Sq(&Li);

	for(i=0;i<=30;i++)
	{
		ListInsert_Sq(&Li,i,i);
	}
	scan = 25;
	po = LocateElem_Sq(Li,scan,equal);
	printf("第一个%d 的位置是 %d ;\r\n",scan,po);
	
	po = 8;
	ListDelete_Sq(&Li,po,&temp);
	printf("删除的元素位置%d ，值 = %d ;\r\n",po,temp);
	ListTraverse(Li,print);
	scan = 25;
	po = LocateElem_Sq(Li,scan,equal);
	printf("删除操作后第一个%d 的位置是 %d ;\r\n",scan,po);

	temp = ListLength(Li);
	printf("当前线性表的长度 %d ;\r\n",temp);
	po = 3;
	GetElem(Li,po,&temp);
	printf("在 %d 获得的元素值 %d", po,temp);
	
#endif


#ifdef  danlianbiao
	LinkList Li1,Li2;
	ElemT temp;

	LinkList_s LL1,LL2;
	Link_s t;
	Position_s high,tall;
//特别说明  单链表本质上是用地址来存储的，其本体为一个指针变量，存储头结点或者头指针的地址，所以在修改它的值的时候，要使用指向地址的指针获得其地址值
	//然后送给函数传递进内部进行修改操作



	//CreatList_L(&(Li1),5);
	//i=5;
	//LinkListTraverse(Li1,view);

	//if(GetElem_L(Li1,3,&temp))
	//	printf("Li1 位置3 的元素值为%d",temp);
	InitList_CL(&Li2);
	for(i=1;i<10;i++)
		ListInsert_L(&Li2,i,i*2);
	printf("单链表2的值：  ");
	LinkListTraverse(Li2,view);
	if(ListDel_L(&Li2,7,&temp))
		printf("Li2被删除的元素 %d \r\n",temp);
	printf("删除后Li2的值：");
	LinkListTraverse(Li2,view);
	//CreatLinkList_Tail(&Li2,3);
	//LinkListTraverse(Li2,view);

	InitList_s(&LL1);
	InitList_s(&LL2);
	for(i=1;i<10;i++)
		ListInsert_s(&LL1,1,i*2);
	printf("单链表LL1的值： ");
	LinkListTraverse_s(LL1,view);
	printf("表长为%d \r\n",LL1.len);

	DelFirst(LL1.head,&t);
	LL1.len --;
	LinkListTraverse_s(LL1,view);
	printf("被删除的节点值%d  表长为%d \r\n",t->data,LL1.len);

	for(i=1;i<5;i++)
	{
		ListInsert_s(&LL2,1,i);
	}
	printf("单链表LL2的值： ");
	LinkListTraverse_s(LL2,view);
	printf("表长为%d \r\n",LL2.len);

	Append(&LL1,LL2.head->next->next);
	printf("拼接后单链表LL1的值： ");
	LinkListTraverse_s(LL1,view);
	printf("表尾的元素为%d \r\n",LL1.tail->data);

	high = GetHead(LL2);
	tall = GetLast(LL2);
	printf("%d %d \r\n",high->next->data,tall->data);
	temp = GetCurElem(tall);
	printf("%d \r\n",temp);

#endif

#ifdef jingtaibiao   //静态表
	SLinkList Sma;  //创建母空间
	int son,j,tail;        //子表
	InitSpace_SL(Sma);

	tail = Malloc_SL(Sma);    //在母体中创建儿子表
	son = tail;             //记录儿子表的表头位置
	for(i=1;i<28;i++)
	{
		j = Malloc_SL(Sma);
		Sma[j].data = i;
		Sma[tail].cur = j;
		tail = j;
	}
	Sma[tail].cur = 0;

	ListTraverse_SL(Sma,son,view);

#endif

#ifdef shuangxiangbiao  //双向表
	DuLinkList Dl1;
	ElemT temp;
	InitList_DuL(&Dl1);

	for(i=1;i<10;i++)
	{
		ListInsert_DuL(&Dl1,1,i*2);
	}
	LinkListTraverse_DuL(Dl1,view);
	ListInsert_DuL(&Dl1,5,55);
	ListInsert_DuL(&Dl1,11,666);
	LinkListTraverse_DuL(Dl1,view);
	
	if(ListDelete_DuL(&Dl1,11,&temp))
		printf("被删除的元素 %d \r\n",temp);
	printf("删除后表的值：");
	LinkListTraverse_DuL(Dl1,view);


#endif


scanf_s("%d",&i);
}