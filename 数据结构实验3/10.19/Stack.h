/***************************************************************************************

Name:              Stack.h
Auther:            Hawkeye
Date:             2018.10.16
Function:          stack ADT

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

//1.2 链栈

typedef int ElementType;

typedef struct stack{
ElementType data;
struct stack* next;
}*Stack, *LinkStack;

Stack CreatStack_sq(Stack S)                                             //构造一个链栈 S 
{
	S=(Stack)malloc(sizeof(struct stack));
	S=NULL;
	return S;                                                            //链栈初始空栈 
}

void DestoryStack_sq(Stack S)                                            //销毁链栈 S 
{
	struct stack *p,*q;
	p=S;
	q=S;
	while(q){
		q=q->next;                                                        //指针后移 
		free(p);
	}
}

Stack Push_sq(Stack S, ElementType e)                                  //入栈 将某个元素插入到栈顶 
{
	struct stack *p;
	p=(Stack)malloc(sizeof(struct stack));
	p->data=e;
	p->next=S;
	S=p;
	return S;
}

Stack Pop_sq(Stack S, ElementType &e)                                   //出栈 将栈顶元素删除 
{
	//if(S==NULL) return false;                                         //若栈空 返回false 
	//else {
		e=S->data;
		S=S->next;
		return S;
	//}                                                                //若顺序栈非空，删除栈顶元素并赋予e,返回true 
}

bool StackEmpty_sq(Stack S)                                           //判断栈是否为空 
{
	if(S==NULL) return false;                                         //若栈空 返回false 
	else return true;                                                 //若顺序栈非空，返回true 
}

bool StackTraverse_sq(Stack &S)
{
	if(S==NULL) return false;                                         //若栈空 返回false 
	//else {
		while(S!=NULL){
			printf("%d",S->data);                                     //若顺序栈非空，打印栈
			S=S->next;
		}
		return true;
	//}
}
