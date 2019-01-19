/*************************************************************************************************** 

Name:              queue.h
Auther:            Hawkeye
Date:            2018.10.7
Function:         queue ADT

2. 编 写 函 数 , CreateQueue_L() , DestoryQueue_L() , EnQueue_L() ,DeQueue_L(),
分别完成                 创建队列,          销毁队列,       入队列,     出队列等操作,完成后进行测试。
测试要求:在主程序中,建立队列,将 0~9 依次入队列,按入队列顺序出队列并打印,销毁队列。
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

//2.1 队列 ：

typedef struct LNode{
int data;
struct LNode *next;
}LNode,*LinkList;

typedef LinkList Queueptr;

//2.2 链队列 ：

typedef struct queue{
Queueptr front;
Queueptr rear;
}*Queue,LinkQueue; 

Queue CreateQueue_L(Queue Q)                                             //初始化链队列 
{
	Q=(Queue)malloc(sizeof(struct queue));
	Q->front=(struct LNode*)malloc(sizeof(struct LNode));               //为队首队尾指针申请空间
	Q->rear=Q->front;
	Q->rear->next=NULL;
	return Q;
}

void DestoryQueue_L(Queue Q)                                            //销毁链队列 
{
	while(Q->front){
		Q->rear=Q->front->next;                                         //Q.rear不断后移指针
		free(Q->front);                                                //释放 Q.front 结点
		Q->front=Q->rear; 
	}
}

Queue EnQueue_L(Queue Q,int e)                                          //入队列 
{
	struct LNode*p;
	p=(struct LNode*)malloc(sizeof(struct LNode));
	p->data=e;
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
	return Q;
}

bool DeQueue_L(Queue Q, int &e)                                        // 出队列 
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
