#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define STACK_INIT_SIZE 100
typedef char ElementType;
typedef struct{
	ElementType *elem;
	int stacksize;
	int top;
}SqStack; 
int main(void)
{
void CreateStack_sq(SqStack *S);//构造一个顺序栈
void DestroyStack_sq(SqStack *S);//销毁一个顺序栈 
void Push_sq(SqStack *S,ElementType e);//入栈操作 
bool Pop_sq(SqStack *S,ElementType *e);//出栈操作 
bool StackEmpty_sq(SqStack *S);//判断栈是否为空 
bool StackTraverse_sq(SqStack *S);//遍历栈
SqStack *S;
S=(SqStack*)malloc(sizeof(SqStack));
int i,j;
char a[100];
char b;
CreateStack_sq(S);
printf("请输入要判断的字符串:");
gets(a);
//if((strlen(a))%2==0)

	for(i=0;i<(strlen(a))/2;i++)
	Push_sq(S,a[i]);
if(strlen(a)%2)
i++;
while(a[i]!='\0')
{
	Pop_sq(S,&b);
	if(b!=a[i])
	{
		printf("该字符序列为非回文");
		break; 
		//return false;
	}
	
	i++;
}
if(i==strlen(a))
  printf("该字符序列为回文"); 


return 0;	
}
void CreateStack_sq(SqStack *S)
{
	
	//S=(SqStack*)malloc(sizeof(SqStack));
	int msize=STACK_INIT_SIZE;
	S->elem=(ElementType *)malloc(sizeof(char)*msize);
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
    printf("该栈为空\n");
	return true;
   }
	else return false;
} 
bool StackTraverse_sq(SqStack *S)
{
	int i;
	if(StackEmpty_sq(S)) return false;
	printf("输入的数据如下：\n");
	for(i=0;i<=S->top;i++)
	printf("%d",S->elem[i]);
	return true;
} 
