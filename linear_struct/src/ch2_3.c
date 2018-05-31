/**
** 章节 2.3 中的所有算法实现
** 
**
**
**********************************/


#include "basicList2.h"
#include "basicList3.h"


//算法2.12 
//归并La与Lb
void MergeList_L(LinkList *La,LinkList *Lb,LinkList *Lc)
{
/**
**  已知单链表La和Lb的元素按非递减排列
**  归并La和Lb得到新的单链表Lc ，Lc的元素也按值非递减排列。
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
		pc -> next = pa?pa:pb;     //把不等于0的表链接过去，就是插入剩余段
	}

	free(*Lb);       //为什么要释放b的头结点？？？？

}


//算法2.17
//在静态表空间中实现集合运算（A-B）+(B-A)
void differnce(SLinkList space,int *S)
{//依次输入集合A和B的元素，在一维数组中建立表示（A-B）+(B-A)的静态表
	//S为其头指针，设备用空间足够大；
	int m,n,ina,inb;
	int i,j;   //老i和老j，循环的干活少不了它！
	int r,p,k;
	InitSpace_SL(space);
	*S = Malloc_SL(space);
	r=*S;

	m=7;n=6; //输入就省掉了，调试起来太麻烦了
	for(j = 1 ;j <= m;++j)     //建立集合A的链表
	{
		i = Malloc_SL(space);  //  分配节点
		ina = j*2;
		space[i].data = ina;   
		space[r].cur = i;		//尾插法
		r = i;
	}
	space[r].cur = NULL;   //创建儿子表A的尾节点，

	for(j = 1;j <= n;j++)   //依次输入B的元素，如若元素不再当前表中，就插入，否则就删除
	{
		inb = j;
		p=*S;             //获取总的表头位置 
		k = space[p].cur;//获取表A的第一个节点
		while(k!=space[r].cur && (space[k].data!= inb))
		{
			p=k;
			k=space[k].cur;
		}//while

		if(k == space[r].cur)   //不存在该元素，则插入
		{
			i = Malloc_SL(space);
			space[i].data =  inb;
			space[i].cur = space[r].cur;   //这里使用的是头插法，每一个新插入的元素都插入在位置R之后，而不是插入表尾
			space[r].cur = i;
		}
		else                    //表中有这个元素，删除它以，它是AB的公共元素
		{
			space[p].cur = space[k].cur;
			Free_SL(space,k);
			if(r==k)r=p;         //如果删除的是尾节点，要修改尾指针
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
	printf("单链表1的值：  ");
	LinkListTraverse(Li1,view);
	printf("单链表2的值：  ");
	LinkListTraverse(Li2,view);

	MergeList_L(&Li1,&Li2,&Li3);
	printf("归并后表3的值：  ");
	LinkListTraverse(Li3,view);


////静态表



	differnce(Smu,&son);

	ListTraverse_SL(Smu,son,view);

//双向表
	getchar();
}
