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
SqStack *S;
int i,a,b;
S=(SqStack*)malloc(sizeof(SqStack));
CreateStack_sq(S);
if(StackEmpty_sq(S))
printf("��ջΪ��!\n"); 
for(i=0;i<=9;i++)
    Push_sq(S,i);
    StackTraverse_sq(S);
    putchar('\n');
Pop_sq(S,&a);
Pop_sq(S,&b);
Push_sq(S,a+b);   
StackTraverse_sq(S);
putchar('\n');
printf("��ջ����ջ�����δ�ӡ����\n");
for(i=S->top;i>=0;i--)
printf("%d",S->elem[i]);  


//CreateStack_sq(S);
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
	else 
	{
	//printf("��ջ�ǿ�\n"); 
	return false;
	} 
} 
bool StackTraverse_sq(SqStack *S)
{
	int i;
	if(StackEmpty_sq(S)) return false;
	printf("ջ������������£�\n");
	for(i=0;i<=S->top;i++)
	printf("%d",S->elem[i]);
	return true;
} 



