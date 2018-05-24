/*8
******
  
   �ڶ��µ�1��2������
   ������
   �㷨2.1 �㷨2.2 �㷨2.7
   ��Ҫ�õ���ͷ�ļ� ��˳���Ļ������������ļ�
 
***
**
**
*****/

#include "basicList1.h"


//�㷨2.1 
//union Ϊ�������������޷���Ϊ������
void unite(SqList *La,SqList Lb)
{//���ܣ���������Lb�е��ǲ���La�е�Ԫ�ز��뵽La��
	int LaLen,LbLen,i;
	ElemT e;
	LaLen = ListLength(*La); LbLen = ListLength(Lb);   //��ȡ a b���Ա�ĳ���

	for(i = 1;i<=LbLen;i++)
	{
		GetElem(Lb,i,&e);

		if(!LocateElem_Sq(*La,e,equal))ListInsert_Sq(La,++LaLen,e);
	}



}


//�㷨2.2 
//��֪���Ա�La��Lb�е�Ԫ�ذ�ֵ�ǵݼ�����
//�ϲ�La��Lb�õ��µ����Ա�Lc��Lc������Ԫ��Ҳ��ֵ�ǵݼ�����
void MergeList(SqList La,SqList Lb,SqList *Lc)
{
	int LaLen,LbLen,i=1,j=1,k=0;
	ElemT ai,bj;

	InitList_Sq(Lc);
	LaLen = ListLength(La); LbLen = ListLength(Lb);   //��ȡ a b���Ա�ĳ���
	while((i <= LaLen)&&(j <= LbLen))                 //�����Ա�a b �е�Ԫ�طֱ�ǵݼ�����Lc
	{
		GetElem(La,i,&ai);
		GetElem(Lb,j,&bj);
		if(ai<=bj){ListInsert_Sq(Lc,++k,ai);++i;}
		else{ListInsert_Sq(Lc,++k,bj);++j;}
	}
	while(i<=LaLen)                                //���Ƚ����ʣ��Ԫ�ؼ�������Lc
	{
		GetElem(La,i++,&ai);
		ListInsert_Sq(Lc,++k,ai);
	}
	while(j<=LbLen)
	{
		GetElem(Lb,j++,&bj);
		ListInsert_Sq(Lc,++k,bj);

	}




}

//�㷨2.2 
//��֪���Ա�La��Lb�е�Ԫ�ذ�ֵ�ǵݼ�����
//�ϲ�La��Lb�õ��µ����Ա�Lc��Lc������Ԫ��Ҳ��ֵ�ǵݼ�����
//ʹ�ø����׵��㷨��ɺϲ�˳���Ĳ���
void MergeList_easy(SqList La,SqList Lb,SqList *Lc)
{
	int LaLen,LbLen,i=1,j=1,k=0;
	ElemT *pa,*pb,*pc;
	ElemT *pa_last,*pb_last;
	InitList_Sq(Lc);
	pa = La.elem;
	pb = Lb.elem;
	pc = Lc->elem;

	pa_last = La.elem + La.length - 1;
	pb_last = Lb.elem + Lb.length - 1;

	while(pa<=pa_last && pb<=pb_last)
	{
		if(*pa<=*pb)*pc++=*pa++;
		else *pc++=*pb++;

		while(pa<=pa_last)*pc++ = *pa++;
		while(pb<=pb_last)*pc++ = *pb++;
	}

}

void print(ElemT *c)
{
   printf("%d ",*c);
}


int main(void)
{
	SqList L1,L2,L3,L4,L5,L6;
	int i;

	InitList_Sq(&L1);
	InitList_Sq(&L2);
	InitList_Sq(&L3);
	InitList_Sq(&L4);

	for(i=1;i<20;i++)
		ListInsert_Sq(&L1,i,i*2);
	for(i=1;i<10;i++)
		ListInsert_Sq(&L2,i,i+30);

	printf("L1��Ԫ�أ�");
	ListTraverse(L1,print);
	printf("\r\n");
	printf("L2��Ԫ�أ�");
	ListTraverse(L2,print);


	unite(&L1,L2);
	printf("�����ɺ��L1��");
	ListTraverse(L1,print);


	for(i=1;i<10;i++)
		ListInsert_Sq(&L3,i,i*2);
	for(i=1;i<10;i++)
		ListInsert_Sq(&L4,i,i+5);

	printf("L3��Ԫ�أ�");
	ListTraverse(L3,print);
	printf("L4��Ԫ�أ�");
	ListTraverse(L4,print);

	MergeList(L3,L4,&L5);

	printf("ƴ�ӳ�����L5��");
	ListTraverse(L5,print);

	MergeList_easy(L3,L4,&L6);
	printf("ƴ�ӳ�����L6��");
	ListTraverse(L5,print);

	getchar();
}