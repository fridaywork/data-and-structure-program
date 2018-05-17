/****
***  线性表的指针实现 链表
**
**
**
***/
#include "list_index.h"
#include "malloc.h"

LIST_I L_index;


int InitList(LinkList *L)
{ /* 操作结果：构造一个空的线性表L */
	*L=(LinkList)malloc(sizeof(cellType)); /* 产生头结点,并使L指向此头结点 */
	if(!*L) /* 存储分配失败 */
	   return 0;
	(*L)->next= NULL ; /* 指针域为空 */
	   return 1;
}

//单链表的建立   
//头插法
LinkList CreatList1(LinkList Li)
{
	cellType *s;
	ElemType x;
//	Li = (LinkList)malloc(sizeof(cellType));    //用动态内存分配形式创建链表头结点，注意，Li始终为头结点，输出和对单链表操作都是从头结点开始
	//因为引入了InitList函数，不需要再创建表头；
//	Li->next = 0x0000;                          //默认0 为null  
	printf("请输入链表元素值，输入999结束 \r\n");
	scanf("%d",&x);
	while(x!= 999)    //识别999为结束值
	{

		s = (cellType*)malloc(sizeof(cellType));    //创建一个新节点并给节点分配内存地址
		s ->elem = x;
		s ->next =Li->next;                          //新插入的节点为尾节点，调整其next为null
		Li->next = s;                                //头插法的Li为头结点，指向新插入的元素
		printf("请输入链表元素值，输入999结束 \r\n");
		scanf("%d",&x);
	}
	return Li;

}

//遍历输出单链表的所有节点的值
void scanLinkList(LinkList Li)
{
	int i = 10;
	ElemType tempout;
	LinkList tempLink;
	printf("单链表的值为：");
	tempLink = Li->next;
	while(tempLink != 0)
	{			
			tempout = tempLink->elem;
			printf("%d,",tempout);
			tempLink = tempLink->next;     //如果获取到的指针为0，也就是到了表尾， tempout的取值语句将无法执行，程序会造成内存冲突
	}
	printf("\r\n");

}


void Insert_I(ElemType x,position_i po)
{
	position_i temp;
	temp = po->next;
//	po->next = new celltype;
	po->next->elem = x;
	po->next->next = temp;

}

