/*************************************************************************************************** 

Name:              SqQueue.h
Auther:            Hawkeye
Date:            2018.10.18
Function:         SqQueue ADT

2. �� д �� �� , CreateQueue_L() , DestoryQueue_L() , EnQueue_L() ,DeQueue_L(),
�ֱ����                 ��������,          ���ٶ���,       �����,     �����еȲ���,��ɺ���в��ԡ�
����Ҫ��:����������,��������,�� 0~9 ���������,�������˳������в���ӡ,���ٶ��С�
void CreateQueue_L(LinkQueue &Q){...}
void DestoryQueue_L(LinkQueue &Q){...}
void EnQueue_L(LinkQueue &Q,int e){...}
bool DeQueue_L(LinkQueue &Q, int &e){...}

***************************************************************************************************/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#define QUEUE_INIT_SIZE 10

//2.1 ���� ��

typedef struct LNode{
int data;
struct LNode *next;
}LNode,*LinkList;

void CreateQueue_L(LinkList Q)                                       //��ʼ�������� 
{
	Q.front=Q.rear=(struct LNode*)malloc(sizeof(struct LNode));       //Ϊ���׶�βָ������ռ�
	Q.front->next=NULL;
}

void DestoryQueue_L(LinkQueue Q)                                      //���������� 
{
	while(Q.front){
		Q.rear=Q.front->next;                                         //Q.rear���Ϻ���ָ��
		free(Q.front);                                                //�ͷ� Q.front ���
		Q.front=Q.rear; 
	}
}

void EnQueue_L(LinkQueue Q,int e)                                     //����� 
{
	struct LNode*p;
	p=(struct LNode*)malloc(sizeof(struct LNode));
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
}

bool DeQueue_L(LinkQueue Q, int e)                                  // ������ 
{
	struct LNode*p;
	if(Q.front=Q.rear) return false;
	p=(struct LNode*)malloc(sizeof(struct LNode));
	p=Q.front->next;
	Q.front->next=p->next;
	e=p->data;
	if(Q.rear==p)
	Q.rear=Q.front;
	free(p);
	return true;
}
