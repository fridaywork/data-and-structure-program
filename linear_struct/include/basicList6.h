/***********8
**
*	����������Polynomial��ʵ��
*   ����ʽ�Ӽ���
*   ����ʽ�˷�����
*
***
****************************/

#ifndef   _BASICLIST6_H
#define   _BASICLIST6_H



#define poly   //����elemtype�ı��뿪��

#include "basicList5.h"
#include "systemtype.h"



//typedef struct{
//	float coef; //ϵ��
//	int   expn; //ָ��
//}term,ElemType;


typedef LinkList_s polynomial;


int cmp(term a,term b)
{//8 ����a��ָ��ֵ ���� ���� С��   b ���� 1��0��-1
	if(a.expn >b.expn)
		return 1;
	else if (a.expn==b.expn)
		return 0;
	else return -1;
}


Status same(term a,term b)
{
	int re;
	re = (a.expn == b.expn)?1:0;   //��ȷ���1������ȷ���0
	return re;
}

Status InitPolyn(polynomial *polyn)
{
	if(InitList_s(polyn))return OK;
}

//��������
void CreatPolyn(polynomial *polyn,int m)
{//1 ����m���ϵ����ָ����������ʾһԪ����ʽ�������poly
	int i;
	Link_s h,s;
	term e;
	InitList_s(polyn);
	h = GetHead(*polyn);  //��ȡͷ���ĵ�ַ
	e.coef = 0.0;
	e.expn = -1;
	SetCurElem(&h,e);
	for(i=1;i<=m;i++)   //��������n���������һ����ȷ��ÿ�������ָ����ͬ������Ϊ�Ƿ�
	{
		printf("�밴�� ϵ�� ָ�� �ĸ�ʽ��������%d��һԪ��\r\n",m);
		scanf("%f,%d",&e.coef,&e.expn);
		if(!LocateElem(*polyn,e,same))//�������в����ڸ�ָ������ʱ
		{
			if(MakeNode(&s,e)) InsFirst(&h,s); //���ɽڵ㲢��������
		}
	}


}

void DestroyPolyn(polynomial *p)
{//2���ٶ�һԪ��ʽp
	p->head->next = NULL;  //��p��Ϊ�ձ��ⲻ�迼���ڴ��ͷŵ�����
}

void PrintPolyn(polynomial p)
{//3 ��ӡһԪ����ʽp
	Link_s first;
	first = p.head->next;
	if(!first)
	{
		printf("the polynomial is empty");
	}
	
	while(first)
	{
		if(first->data.coef > 0 )
		{
			printf("+%0.2fX^%d ",first->data.coef,first->data.expn);
		}
		else if (first->data.coef == 0);
		else
		{
			printf("%0.2fX^%d ",first->data.coef,first->data.expn);

		}
		first = first->next;
	}
	printf("\r\n");
	
}

void PolynLength(polynomial p)
{//4 ����һԪ����ʽp�е�����
}

//�㷨2.23
void Addpolyn(polynomial *pa,polynomial *pb)
{//5 ��ɶ���Կα����㷨ֻ��������pb��pa��Ԫ�ذ��ս�������������������µĶ���ʽ��ӣ����粻����ˣ�pb�е���ֻ�ᴦ���һ��ĺϲ�
	Link_s ha,hb,qa,qb;
	term a,b,sum;

	ha = GetHead(*pa);
	hb = GetHead(*pb);   ///��ȡ����ʽa�Ͷ���ʽb��ͷ���
	qa = NextPos(*pa,ha); 
	qb = NextPos(*pb,hb); //��ȡ��һ���ڵ�
	while(qa&&qb)      //qa��qb������null
	{
		a = GetCurElem(qa);
		b = GetCurElem(qb);
		switch(cmp(a,b))
		{
			case -1: //����ʽPA�е�ǰ�ڵ��ָ��ֵС
				ha = qa;
				qa = qa->next;
				break;
			case 0: //pa��pb�ĵ�ǰ��ָ�����
				sum = a;
				sum.coef = a.coef + b.coef ;
				if(sum.coef != 0.0)   //û�е���������ӵĽ������pa
				{
					SetCurElem(&qa,sum);
					ha = qa;
				}
				else  //�������ˣ�ɾ��pa�еĵ�ǰ�ڵ�
				{
					DelFirst(ha,&qa);
					FreeNode(&qa);
				}
				DelFirst(hb,&qb);
				FreeNode(&qb);
				qb = NextPos(*pb,hb);
				qa = NextPos(*pa,ha);
				break;
			case 1:     //pb�ĵ�ǰ�ڵ�ָ��ֵС
				DelFirst(hb,&qb);
				InsFirst(&ha,qb);
				FreeNode(&qb);
				ha = NextPos(*pa,ha);
				break;
		} //switch
					
	}//while 
	if(!ListEmpty(*pb))Append(pa,qb);  //����Pb�е�ʣ��ڵ�
	FreeNode(&hb);
}

//�㷨2.23�Ľ�
void AddpolynFix(polynomial *pa,polynomial *pb)
{//5 ��ɶ���ʽ��������� �� Pa = Pa+Pb ������Pb
//�������̵ĳ�������Ż������������������ʽa �� b�ϲ�
//���������Ĭ�϶���ʽ��������߽���������
//������Ҫ�Ƚ�pa��pb�е�ÿһ��
	Link_s ha,hb,qa,qb;
	term a,b,sum;

	ha = GetHead(*pa);
	hb = GetHead(*pb);   ///��ȡ����ʽa�Ͷ���ʽb��ͷ���
	qa = NextPos(*pa,ha); 
	qb = NextPos(*pb,hb); //��ȡ��һ���ڵ�
	a = GetCurElem(qa);
	while(qb)      //��Ҫ�Ա����ʽb��������
	{
		
		b = GetCurElem(qb);
		//��pb�е�Ԫ����pa��Ԫ������Ƚ�
		while(qa&&(!same(a,b)))
		{
			qa = qa->next;
			if(qa)
				a = GetCurElem(qa);
		}//while	

		if(same(a,b))
		{
				 //pa��pb�ĵ�ǰ��ָ�����
				sum = a;
				sum.coef = a.coef + b.coef ;
				if(sum.coef != 0.0)   //û�е���������ӵĽ������pa
				{
					SetCurElem(&qa,sum);
				}
				else  //�������ˣ�ɾ��pa�еĵ�ǰ�ڵ�
				{
					DelFirst(ha,&qa);
					FreeNode(&qa);
				}
				DelFirst(hb,&qb);     //ͬʱɾ��b�еĶ�Ӧ�ڵ�
				FreeNode(&qb);				
		} 
		else      //��ǰ���ָ������ȣ�ֱ�ӽ�qb����pa
		{
			DelFirst(hb,&qb);
			InsFirst(&ha,qb);
		//	ha = NextPos(*pa,ha); //Ĭ�ϲ���Ľڵ����²���Ľڵ�֮��
		}

		qb = NextPos(*pb,hb);
		qa = (*pa).head->next;
	}//while 
//	if(!ListEmpty(*pb))Append(pa,qb);  //����Pb�е�ʣ��ڵ�
	FreeNode(&hb);
}

void Subtrctpolyn(polynomial *pa,polynomial *pb)
{//6 ��ɶ���ʽ��������� �� Pa = Pa-Pb��������Pb
	//��������˵�����������ǲ���
	//��P�������ϵ��������෴����Ȼ������ӾͿ�����
}

void MultiplyPolyn(polynomial *pa,polynomial *pb)
{//7 ��ɶ���ʽ��������㣬Pa=Pa*Pb ��������Pb

}



#endif
