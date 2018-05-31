/****
***
˳����������ʵ�ֺ���
��main��������֤��Щ��������Ч��
�㷨2.3

**
********************/


#ifndef  __BASICLIST1_H
#define  __BASICLIST1_H

#include  "systemtype.h"

//�㷨2.3  ������̬һά����ṹ
#define LIST_INIT_SIZE   50  
#define LISTINCREMENT    10

typedef struct{
	ElemT  *elem;     //�����ַ
	int    length;	//��ǰ����
	int    listsize;   //��ǰ����Ĵ洢����
}SqList;

Status InitList_Sq(SqList *L)
{
	//����һ���յ�˳���L���Զ�̬��ʽ�����ڴ�
	L->elem = (ElemT*)malloc(LIST_INIT_SIZE*sizeof(ElemT));
	if(!L->elem)exit(OVERFLOW);  //fail to allot
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}// InitList_Sq



//�㷨2.4 ˳����в���Ԫ��
Status ListInsert_Sq(SqList *L,int i,ElemT  e)
{
	ElemT *newbase,*q,*p;
	//��˳���L�е�I��λ�ò�����Ԫ��E
	if(i<1 || i>L->length+1) return  ERROR;   //i�Ƿ�Ϸ�
	if(L->length >= L->listsize){            //��ǰ�ռ����������ӷ���  
		newbase = (ElemT*)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemT));
		if(!newbase)exit(OVERFLOW);
		L->elem = newbase;     //�»�ַ����
		L->listsize += LISTINCREMENT;
	}

	q= &(L->elem[i-1]);
	for(p =&(L->elem[L->length-1]);p>=q;--p)
		*(p+1)=*p;       //����ǰ�Ⱥ������е�Ԫ��
	*q = e;
	++L->length;
	return OK;
}//ListInsert_Sq


//�㷨2.5 ɾ��˳����е�Ԫ��
Status ListDelete_Sq(SqList *L,int i,ElemT  *e)
{
	ElemT *p,*q;
	//˳�����ɾ����i��Ԫ�أ�����e������ֵ
	if(i<1 || i>L->length)return ERROR;
	p = &L->elem[i-1];   //��ȡԪ�ص�ַ
	*e=*p;   //��ȡԪ��ֵ
	q=L->elem + L->length -1;  //��ȡ��βԪ�ص�ַ������ǰ��Ԫ��
	for(p=p+1;p<=q;++p)*(p-1)=*p;
	L->length--;
	return OK;

}

//�㷨2.6  ��˳����в��ҵ�һ����E��ͬ��ֵ

Status equal(ElemT a,ElemT b)      
{//�ж�����Ԫ���Ƿ���ȣ��Ƿ���1���񷵻�0��
	Status result;
	a==b?(result = 1):(result = 0);
	return result;
}
 int LocateElem_Sq(SqList L,ElemT e,Status(*compare)(ElemT,ElemT))
 { /* ��ʼ������˳�����Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�����(����Ϊ1,����Ϊ0) */
   /* �������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ�� */
   /*           ������������Ԫ�ز����ڣ��򷵻�ֵΪ0���㷨2.6 */
	 int  i;
	 ElemT *p;
	 i = 1;
	 p = L.elem;
	 while(i<=L.length && !(*compare)(*p,e))
	 {
		 p++;
		 i++;
	 }
	 if(i<= L.length)return i;
	 else return 0;
	 
 }

 //��ȡһ�����Ա�ĳ���
 int ListLength(SqList L)
 {
	 return L.length;
 }

 //��ȡ˳����е�i��Ԫ�ص�ֵ����ָ�뷵����ֵ
 Status GetElem(SqList L,int i,ElemT *e)
 {
	if(i<1 || i>L.length)return ERROR;
	 *e = L.elem[i-1];
	 return OK;
 }

//����˳��������ֵ
Status ListTraverse(SqList L,void(*vi)(ElemT*))
{
	/* ��ʼ������˳�����Ա�L�Ѵ��� */
   /* ������������ζ�L��ÿ������Ԫ�ص��ú���vi()��һ��vi()ʧ�ܣ������ʧ�� */
   /*           vi()���βμ�'&'��������ͨ������vi()�ı�Ԫ�ص�ֵ */
	ElemT *p;
	int i;
	p=L.elem;
	for(i=1;i<=L.length;i++)
	{
		vi(p++);
	}
	printf("\r\n");
	return OK;
}


#endif



