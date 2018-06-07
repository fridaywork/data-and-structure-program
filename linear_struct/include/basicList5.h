/****---------------------------------------
***   2.3
***   ��ͷ�������Ա�Ķ�����������
***   
**    
************************************--------******/


#ifndef _BASICLIST5_H
#define _BASICLIST5_H

#include "systemtype.h"



#ifndef  poly

typedef int  ElemType;

#endif



typedef struct LNode_s{
	ElemType		data;
	struct LNode_s	*next;
}LNode_s,*Link_s,*Position_s;

typedef struct{
	Link_s head,tail;     //ͷָ���βָ��
	int  len;          //���Ա��Ԫ�س���
}LinkList_s;


Status InitList_s(LinkList_s *L)
{//1����һ���յ����Ա�L
	Link_s p;
	p = (Link_s)malloc(sizeof(LNode_s)); /* ����ͷ���*/
	if(!(p)) /* �洢����ʧ�� */
	 exit(OVERFLOW);
	(p)->next= NULL; /* ָ����ָ��ͷ��� */

	L->head =p;
	L->tail =p;
	L->len  = NULL;


	return OK;
}

Status MakeNode(Link_s *s,ElemType e)
{//2������pָ��ֵΪe�Ľڵ㣬������OK��������ʧ�ܣ�����ERROR
	Link_s p;
	
	p = (Link_s)malloc(sizeof(LNode_s)); /* ����ͷ���*/
	if(!(p)) /* �洢����ʧ�� */
	 return ERROR;
	(p)->next= NULL; /* ָ����ָ��ͷ��� */

	p->data = e;
	*s=p;
	return OK;
}

void FreeNode(Link_s *p)
{//3�ͷ�p��ָ�Ľڵ�
	free(*p);
	*p = NULL;
}

Status DestroyList(LinkList_s *L)
{//4�������Ա�L��L�����ٴ��ڣ����ͷ�Lռ�õ��ڴ�

}

Status ClearList(LinkList_s  *L)
{//5�����Ա�L����Ϊ�ձ����ͷ�ԭ������Ľڵ�ռ�
}



Status InsFirst(Link_s *h,Link_s s)
{//6��֪hָ�����������ͷ��㣬��s��ָ�Ľڵ�����ڵ�һ���ڵ�֮ǰ
	//�����ͷ���ָ��s���ڵ��ַ���䵫�ǽڵ������ѱ��޸ģ�������ֵ����
	Link_s p;
	p= *h;
	s->next = p->next;
	p->next = s;

	return OK;
}

Status DelFirst(Link_s h,Link_s *q)
{//7��֪hָ�����������ͷ��㣬ɾ�����еĵ�һ���ڵ㲢��q������ڵ�

	Link_s tn;

	if(!(h->next))   //������ǿձ����޷�������ֵ
		return ERROR;

	tn = h->next;
	h->next=h->next->next; //���ӵڶ����ڵ㵽ͷ���

	MakeNode(q,tn->data);   //������ڵ���q����
	FreeNode(&tn);       //�ͷ�����ڵ���ڴ�
	return OK;
	//��ΪҪ���ؽڵ�ĵ�ַ��������ֱ�ӽ��ڵ�ռ�õ��ڴ��ͷ�

}

Status Append(LinkList_s *L,Link_s s)
{//8��ָ��s��ָ��һ���ڵ㣨һ��������ӱ���䱾����������������L�����һ���ڵ�
 //֮�󣬲��ı�����L��βָ��ָ���µ�β�ڵ�
	L->tail->next = s;      //ֱ�ӽ�L��β�ڵ�ָ��s��Ĭ��s�Դ�β�ڵ�
	while(s->next)
	{
		s=s->next;  //����s��β�ڵ�
	}
	L->tail = s;   //����L��β�ڵ�
	
}

Status Remove_s(LinkList_s *L,Link_s *q)
{//9ɾ����������L�е�β�ڵ㲢��q���أ��ı�L��βָ��ָ���µ�β�ڵ�

}

Status InsBefore(LinkList_s *L ,Link_s *p,Link_s s)
{//10��֪pָ����������L�е�һ���ڵ㣬��s��ָ�ڵ������p��ָ�Ľڵ�֮ǰ
	//���޸�ָ��pָ���²���Ľڵ�
}

Status InsAfter(LinkList_s *L,Link_s *p,Link_s s)
{//11��֪pָ����������L�е�һ���ڵ㣬��s��ָ�Ľڵ������P���µĽڵ�֮��
//���޸�pָ��
}

