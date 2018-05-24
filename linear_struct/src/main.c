
#include "basicList1.h"





void print(ElemT *c)
{
   printf("%d ",*c);
}


int main(void)
{
	SqList Li;
	int i,po,scan;
	ElemT temp;
	InitList_Sq(&Li);

	for(i=0;i<=30;i++)
	{
		ListInsert_Sq(&Li,i,i);
	}
	scan = 25;
	po = LocateElem(Li,scan,equal);
	printf("第一个%d 的位置是 %d ;\r\n",scan,po);
	
	po = 8;
	ListDelete_Sq(&Li,po,&temp);
	printf("删除的元素位置%d ，值 = %d ;\r\n",po,temp);
	ListTraverse(Li,print);
	scan = 25;
	po = LocateElem(Li,scan,equal);
	printf("删除操作后第一个%d 的位置是 %d ;\r\n",scan,po);

	temp = ListLength(Li);
	printf("当前线性表的长度 %d ;\r\n",temp);
	po = 3;
	GetElem(Li,po,&temp);
	printf("在 %d 获得的元素值 %d", po,temp);
	scanf_s("%d",&i);
}