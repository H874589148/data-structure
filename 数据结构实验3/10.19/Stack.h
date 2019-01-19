/***************************************************************************************

Name:              Stack.h
Auther:            Hawkeye
Date:             2018.10.16
Function:          stack ADT

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

//1.2 ��ջ

typedef int ElementType;

typedef struct stack{
ElementType data;
struct stack* next;
}*Stack, *LinkStack;

Stack CreatStack_sq(Stack S)                                             //����һ����ջ S 
{
	S=(Stack)malloc(sizeof(struct stack));
	S=NULL;
	return S;                                                            //��ջ��ʼ��ջ 
}

void DestoryStack_sq(Stack S)                                            //������ջ S 
{
	struct stack *p,*q;
	p=S;
	q=S;
	while(q){
		q=q->next;                                                        //ָ����� 
		free(p);
	}
}

Stack Push_sq(Stack S, ElementType e)                                  //��ջ ��ĳ��Ԫ�ز��뵽ջ�� 
{
	struct stack *p;
	p=(Stack)malloc(sizeof(struct stack));
	p->data=e;
	p->next=S;
	S=p;
	return S;
}

Stack Pop_sq(Stack S, ElementType &e)                                   //��ջ ��ջ��Ԫ��ɾ�� 
{
	//if(S==NULL) return false;                                         //��ջ�� ����false 
	//else {
		e=S->data;
		S=S->next;
		return S;
	//}                                                                //��˳��ջ�ǿգ�ɾ��ջ��Ԫ�ز�����e,����true 
}

bool StackEmpty_sq(Stack S)                                           //�ж�ջ�Ƿ�Ϊ�� 
{
	if(S==NULL) return false;                                         //��ջ�� ����false 
	else return true;                                                 //��˳��ջ�ǿգ�����true 
}

bool StackTraverse_sq(Stack &S)
{
	if(S==NULL) return false;                                         //��ջ�� ����false 
	//else {
		while(S!=NULL){
			printf("%d",S->data);                                     //��˳��ջ�ǿգ���ӡջ
			S=S->next;
		}
		return true;
	//}
}
