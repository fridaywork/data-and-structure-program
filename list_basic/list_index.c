/****
***  ���Ա��ָ��ʵ�� ����
**
**
**
***/
#include "list_index.h"
#include "malloc.h"

LIST_I L_index;


int InitList(LinkList *L)
{ /* �������������һ���յ����Ա�L */
	*L=(LinkList)malloc(sizeof(cellType)); /* ����ͷ���,��ʹLָ���ͷ��� */
	if(!*L) /* �洢����ʧ�� */
	   return 0;
	(*L)->next= NULL ; /* ָ����Ϊ�� */
	   return 1;
}

//������Ľ���   
//ͷ�巨
LinkList CreatList1(LinkList Li)
{
	cellType *s;
	ElemType x;
//	Li = (LinkList)malloc(sizeof(cellType));    //�ö�̬�ڴ������ʽ��������ͷ��㣬ע�⣬Liʼ��Ϊͷ��㣬����ͶԵ�����������Ǵ�ͷ��㿪ʼ
	//��Ϊ������InitList����������Ҫ�ٴ�����ͷ��
//	Li->next = 0x0000;                          //Ĭ��0 Ϊnull  
	printf("����������Ԫ��ֵ������999���� \r\n");
	scanf("%d",&x);
	while(x!= 999)    //ʶ��999Ϊ����ֵ
	{

		s = (cellType*)malloc(sizeof(cellType));    //����һ���½ڵ㲢���ڵ�����ڴ��ַ
		s ->elem = x;
		s ->next =Li->next;                          //�²���Ľڵ�Ϊβ�ڵ㣬������nextΪnull
		Li->next = s;                                //ͷ�巨��LiΪͷ��㣬ָ���²����Ԫ��
		printf("����������Ԫ��ֵ������999���� \r\n");
		scanf("%d",&x);
	}
	return Li;

}

//�����������������нڵ��ֵ
void scanLinkList(LinkList Li)
{
	int i = 10;
	ElemType tempout;
	LinkList tempLink;
	printf("�������ֵΪ��");
	tempLink = Li->next;
	while(tempLink != 0)
	{			
			tempout = tempLink->elem;
			printf("%d,",tempout);
			tempLink = tempLink->next;     //�����ȡ����ָ��Ϊ0��Ҳ���ǵ��˱�β�� tempout��ȡֵ��佫�޷�ִ�У����������ڴ��ͻ
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