Status SetCurElem(Link_s *p,ElemType e)
{//12��֪pָ����е�һ���ڵ㣬��e����p��ָ�Ľڵ��е�Ԫ������ֵ
	(*p)->data = e;
	return OK;
}

ElemType GetCurElem(Link_s p)
{//13��֪pָ����е�һ���ڵ㣬����p��ָ�Ľڵ��е�����Ԫ�ص�ֵ
	return p->data;
}

Status ListEmpty(LinkList_s L)
{//14��LΪ�ձ�����ture�����򷵻�false
	if(L.head->next)
		return FALSE;
	else 
		return TURE;
}

int ListLength_s(LinkList_s L)
{//15�������Ա�L�е�Ԫ�ظ���
	return L.len;
}


Position_s GetHead(LinkList_s L)
{//16�������Ա�L��ͷ����λ��
	return L.head;
}

Position_s GetLast(LinkList_s L)
{//17�������Ա�L�����һ���ڵ��λ��
	return L.tail;
}

Position_s PriorPos(LinkList_s L ,Link_s p)
{//18 ��֪pָ�����Ա�L�е�һ���ڵ㣬����p��ָ��ֱ��ǰ����λ��
	//����ǰ��������NULL
	Link_s t;
	if(p=L.head)
		return NULL;
	t = L.head;
	while(t->next != p)   //�ҵ�L��p�ڵ��ǰ��
		t=t->next;
	return t;

}

Position_s NextPos(LinkList_s L ,Link_s p)
{//19 ��֪pָ�����Ա�L�е�һ����㣬����pָ��Ľڵ��ֱ�Ӻ��λ��
	//���޺�̣��򷵻�NULL

	Position_s t;
	if(p->next)
	{	
		t = p->next;
		return t;
	}
	else 
		return NULL;

}

Status LocatePos(LinkList_s L,int i,Link_s *p)
{//20 ����ָʾ���Ա��е�i���ڵ��λ�ò�����OK��iֵ���Ϸ�ʱ����ERROR
	int j;
	Link_s temp;
	if(i<0)return ERROR; //i��ЧֵΪ0������i=0��ʱ�򷵻ر�ͷ
	else if(i==0){*p = L.head;return OK;}

	//if(ListEmpty(L)&&i>0)      //���ڿձ�Ԫ�ظ���Ϊ0��ֱ�ӷ��ش���
	//{
	//	printf("������ǿձ�");
	//	return ERROR;
	//}  

	temp = L.head;
	for(j=0;j<=i;j++); //�ӱ�ͷ��ʼ��
	{
		if(temp->next)   //����һֱ����β
			temp=temp->next;
		else //������˱�β
		{
			if(j<i)  //i�����˱�
			{
				printf("iֵ������Χ");
				return ERROR;
			}
		}
	}

	*p = temp;   //�����ҵ�λ�õĵ�ַ
	return OK;
}  

Position_s LocateElem(LinkList_s L,ElemType e,Status (*compare)(ElemType,ElemType))
{//21 �������Ա�L�е�һ����e����compare()�ж���ϵ��Ԫ��λ��
	//��������������Ԫ�أ�����NULL
}

//22 �㷨2.20
//  ����Ԫ��
Status ListInsert_s(LinkList_s *L,int i,ElemType e)
{//�ڴ�ͷ���ĵ�����L�ĵ�i��Ԫ��֮ǰ����Ԫ��e
	Link_s h,s;
	if(!LocatePos(*L,i-1,&h)) return ERROR; //��õ�i���ڵ㣬��ַ����h
	if(!MakeNode(&s,e)) return ERROR;
	InsFirst(&h,s);  //��h��ǰ�����s�����ﲻ�Ͻ�����Ϊ�ǲ����i���ڵ㿪ʼ�������ͷ���ǰ��
	if((*L).len == NULL)  //���L�����Ǹ��ձ�����һ��βָ��
	{
		L->tail = s;   //���ڿձ�����h����β�ڵ�
	}
	(*L).len++;     //����һ
	return OK;
}

int compare(ElemType a,ElemType b)  //�ж�a��b�Ƿ��Ƿǵݼ���ϵ,���򷵻�1�����򷵻�0
{
	int temp;
	temp = (a <= b)?1:0;
	return temp;
}

//���������������ֵ
Status LinkListTraverse_s(LinkList_s L,void(*vi)(ElemType))
{//���������ͷ���ĵ�����ֵ
	Link_s p;
	int j=1;
	p = L.head->next;
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




