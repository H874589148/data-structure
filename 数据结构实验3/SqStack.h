/***************************************************************************************

Name:              SqStack.h
Auther:            Hawkeye
Date:             2018.10.16
Function:          sq stack ADT

1. ��д���� CreatStack_sq(), DestoryStack_sq(), Push_sq(), Pop_sq(),StackEmpty_sq() ��StackTraverse_sq(),
   �ֱ����        ������ջ,            ����ջ,      ��ջ,     ��ջ,  �ж�ջ�Ƿ�Ϊ��,  ����ջ�׵�ջ�����δ�ӡջ��Ԫ��
   �ȹ���(��Ҫ�޸�ԭջ),��ɺ���в��ԡ�

����Ҫ��:�� main ��,����ջ���ж�ջ�Ƿ�Ϊ�գ��� 0~9 ��ջ����ջ������Ԫ�س�ջ,
��Ԫ����ͺ�����ջ����ջ�׵�ջ�����δ�ӡԪ��,�ٴ�ջ����ջ�״�ӡԪ�أ�����ջ��

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

//1.1 ˳��ջ

typedef int ElementType;

typedef struct stack{
ElementType *elem;
int stacksize;
int top;
}SqStack;

int msize = STACK_INIT_SIZE;

void CreatStack_sq(SqStack S, int msize )               //����һ�������� msize ��˳��ջ S 
{
	struct stack *p;
	p=(struct stack*)malloc(STACK_INIT_SIZE*sizeof(struct stack));       //��ָ�붯̬���� msize ���ȵ����� 
	p->top=-1;                                                           //˳��ջ��ʼΪ��ջ 
	S=*p;
}

void DestoryStack_sq(SqStack S)                                          //����˳��ջ S 
{
	struct stack *p;
	p=&S;
	while(p!=NULL){
		free(p);                                                        //�ͷ�����ռ�
		p++;
	}
	p->top=-1;
	p->stacksize=0;
}

void Push_sq(SqStack S, ElementType e)                                  //��ջ ��ĳ��Ԫ�ز��뵽ջ�� 
{
	if(S.top==S.stacksize-1)
	{
		struct stack *p;
		p=(struct stack*)malloc(STACK_INIT_SIZE*sizeof(struct stack));  //���ջ�������ӿռ� 
	}
	S.elem[++S.top]=e; 
}

bool Pop_sq(SqStack S, ElementType e)                                   //��ջ ��ջ��Ԫ��ɾ�� 
{
	if(S.top==-1) return false;                                         //��ջ�� ����false 
	else {
		e=S.elem[S.top--];
		return true;
	}                                                                   //��˳��ջ�ǿգ�ɾ��ջ��Ԫ�ز�����e,����true 
}

bool StackEmpty_sq(SqStack S)                                           //�ж�ջ�Ƿ�Ϊ�� 
{
	if(S.top==-1) return false;                                         //��ջ�� ����false 
	else return true;                                                   //��˳��ջ�ǿգ�����true 
}

bool StackTraverse_sq(SqStack S)
{
	if(S.top==-1) return false;                                         //��ջ�� ����false 
	else {
		printf("%d",S.elem[S.top--]);                                  //��˳��ջ�ǿգ���ӡջ
		return true;
	}
}

