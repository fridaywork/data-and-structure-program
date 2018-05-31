/**
**    ˫���Ķ������������
***
**
**
***********************************888*/




#ifndef  __BASICLIST4_H
#define  __BASICLIST4_H

#include "systemtype.h"


//  --------   ���Ա��˫������洢�ṹ   --------------------------
//����Ԫ�ء�ǰ��ָ�룬����ָ��
typedef struct DuLNode{
	ElemT data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode, *DuLinkList;

//��ʼ��һ��˫��ѭ������βָ��ָ��ͷ���
 Status InitList_DuL(DuLinkList *L)
 { /* �������������һ�����ڵ�Ŀյ����Ա�L */
   *L=(DuLinkList)malloc(sizeof(DuLNode)); /* ����ͷ���*/
   if(!*L) /* �洢����ʧ�� */
     exit(OVERFLOW);
   (*L)->next= (*L); /* ָ����ָ��ͷ��� */
   (*L)->prior = (*L)->next;      //ͷ����ǰ��ָ��ĩ���

   //�涨��ѭ�����ĩָ��ָ��ͷ���
   return OK;
 }

//DuLinkList GetElemP_DuL(DuLinkList L,int i) /* ��� */
//{ /* ��˫������L�з��ص�i��Ԫ�ص�λ��ָ��(�㷨2.18��2.19Ҫ���õĺ���) */
//	int j;      //���ﲢû�ж�i��ֵ���Ƿ��жϴ���
//	DuLinkList p=L;
//	for(j=1;j<=i;j++)
//	    p=p->next;
//	return p;
//}

 DuLinkList  GetElemP_DuL(DuLinkList L,int i)
 {//���˫������L���Ƿ����λ��i
	 //������ڣ��������λ�õĵ�ַ����������ڣ�����ERROR��
	 //������LΪ�ǿձ�  i�ĺϷ�ֵΪ 1-��
	 int j;
	 DuLinkList p,n;
	 p = L;
	 n = L->next;

	 if(i==1)  //i = 1 ��ʱ�򣬷���ͷָ���next
	 {
		 return  n;
	 }
	 else 
	 {
		 if(p==n)  //�ձ�Ҳ����ͷָ���next
		 {
			 return  n;
		 }
		 else  //�ǿձ� �� i ������0
		 {
			 j = 1;
			 while(p!=n && j<i)
			 {
				 n = n->next;   //nָ�����
				 j++;
			 }

			 if(p==n && j<i) //����ҵ��˱�β����û���ҵ�i
				 return ERROR;
			 else return n;
		 }
	 }
 }

 //�㷨2.19 
 //˫���� ��Ԫ�ز���
 Status ListInsert_DuL(DuLinkList *L,int i,ElemT e)
 {
	 //�ڴ�ͷ����˫ѭ������L�е�i��Ԫ��֮ǰ����Ԫ��e
	 //i �ĺϷ�ֵΪ1<=i<=��+1
	 DuLinkList s,p;
	 if(!(p = GetElemP_DuL(*L,i)))return ERROR;    //����i�ĺϷ��ԣ�������Ϸ���������λ�õĵ�ַ
	 if(!(s = (DuLinkList)malloc(sizeof(DuLNode))))return ERROR;
	 s->data = e;
	 s->prior = p->prior;   //һ��Ҫ�޸��ĸ�ָ��
	 p->prior->next = s;
	 s->next = p;
	 p->prior = s;

	 return OK;
 }

 //�㷨2.19 
 //ɾ����ͷ����˫����ĵ�i��Ԫ��
Status ListDelete_DuL(DuLinkList *L,int i,ElemT *e)
{
	//ɾ����ͷ����˫��ѭ����ĵ�i��Ԫ�أ��Ϸ�ֵΪ1<=i<=��
	DuLinkList p;
	if(i==1)
		{ if(!(p = GetElemP_DuL(*L,i)))return ERROR;}
	else
		if(!(p = GetElemP_DuL(*L,i)))return ERROR;
	*e=p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return OK;
}

 //����˫��������ֵ
Status LinkListTraverse_DuL(DuLinkList L,void(*vi)(ElemT))
{//���������ͷ���ĵ�����ֵ
	DuLinkList p,n;
	int j=1;
	p=L->next;
	n=L;
	if(n==p)
	{
		printf("empty LinkList");
		return ERROR;
	}
	while(n!=p)
	{
		vi(p->data);		
		p=p->next;

	}
	printf("\r\n");
	return OK;
}

#endif


