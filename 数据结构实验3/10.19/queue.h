/*************************************************************************************************** 

Name:              queue.h
Auther:            Hawkeye
Date:            2018.10.7
Function:         queue ADT

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

typedef LinkList Queueptr;

//2.2 ������ ��

typedef struct queue{
Queueptr front;
Queueptr rear;
}*Queue,LinkQueue; 

Queue CreateQueue_L(Queue Q)                                             //��ʼ�������� 
{
	Q=(Queue)malloc(sizeof(struct queue));
	Q->front=(struct LNode*)malloc(sizeof(struct LNode));               //Ϊ���׶�βָ������ռ�
	Q->rear=Q->front;
	Q->rear->next=NULL;
	return Q;
}

void DestoryQueue_L(Queue Q)                                            //���������� 
{
	while(Q->front){
		Q->rear=Q->front->next;                                         //Q.rear���Ϻ���ָ��
		free(Q->front);                                                //�ͷ� Q.front ���
		Q->front=Q->rear; 
	}
}

Queue EnQueue_L(Queue Q,int e)                                          //����� 
{
	struct LNode*p;
	p=(struct LNode*)malloc(sizeof(struct LNode));
	p->data=e;
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
	return Q;
}

bool DeQueue_L(Queue Q, int &e)                                        // ������ 
{
	
	LNode* p = Q->front->next;
	if(Q->front==Q->rear){
		//printf("haha");
		return false;
	}
	//printf("!!!");
	//p=(struct LNode*)malloc(sizeof(struct LNode));
	//printf("???");
	Q->front->next=p->next;
	//printf("hahaha");
	e=p->data;
	//printf("ha");
	//printf("%d\n",e);
	if(Q->rear==p)
	Q->rear=Q->front;
	free(p);
	return true;
}
