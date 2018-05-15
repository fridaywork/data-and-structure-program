#ifndef  __LIST_ARRAY_H
#define  __LIST_ARRAY_H




#include <stdio.h>

#include "basictype.h"

#define position int



#define maxlength   100

typedef struct {
	
	ElemType data[maxlength];
	int length;
} LIST;

//���Ա������������ 7��
//1
int End(LIST Li);
//2
int MakeNull(LIST *Li);
//3
int Insert(ElemType x, position po ,LIST* Li);
//4
int Locate(int x,LIST Li);
//5
ElemType Retrieve(int po,LIST Li);
//6
int Delete(int po,LIST *Li);


extern LIST L;

//���Ա�������ʾ ��дһЩʵ�����Ա������ʾ�ĺ���
 

#endif

