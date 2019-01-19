/****************************************************

Name:            Homework3.c
Auther:            Hawkeye
Date:           2018.10.16
Function:    Data struct third computer homework

3.编写函数 void Knapsack(int w[],int T,int n),完成背包求解问题。
测试数据:
w[6] = {2,8,6,5,1,4};T=11;n=6;

4. (附加题)回文是指正读反读均相同的字符序列,如”abba”和”abdba”均是回文,但”good”不是
回文。根据第四章栈和队列所学内容,试写一个算法判定给定的字符向量是否为回文(注意：
这里必须利用栈和队列的方式进行判定)。
测试数据:
char* ch = “abccba”;
char* ch = “abccbd”;

****************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"Stack.h"
#include"queue.h"
#include"backpack_answer.h"

int main()
{
	int i;
	int msize = STACK_INIT_SIZE;
	char c;
	char z[10]={"\0"}; 
	Stack S=NULL;
	//第一题 
	S=CreatStack_sq(S);
	c=StackEmpty_sq(S);
	switch(c){
		case true:printf("The stack create just now is empty!\n");break;
		case false:printf("The stack create just now is not empty!\n");break;
	} 
	for(i=0;i<=9;i++){
		//printf("%d",i);
		S=Push_sq(S,i);
		//printf("%d",i);
	}
	c=StackTraverse_sq(S);
	printf("\n\nFirst end\n\n");
	//DestoryStack_sq(S);
	
	//第二题  
	Queue Q=NULL;     
	//printf("!"); 
	Q=CreateQueue_L(Q);                                                       // 新建队列 
	printf("Create an empty queue just now!\n\n");
	for(i=0;i<=9;i++){
		Q=EnQueue_L(Q,i);                                                     //元素依次入队列 
	}
	bool j=true; 
	do{
		j=DeQueue_L(Q,i);
		printf("%d\n",i);
	}while(j);
	//第三题
	int w[6] = {2,8,6,5,1,4};
	int T=11;
	int n=6;
	Knapsack(w,T,n);
	
	//第四题
	int l,m,flag;
	printf("Please input the length of your char"); 
	scanf("%d",&l);
	printf("Please input your char\n");
	fflush(stdin);
	gets(z);
	printf("The char your input is\n");
	puts(z);
	for(i=l-1;i>l/2;i--){
		S=Push_sq(S,z[i]);
	}
	flag=l/2;
	for(i=l/2-1;i>=0;i--){
		Pop_sq(S,m);
		printf("m=%d\t",m);
		if(m==z[i]) flag--;
		printf("%d",flag);
	}
	if(flag==0) printf("\nYES!");
	else printf("\nNO!");
	system("pause");
	return 0;
}
