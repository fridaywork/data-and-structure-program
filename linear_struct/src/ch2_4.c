/***************************************************************************
**     多项式加减法和乘法的实现
**
***********************************************************************8*///

#include  "basicList6.h"






int main()
{
	int i;
	polynomial po1,po2;
	term xi;

	InitPolyn(&po1);
	for(i=1;i<9;i++)
	{
		xi.coef = i*1.5;//(rand()%100)/4.0;
		xi.expn = i;
		ListInsert_s(&po1,1,xi);
	}
//	CreatPolyn(&po1,3);
	PrintPolyn(po1);

	InitPolyn(&po2);
	for(i=1;i<5;i++)
	{
		xi.coef = i*(-2);
		xi.expn = 2*i;
		ListInsert_s(&po2,1,xi);
	}
	PrintPolyn(po2);

	AddpolynFix(&po1,&po2);
	printf("相加后得到的多项式：\r\n");
	PrintPolyn(po1);


	scanf("%d",&i);
}