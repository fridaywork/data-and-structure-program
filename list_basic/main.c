

#include "list_array.h"
#include "list_index.h"
//引用传递形式的验证程序
int swap(int i,int j,int* a,int* b)
{
	int temp;
	temp = i;
	i=j;
	j=temp;

	temp = *a;
	*a=*b;
	*b = temp;

	return 0;
}

//#define arrayac
#define indexac

#ifdef indexac
cellType Link;
#endif

int main(int argc, char *argv[])
{
	int i,ch1 = 10,ch2 = 20,ch3=11,ch4=55;
	int temp;


	printf("before \r\n ch1:%d ch2:%d ch3:%d ch4:%d \r\n",ch1,ch2,ch3,ch4);
	swap(ch1,ch2,&ch3,&ch4);

	printf("after \r\n ch1:%d ch2:%d ch3:%d ch4:%d \r\n",ch1,ch2,ch3,ch4);

#ifdef arrayac  //数组实现函数段
	MakeNull(&L);
	for(i=0;i<20;i++)
	 Insert(i*10,i,&L);
	for(i=0;i<L.length;i++) 
		printf("%d:%d \r\n",i,L.data[i]);    //*/
		
	Insert(30,30,&L);
	Insert(30,500,&L);
	printf("线性表长度：%d  \r\n 查找到的值位置 %d \r\n",End(L),Locate(140,L));
	temp = Retrieve(7,L);
	printf("%d\n\r",temp);

	Delete(2,&L);
	printf("after del");
	for(i=0;i<L.length;i++) 
		printf(" %d:%d \r\n",i,L.data[i]);    //*/

#endif 

#ifdef indexac
	//初始化一个单链表并遍历其值
	InitList(&Link);
    CreatList1(&Link);

	scanLinkList(&Link);


#endif

	printf("cfree is rubish  c free 是个垃圾编译器");



	scanf("%d",&i);
	return 0;
}



