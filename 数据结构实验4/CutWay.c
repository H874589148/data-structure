/****************************************************

Name:              CutWay.c 
Auther:            Hawkeye
Date:           2018.10.22
Function:   

使用递归算法编写函数完成整数划分问题:
将正整数 n 表示成一系列正整数之和： n =n1+n2+…+nk，其中 n1≥n2≥…≥nk≥1， k≥1

正整数 n 的这种表示称为正整数 n 的划分，求正整数 n 的不同划分个数。

例如正整数 6 有如下 11 种不同的划分：
6; 5+1; 4+2; 4+1+1; 3+3; 3+2+1; 3+1+1+1; 2+2+2; 2+2+1+1; 2+1+1+1+1; 1+1+1+1+1+1

****************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int stack[100];
int top;
int total,n,t=1;

int cut(int index){
	int i;
	if(total==n)
	{
		printf("\n%d=",n);
		t++;
		for(i=top-1;i>0;i--)
		{
			printf("%d+",stack[i]);
		}
		printf("%d",stack[0]);
	}
	if(total>n)
		return 0;
	for(i=n-1;i>=index;i--)
	{
		total+=i;
		stack[top++]=i;
		cut(i);
		total-=i;
		stack[--top];
	}
}

void main(){
	printf("Please input the number you want to cut:\n");
	while(scanf("%d",&n)!=EOF)
	{
		top=0;
		total=0;
		cut(1);
		printf("\n%d=%d\nThe number '%d' have %d cut way!\n\nPlease input the number you want to cut:\n",n,n,n,t);
		t=1;
	}
}
