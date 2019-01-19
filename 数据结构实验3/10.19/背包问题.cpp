#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define STACK_INIT_SIZE 100
typedef int ElementType;
typedef struct{
	ElementType *elem;
	int stacksize;
	int top;
}SqStack; 
int main(void)
{
void CreateStack_sq(SqStack *S);//����һ��˳��ջ
void DestroyStack_sq(SqStack *S);//����һ��˳��ջ 
void Push_sq(SqStack *S,ElementType e);//��ջ���� 
bool Pop_sq(SqStack *S,ElementType *e);//��ջ���� 
bool StackEmpty_sq(SqStack *S);//�ж�ջ�Ƿ�Ϊ�� 
bool StackTraverse_sq(SqStack *S);//����ջ
void knapsack(int w[],int T,int n); 
int w[6]={2,8,6,5,1,4};
knapsack(w,11,6);
return 0;	
}
void CreateStack_sq(SqStack *S)
{
	
	//S=(SqStack*)malloc(sizeof(SqStack));
	int msize=STACK_INIT_SIZE;
	S->elem=(ElementType *)malloc(sizeof(int)*msize);
	//S->elem=new int[msize];
	S->stacksize=msize;
	S->top=-1;
	//return S;
}
void DestroyStack_sq(SqStack *S)
{
	free(S->elem);
	S->top=-1;
	S->stacksize=0;
}
void Push_sq(SqStack *S,ElementType e)
{
   S->elem[++S->top]=e;	
}
bool Pop_sq(SqStack *S,ElementType *e)
{
	if(S->top==-1) return false;
	*e=S->elem[S->top--];
	return true;
}
bool StackEmpty_sq(SqStack *S)
{
	if(S->top==-1) {
    //printf("��ջΪ��\n");
	return true;
   }
	else return false;
} 
bool StackTraverse_sq(SqStack *S)
{
	int i;
	if(StackEmpty_sq(S)) return false;
	printf("�����������±�������£�\n");
	for(i=0;i<=S->top;i++)
	printf("%d\n",S->elem[i]);
	return true;
} 
void knapsack(int w[],int T,int n)
{
	int k=0;
	SqStack *S;
	S=(SqStack*)malloc(sizeof(SqStack));
	CreateStack_sq(S);
	do{
		while(T>0&&k<n)
		{
			if(T-w[k]>=0)
			{
				Push_sq(S,k);
				T-=w[k];
			}
			k++;
		}
		if(T==0)
		StackTraverse_sq(S);
		if(!StackEmpty_sq(S))
		{
		  Pop_sq(S,&k);
		  T+=w[k];
		  k++;	
		} 
   	  }while(!StackEmpty_sq(S)||k!=n);
   	  DestroyStack_sq(S);
}


