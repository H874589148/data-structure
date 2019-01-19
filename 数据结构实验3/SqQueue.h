/*************************************************************************************************** 

Name:              SqQueue.h
Auther:            Hawkeye
Date:            2018.10.18
Function:         SqQueue ADT

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

void CreateQueue_L(LinkList Q)                                       //初始化链队列 
{
	Q.front=Q.rear=(struct LNode*)malloc(sizeof(struct LNode));       //为队首队尾指针申请空间
	Q.front->next=NULL;
}

void DestoryQueue_L(LinkQueue Q)                                      //销毁链队列 
{
	while(Q.front){
		Q.rear=Q.front->next;                                         //Q.rear不断后移指针
		free(Q.front);                                                //释放 Q.front 结点
		Q.front=Q.rear; 
	}
}

void EnQueue_L(LinkQueue Q,int e)                                     //入队列 
{
	struct LNode*p;
	p=(struct LNode*)malloc(sizeof(struct LNode));
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
}

bool DeQueue_L(LinkQueue Q, int e)                                  // 出队列 
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
