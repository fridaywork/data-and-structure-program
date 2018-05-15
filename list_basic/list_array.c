

/*   顺序表
//线性表的数组表示    各个函数封装 
对数组表示线性表的说明：
1、使用王道的编排规则，第一个元素的数组下标为0，数据长度定义为maxlength，这与廖明宏的课本中有所不同；
2、编程使用C语言，C语言不支持void Intt(LIST &L)形式的函数声明，这是C++中才支持的引用形式，在C中使用指针传递代替，可以达到同样的效果；
*******/
#include "list_array.h" 

LIST L ;   //定义一个线性表L 

int Li;

//1  返回线性表中最后一个元素后面一个标号   1
int End(LIST Li)
{
	return Li.length +1;
}

//2  将线性表清空并初始化线性表   2
int MakeNull(LIST *Li)
{
	Li->length = 0;  
	return End(*Li);
}

//3  插入元素   3
int Insert( ElemType x, position po,LIST* Li )
{

	
	if(po >= maxlength)  //超出了大小限制
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

//4  求x第一次在L中出现的位置
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
//5 返回线性表中位置为P的元素
ElemType Retrieve(int po,LIST Li)
{
	if(po>=End(Li))
	{
		printf("error:position is out of limit");
		return 0;
	}

	return Li.data[po];
}
//6 删除L中位置为P的元素
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
//7 返回L中的第一个位置，如果L是空表，返回End(L)
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
 
 
 
 
