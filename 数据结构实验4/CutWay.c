/****************************************************

Name:              CutWay.c 
Auther:            Hawkeye
Date:           2018.10.22
Function:   

ʹ�õݹ��㷨��д�������������������:
�������� n ��ʾ��һϵ��������֮�ͣ� n =n1+n2+��+nk������ n1��n2�ݡ���nk��1�� k��1

������ n �����ֱ�ʾ��Ϊ������ n �Ļ��֣��������� n �Ĳ�ͬ���ָ�����

���������� 6 ������ 11 �ֲ�ͬ�Ļ��֣�
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
