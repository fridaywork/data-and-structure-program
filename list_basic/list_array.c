

/*   ˳���
//���Ա�������ʾ    ����������װ 
�������ʾ���Ա��˵����
1��ʹ�������ı��Ź��򣬵�һ��Ԫ�ص������±�Ϊ0�����ݳ��ȶ���Ϊmaxlength������������Ŀα���������ͬ��
2�����ʹ��C���ԣ�C���Բ�֧��void Intt(LIST &L)��ʽ�ĺ�������������C++�в�֧�ֵ�������ʽ����C��ʹ��ָ�봫�ݴ��棬���Դﵽͬ����Ч����
*******/
#include "list_array.h" 

LIST L ;   //����һ�����Ա�L 

int Li;

//1  �������Ա������һ��Ԫ�غ���һ�����   1
int End(LIST Li)
{
	return Li.length +1;
}

//2  �����Ա���ղ���ʼ�����Ա�   2
int MakeNull(LIST *Li)
{
	Li->length = 0;  
	return End(*Li);
}

//3  ����Ԫ��   3
int Insert( ElemType x, position po,LIST* Li )
{

	
	if(po >= maxlength)  //�����˴�С����
	{
		printf("error:list is full,out of range \r\n");
		return 0;
	}
	else if ((po > L.length)||(po < 0))
	{
		printf("error:position does not exist \r\n");
		return 0;
	}

	Li->data[po] = x;
	Li->length ++;
	return 1;        //*/
} 

//4  ��x��һ����L�г��ֵ�λ��
int Locate(int x,LIST Li)
{
	int i = 0;
	while(x != Li.data[i])
	{
		if(i<Li.length)
			i++;
		else 
		{
			printf("no value found \r\n");
			return End(Li);
		}
	}
	return i;
}
//5 �������Ա���λ��ΪP��Ԫ��
ElemType Retrieve(int po,LIST Li)
{
	if(po>=End(Li))
	{
		printf("error:position is out of limit");
		return 0;
	}

	return Li.data[po];
}
//6 ɾ��L��λ��ΪP��Ԫ��
int Delete(int po,LIST *Li)
{
	int i;
	if(po>=End(*Li))
	{
		printf("error:position is out of limit");
		return 0;
	}
	
	for(i=po;i<Li->length;i++)
	{
		Li->data[i] = Li->data[i+1];

	}
	Li->length --;
	return 1;
}
//7 ����L�еĵ�һ��λ�ã����L�ǿձ�����End(L)
int First(LIST Li)
{
	if(Li.length != 0)
		return 0;
	else
		return End(L);
}
//
//
//
//
//
//
 
 
 
 
