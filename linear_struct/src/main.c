
#include "basicList1.h"





void print(ElemT *c)
{
   printf("%d ",*c);
}


int main(void)
{
	SqList Li;
	int i,po;
	ElemT temp;
	InitList_Sq(&Li);

	for(i=0;i<=30;i++)
	{
		ListInsert_Sq(&Li,i,i);
	}
	po = 8;
	ListDelete_Sq(&Li,po,&temp);
	printf("ɾ����Ԫ��λ��%d ��ֵ = %d ;\r\n",po,temp);
	ListTraverse(Li,print);


	scanf_s("%d",&i);
}