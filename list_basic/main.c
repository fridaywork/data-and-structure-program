#include <stdio.h>

#include "list_array.h"
#include "list_index.h"
//���ô�����ʽ����֤����
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

int main(int argc, char *argv[])
{
	int i,ch1 = 10,ch2 = 20,ch3=11,ch4=55;
	int temp;


	printf("before \r\n ch1:%d ch2:%d ch3:%d ch4:%d \r\n",ch1,ch2,ch3,ch4);
	swap(ch1,ch2,&ch3,&ch4);

	printf("after \r\n ch1:%d ch2:%d ch3:%d ch4:%d \r\n",ch1,ch2,ch3,ch4);

#ifdef arrayac  //����ʵ�ֺ�����
	MakeNull(&L);
	for(i=0;i<20;i++)
	 Insert(i*10,i,&L);
	for(i=0;i<L.length;i++) 
		printf("%d:%d \r\n",i,L.data[i]);    //*/
		
	Insert(30,30,&L);
	Insert(30,500,&L);
	printf("���Ա��ȣ�%d  \r\n ���ҵ���ֵλ�� %d \r\n",End(L),Locate(140,L));
	temp = Retrieve(7,L);
	printf("%d\n\r",temp);

	Delete(2,&L);
	printf("after del");
	for(i=0;i<L.length;i++) 
		printf(" %d:%d \r\n",i,L.data[i]);    //*/

#endif 

#ifdef indexac
	//��ʼ��һ��������������ֵ
	L_index->elem = 20;
	L_index->next = 0;   //��һ�����ݽ���ʱ����ͷ���Ǳ�β


#endif

	printf("cfree is rubish  c free �Ǹ�����������");



	getchar();
	return 0;
}



