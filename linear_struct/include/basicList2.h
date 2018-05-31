/***
**   ��̬����Ļ������� 
	
**   
***
**
***********************/


#ifndef  __BASICLIST2_H
#define  __BASICLIST2_H

#include "systemtype.h"

//������Ĵ洢�ṹ����
typedef struct LNode{
	ElemT data;
	struct LNode *next;

}LNode,*LinkList;

//�����Զ��������Ա�����Ҫÿ�ζ�����
 Status InitList_CL(LinkList *L)
 { /* �������������һ�����ڵ�Ŀյ����Ա�L */
   *L=(LinkList)malloc(sizeof(LNode)); /* ����ͷ���*/
   if(!*L) /* �洢����ʧ�� */
     exit(OVERFLOW);
   (*L)->next= NULL; /* ָ����ָ��ͷ��� */
   return OK;
 }

//�㷨2.8 
//��������ȡ��λ��I��Ԫ��
Status GetElem_L(LinkList L,int i,ElemT *e)
{
	//LΪ��ͷ���ĵ������ͷָ��
	//����i��Ԫ�ش���ʱ����ֵ��E���ش������򷵻�ERROR
	int j;
	LinkList p;   
	p = L->next;  //��ʼ����ʱָ��ͼ��������ӵ�һ��Ԫ�ؿ�ʼ��
	j=1;
	while(p&&j<i) //��p��0ʱ������β�ڵ㣬p=0����p=null��Ϊβ�ڵ�
	{
		p=p->next;
		j++;
	}
	if(!p||j>i)return ERROR;
	*e = p->data;
	return OK;

} //GetElem_L

//�㷨2.9
//��L�е�i��λ��ǰ����e
Status ListInsert_L(LinkList *L ,int i,ElemT e)
{
	//�ڴ�ͷ���ĵ�����L�еĵ�i��λ��֮ǰ����Ԫ��e
	LinkList p,s;
	int j=0;
	p=*L;                  //��ͷ��㿪ʼ
	while(p&&j<i-1)     //��Ϊλ��i������1������һ��Ԫ�أ�����j��0��ʼ�������ҵ�λ��i-1���ڵ�
	{
		p=p->next;
		j++;
	}
	if(!p||j>i-1)  //if i-1���ڱ���while�е�j<i-1 ��Ϊ1,����i������ֵΪ����������0��Ҳ�ǷǷ���
	{
		printf("�����λ���ǷǷ��� \r\n");
		return ERROR;
	}

	s =(LinkList)malloc(sizeof(LNode));  //����ڵ����Ҫ�����ڴ棬�����޷�����
	s->data = e;
	s->next =p->next;
	p->next = s;
	return OK;
}

//�㷨2.10
//��L��ɾ����i��Ԫ�ز���e������ֵ
Status ListDel_L(LinkList *L,int i,ElemT *e)
{//�ڴ�ͷ���ĵ�����L��ɾ����i��Ԫ�ز���e������ֵ
	LinkList p,q;
	int j=1;
	p=(*L)->next;   //ע����ʼλ�ã��ӵ�һ��Ԫ�ؿ�ʼ
	while(p&&j<i-1)      //�ҵ���i���ڵ��ǰ������Pָ����
	{
		p=p->next;
		j++;
	}
	if(!p||j>i-1)
	{
		printf("�����λ���ǷǷ��� \r\n");
		return ERROR;
	}
	q=p->next;            //q���ǵ�i���ڵ�ĵ�ַ
	p->next = q->next;    //��i+1��i-1������
	*e = q->data;         
	free(q);			//����q���Ƕ�����ˣ�ɾ��,�ͷ��ڴ�
	return OK;
}

//�㷨2.11
//����һ��
void CreatList_L(LinkList *L,int n)
{//��������n��Ԫ��ֵ������ͷ���ĵ�����L������ͷ�巨
	int i;
	LinkList p;
	(*L)=(LinkList)malloc(sizeof (LNode));
	if(!L)
	{
		printf("�ڴ����ʧ�� \r\n");
		exit(OVERFLOW);  //fail to allot
	}
	(*L)->next = NULL ;  //����ͷ��㣬�����ڴ�

	printf("������%d������,�ûس��ָ�\r\n",n);
	for(i=n;i>0;i--)
	{
		p = (LinkList)malloc(sizeof(LNode));
		if(!p)
		{
			printf("�ڴ����ʧ�� \r\n");
			exit(OVERFLOW);  //fail to allot
		}
		scanf_s("%d",&(p->data));
		p->next = (*L)->next;
		(*L)->next =p;
	}
	printf("\r\n");
}  //CreatList_L

//����β�巨����һ��������
void CreatLinkList_Tail(LinkList *L,int n)
{
//˳������n��Ԫ��ֵ������ͷ���ĵ�����L������β�巨
	int i;
	LinkList p,q;
	(*L)=(LinkList)malloc(sizeof (LNode));
	if(!L)
	{
		printf("�ڴ����ʧ�� \r\n");
		exit(OVERFLOW);  //fail to allot
	}
	(*L)->next = NULL ;  //����ͷ��㣬�����ڴ�
	p=(*L);        //��ȡͷ���ĵ�ַ

	printf("������%d������,�ûس��ָ�\r\n",n);
	for(i=n;i>0;i--)
	{
		q=(LinkList)malloc(sizeof(LNode));
		if(!q)
		{
			printf("�ڴ����ʧ�� \r\n");
			exit(OVERFLOW);  //fail to allot
		}	
		scanf_s("%d",&(q->data));
		p->next =q;                   //�Ƚ�ͷ�������
		p=p->next;
	}
	q->next = NULL;    //�޸�βָ���ֵ

	printf("\r\n");
}




//���������������ֵ
Status LinkListTraverse(LinkList L,void(*vi)(ElemT))
{//���������ͷ���ĵ�����ֵ
	LinkList p;
	int j=1;
	p=L->next;
	if(!p)
	{
		printf("empty LinkList");
		return ERROR;
	}
	while(p)
	{
		vi(p->data);		
		p=p->next;

	}
	printf("\r\n");
	return OK;
}

#endif


