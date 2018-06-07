
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
//ʹ������������е��ԣ��Ա��������ļ�����
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
	printf("��һ��%d ��λ���� %d ;\r\n",scan,po);
	
	po = 8;
	ListDelete_Sq(&Li,po,&temp);
	printf("ɾ����Ԫ��λ��%d ��ֵ = %d ;\r\n",po,temp);
	ListTraverse(Li,print);
	scan = 25;
	po = LocateElem_Sq(Li,scan,equal);
	printf("ɾ���������һ��%d ��λ���� %d ;\r\n",scan,po);

	temp = ListLength(Li);
	printf("��ǰ���Ա�ĳ��� %d ;\r\n",temp);
	po = 3;
	GetElem(Li,po,&temp);
	printf("�� %d ��õ�Ԫ��ֵ %d", po,temp);
	
#endif


#ifdef  danlianbiao
	LinkList Li1,Li2;
	ElemT temp;

	LinkList_s LL1,LL2;
	Link_s t;
	Position_s high,tall;
//�ر�˵��  �������������õ�ַ���洢�ģ��䱾��Ϊһ��ָ��������洢ͷ������ͷָ��ĵ�ַ���������޸�����ֵ��ʱ��Ҫʹ��ָ���ַ��ָ�������ֵַ
	//Ȼ���͸��������ݽ��ڲ������޸Ĳ���



	//CreatList_L(&(Li1),5);
	//i=5;
	//LinkListTraverse(Li1,view);

	//if(GetElem_L(Li1,3,&temp))
	//	printf("Li1 λ��3 ��Ԫ��ֵΪ%d",temp);
	InitList_CL(&Li2);
	for(i=1;i<10;i++)
		ListInsert_L(&Li2,i,i*2);
	printf("������2��ֵ��  ");
	LinkListTraverse(Li2,view);
	if(ListDel_L(&Li2,7,&temp))
		printf("Li2��ɾ����Ԫ�� %d \r\n",temp);
	printf("ɾ����Li2��ֵ��");
	LinkListTraverse(Li2,view);
	//CreatLinkList_Tail(&Li2,3);
	//LinkListTraverse(Li2,view);

	InitList_s(&LL1);
	InitList_s(&LL2);
	for(i=1;i<10;i++)
		ListInsert_s(&LL1,1,i*2);
	printf("������LL1��ֵ�� ");
	LinkListTraverse_s(LL1,view);
	printf("��Ϊ%d \r\n",LL1.len);

	DelFirst(LL1.head,&t);
	LL1.len --;
	LinkListTraverse_s(LL1,view);
	printf("��ɾ���Ľڵ�ֵ%d  ��Ϊ%d \r\n",t->data,LL1.len);

	for(i=1;i<5;i++)
	{
		ListInsert_s(&LL2,1,i);
	}
	printf("������LL2��ֵ�� ");
	LinkListTraverse_s(LL2,view);
	printf("��Ϊ%d \r\n",LL2.len);

	Append(&LL1,LL2.head->next->next);
	printf("ƴ�Ӻ�����LL1��ֵ�� ");
	LinkListTraverse_s(LL1,view);
	printf("��β��Ԫ��Ϊ%d \r\n",LL1.tail->data);

	high = GetHead(LL2);
	tall = GetLast(LL2);
	printf("%d %d \r\n",high->next->data,tall->data);
	temp = GetCurElem(tall);
	printf("%d \r\n",temp);

#endif

#ifdef jingtaibiao   //��̬��
	SLinkList Sma;  //����ĸ�ռ�
	int son,j,tail;        //�ӱ�
	InitSpace_SL(Sma);

	tail = Malloc_SL(Sma);    //��ĸ���д������ӱ�
	son = tail;             //��¼���ӱ�ı�ͷλ��
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

#ifdef shuangxiangbiao  //˫���
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
		printf("��ɾ����Ԫ�� %d \r\n",temp);
	printf("ɾ������ֵ��");
	LinkListTraverse_DuL(Dl1,view);


#endif


scanf_s("%d",&i);
}