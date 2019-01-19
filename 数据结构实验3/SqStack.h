/***************************************************************************************

Name:              SqStack.h
Auther:            Hawkeye
Date:             2018.10.16
Function:          sq stack ADT

1. 编写函数 CreatStack_sq(), DestoryStack_sq(), Push_sq(), Pop_sq(),StackEmpty_sq() 和StackTraverse_sq(),
   分别完成        创建空栈,            销毁栈,      入栈,     出栈,  判断栈是否为空,  遍历栈底到栈顶依次打印栈内元素
   等功能(不要修改原栈),完成后进行测试。

测试要求:在 main 中,建立栈；判断栈是否为空；将 0~9 入栈；将栈顶两个元素出栈,
两元素求和后再入栈；从栈底到栈顶依次打印元素,再从栈顶到栈底打印元素；销毁栈。

void CreatStack_sq(SqStack &S, int msize = STACK_INIT_SIZE){...}
void DestoryStack_sq(SqStack &S){...}
void Push_sq(SqStack &S, ElementType e){...}
bool Pop_sq(SqStack &S, ElementType &e){...}
bool StackEmpty_sq(SqStack S){...}
bool StackTraverse_sq(SqStack S){...}

*****************************************************************************************/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#define STACK_INIT_SIZE 10

//1.1 顺序栈

typedef int ElementType;

typedef struct stack{
ElementType *elem;
int stacksize;
int top;
}SqStack;

int msize = STACK_INIT_SIZE;

void CreatStack_sq(SqStack S, int msize )               //构造一个容量是 msize 的顺序栈 S 
{
	struct stack *p;
	p=(struct stack*)malloc(STACK_INIT_SIZE*sizeof(struct stack));       //给指针动态分配 msize 长度的数组 
	p->top=-1;                                                           //顺序栈初始为空栈 
	S=*p;
}

void DestoryStack_sq(SqStack S)                                          //销毁顺序栈 S 
{
	struct stack *p;
	p=&S;
	while(p!=NULL){
		free(p);                                                        //释放数组空间
		p++;
	}
	p->top=-1;
	p->stacksize=0;
}

void Push_sq(SqStack S, ElementType e)                                  //入栈 将某个元素插入到栈顶 
{
	if(S.top==S.stacksize-1)
	{
		struct stack *p;
		p=(struct stack*)malloc(STACK_INIT_SIZE*sizeof(struct stack));  //如果栈满则增加空间 
	}
	S.elem[++S.top]=e; 
}

bool Pop_sq(SqStack S, ElementType e)                                   //出栈 将栈顶元素删除 
{
	if(S.top==-1) return false;                                         //若栈空 返回false 
	else {
		e=S.elem[S.top--];
		return true;
	}                                                                   //若顺序栈非空，删除栈顶元素并赋予e,返回true 
}

bool StackEmpty_sq(SqStack S)                                           //判断栈是否为空 
{
	if(S.top==-1) return false;                                         //若栈空 返回false 
	else return true;                                                   //若顺序栈非空，返回true 
}

bool StackTraverse_sq(SqStack S)
{
	if(S.top==-1) return false;                                         //若栈空 返回false 
	else {
		printf("%d",S.elem[S.top--]);                                  //若顺序栈非空，打印栈
		return true;
	}
}

