/****************************************************

Name:            Homework3.cpp 
Auther:            Hawkeye
Date:           2018.10.16
Function:    Data struct third computer homework

3.��д���� void Knapsack(int w[],int T,int n),��ɱ���������⡣
��������:
w[6] = {2,8,6,5,1,4};T=11;n=6;

4. (������)������ָ������������ͬ���ַ�����,�硱abba���͡�abdba�����ǻ���,����good������
���ġ����ݵ�����ջ�Ͷ�����ѧ����,��дһ���㷨�ж��������ַ������Ƿ�Ϊ����(ע�⣺
�����������ջ�Ͷ��еķ�ʽ�����ж�)��
��������:
char* ch = ��abccba��;
char* ch = ��abccbd��;

****************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"Stack.h"
#include"queue.h"

int main()
{
	int i,D1,D2;
	int msize = STACK_INIT_SIZE;
	char c;
	char z[10]={"\0"}; 
	Stack S=NULL;
	//��һ�� 
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
	printf("Step1:into stack and print\n");
	c=StackTraverse_sq(S);
	/*printf("\nStep2:out stack two element and add\n");
	S=Pop_sq(S,D1);
	S=Pop_sq(S,D2);
	S=Push_sq(S,D1+D2);
	c=StackTraverse_sq(S);*/
	printf("\n\nFirst end\n\n");
	//DestoryStack_sq(S);
	
	//�ڶ���  
	Queue Q=NULL;     
	//printf("!"); 
	Q=CreateQueue_L(Q);                                                       // �½����� 
	printf("Create an empty queue just now!\n\n");
	for(i=0;i<=9;i++){
		Q=EnQueue_L(Q,i);                                                     //Ԫ����������� 
	}
	bool j=true; 
	while(j){
		j=DeQueue_L(Q,i);
		printf("%d",i);
	}
	/*
	//������
	int w[6] = {2,8,6,5,1,4};
	int T=11;
	int n=6;
	Knapsack(w,T,n);
	*/
	//������
	int l,m,n,flag;
	/*printf("\n\nPlease input the length of your char\n"); 
	scanf("%d",&l);*/
	printf("\nPlease input your char\n");
	fflush(stdin);
	gets(z);
	printf("The char your input is\n");
	puts(z);
	for(i=strlen(z)-1;i>strlen(z)/2;i--){
		S=Push_sq(S,z[i]);
	}
	/*for(i=l/2-1;i>=0;i--){
		Q=EnQueue_L(Q,z[i]);
	}*/
	flag=strlen(z)/2;
	for(i=strlen(z)/2-1;i>=0;i--){
		S=Pop_sq(S,m);
		//printf("m=%d\t",m);
		DeQueue_L(Q,n);
		//printf("n=%d\n",n);
		n=z[i];//printf("\ni=%d\n",i); 
		if(m==n) flag--;
		//printf("%d%d%d\n",m,n,flag);
	}
	if(flag==0) printf("\nYES!");
	else printf("\nNO!");
	system("pause");
	return 0;
}
