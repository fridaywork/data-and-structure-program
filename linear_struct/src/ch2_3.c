/**
** �½� 2.3 �е������㷨ʵ��
** 
**
**
**********************************/


#include "basicList2.h"
#include "basicList3.h"


//�㷨2.12 
//�鲢La��Lb
void MergeList_L(LinkList *La,LinkList *Lb,LinkList *Lc)
{
/**
**  ��֪������La��Lb��Ԫ�ذ��ǵݼ�����
**  �鲢La��Lb�õ��µĵ�����Lc ��Lc��Ԫ��Ҳ��ֵ�ǵݼ����С�
**/
	LinkList pa,pb,pc;
	pa = (*La)->next;
	pb = (*Lb)->next;
	*Lc = pc = *La;
	while(pa&&pb)
	{
		if(pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next =pb;
			pc = pb;
			pb = pb->next;
		}
		pc -> next = pa?pa:pb;     //�Ѳ�����0�ı����ӹ�ȥ�����ǲ���ʣ���
	}

	free(*Lb);       //ΪʲôҪ�ͷ�b��ͷ��㣿������

}


//�㷨2.17
//�ھ�̬��ռ���ʵ�ּ������㣨A-B��+(B-A)
void differnce(SLinkList space,int *S)
{//�������뼯��A��B��Ԫ�أ���һά�����н�����ʾ��A-B��+(B-A)�ľ�̬��
	//SΪ��ͷָ�룬�豸�ÿռ��㹻��
	int m,n,ina,inb;
	int i,j;   //��i����j��ѭ���ĸɻ��ٲ�������
	int r,p,k;
	InitSpace_SL(space);
	*S = Malloc_SL(space);
	r=*S;

	m=7;n=6; //�����ʡ���ˣ���������̫�鷳��
	for(j = 1 ;j <= m;++j)     //��������A������
	{
		i = Malloc_SL(space);  //  ����ڵ�
		ina = j*2;
		space[i].data = ina;   
		space[r].cur = i;		//β�巨
		r = i;
	}
	space[r].cur = NULL;   //�������ӱ�A��β�ڵ㣬

	for(j = 1;j <= n;j++)   //��������B��Ԫ�أ�����Ԫ�ز��ٵ�ǰ���У��Ͳ��룬�����ɾ��
	{
		inb = j;
		p=*S;             //��ȡ�ܵı�ͷλ�� 
		k = space[p].cur;//��ȡ��A�ĵ�һ���ڵ�
		while(k!=space[r].cur && (space[k].data!= inb))
		{
			p=k;
			k=space[k].cur;
		}//while

		if(k == space[r].cur)   //�����ڸ�Ԫ�أ������
		{
			i = Malloc_SL(space);
			space[i].data =  inb;
			space[i].cur = space[r].cur;   //����ʹ�õ���ͷ�巨��ÿһ���²����Ԫ�ض�������λ��R֮�󣬶����ǲ����β
			space[r].cur = i;
		}
		else                    //���������Ԫ�أ�ɾ�����ԣ�����AB�Ĺ���Ԫ��
		{
			space[p].cur = space[k].cur;
			Free_SL(space,k);
			if(r==k)r=p;         //���ɾ������β�ڵ㣬Ҫ�޸�βָ��
		}
	}
}

void view(ElemT e)
{
   printf("%d ",e);
}

	SLinkList Smu;

int main()
{
	LinkList Li1,Li2,Li3;
	int i;

	int son;



	InitList_CL(&Li1);
	InitList_CL(&Li2);
	for(i=1;i<15;i++)
	{
		ListInsert_L(&Li1,i,i);
	}
	for(i=1;i<10;i++)
	{
		ListInsert_L(&Li2,i,i*2);
	}
	printf("������1��ֵ��  ");
	LinkListTraverse(Li1,view);
	printf("������2��ֵ��  ");
	LinkListTraverse(Li2,view);

	MergeList_L(&Li1,&Li2,&Li3);
	printf("�鲢���3��ֵ��  ");
	LinkListTraverse(Li3,view);


////��̬��



	differnce(Smu,&son);

	ListTraverse_SL(Smu,son,view);

//˫���
	getchar();
}
