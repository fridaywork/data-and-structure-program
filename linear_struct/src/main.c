
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
	printf("��һ��%d ��λ���� %d ;\r\n",scan,po);
	
	po = 8;
	ListDelete_Sq(&Li,po,&temp);
	printf("ɾ����Ԫ��λ��%d ��ֵ = %d ;\r\n",po,temp);
	ListTraverse(Li,print);
	scan = 25;
	po = LocateElem(Li,scan,equal);
	printf("ɾ���������һ��%d ��λ���� %d ;\r\n",scan,po);

	temp = ListLength(Li);
	printf("��ǰ���Ա�ĳ��� %d ;\r\n",temp);
	po = 3;
	GetElem(Li,po,&temp);
	printf("�� %d ��õ�Ԫ��ֵ %d", po,temp);
	scanf_s("%d",&i);
}