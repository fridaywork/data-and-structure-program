/****
**  ��̬����Ļ�������
**  �����α껯
**
************************************/


#ifndef __BASICLIST_H
#define __BASICLIST_H

#include "systemtype.h"

//��̬���������
#define MAXSIZE 100

typedef struct{

	ElemT data;
	int   cur;

}component,SLinkList[MAXSIZE];

//�㷨2.13
//��̬���Ԫ�ز���
int LocateElem_SL(SLinkList S,ElemT e)
{//�ھ�̬���в��ҵ�1��ֵΪe��Ԫ��
	//���ҵ����򷵻�����L�е�λ�ã����򷵻�0
	int i;
	i = S[0].cur;
	while(i&&S[i].data != e)
		i=S[i].cur;
	return i;
} //locate


//�㷨2.14
//����������ռ������������һ����������space[0].cur ��Ϊͷָ��
// ��0����ʾ��ָ��
void InitSpace_SL(SLinkList space)	      //�������������һ����ַ��ʵ���ϴ������������Ǵ��ݵ�ַ
{
//����������ռ������������һ����������space[0].cur ��Ϊͷָ��
// ��0����ʾ��ָ��
	int i;
	for(i = 0;i<MAXSIZE-1;++i)
		space[i].cur = i+1;        //�α귶ΧΪ1��maxsize �൱���ڴ��ַ

	space[MAXSIZE-1].cur = 0;      //β�ڵ�ָ��NULL

}

//�㷨2.15
//ģ�⶯̬�ڴ���䣬�ڱ��ñ��п��ٿռ���ڵ�
int Malloc_SL(SLinkList space)
{///����������Ϊ�ǿգ��򷵻ط�����ڵ���±꣬���򷵻�0
	int i = space[0].cur;
	if(space[0].cur)
		space[0].cur = space[i].cur;
	return i;
}

//�㷨2.16
//�ͷſ��нڵ�
void Free_SL(SLinkList space ,int k)
{//�ͷ��±�ΪK�Ŀ��нڵ㣬������յ����ñ���
	space[k].cur = space[0].cur;
	space[0].cur = k;

}



//��ĸ�ռ��ڣ�������Ӧ�ľ�̬�������ֵ
Status ListTraverse_SL(SLinkList S,int son,void(*vi)(ElemT))
{
	/*������� ĸ�ռ�  �ӱ�ͷ���  �����������*/
   /* ������������ζ�L��ÿ������Ԫ�ص��ú���vi()��һ��vi()ʧ�ܣ������ʧ�� */
   /*           vi()���βμ�'&'��������ͨ������vi()�ı�Ԫ�ص�ֵ */
	int i;
	i=S[son].cur;
	while(i)        //i = 0 �ж�Ϊ�����
	{
		vi(S[i].data);
		i = S[i].cur;
	}
	printf("\r\n");
	return OK;
}


#endif
