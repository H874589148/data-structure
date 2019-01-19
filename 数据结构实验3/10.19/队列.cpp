#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList; 
typedef LinkList Queueptr;
typedef struct{
	Queueptr front;
	Queueptr rear;
}LinkQueue;
int main()
{
	void CreateQueue_L(LinkQueue &Q);
	void DestroyQueue_L(LinkQueue &Q);
	void EnQueue_L(LinkQueue &Q,int e);
	bool DeQueue_L(LinkQueue &Q,int &e);
	LinkQueue Q;
	int i,a,b;
	CreateQueue_L(Q);
	for(i=0;i<=9;i++)
		EnQueue_L(Q,i);
		printf("队列输出如下：\n");
		for(i=0;i<=9;i++){
	    DeQueue_L(Q,a);
	   	printf("%d\n",a);
      }
      DestroyQueue_L(Q);
	return 0;	
}
void CreateQueue_L(LinkQueue &Q)
{
	Q.front=Q.rear=new LNode;
	Q.front->next=NULL; 
}
void DestroyQueue_L(LinkQueue &Q)
{
	while(Q.front)
	{
		Q.rear=Q.front->next;
		delete Q.front;
		Q.front=Q.rear;
	}
}
void EnQueue_L(LinkQueue &Q,int e)
{
	LNode *p;
	p=new LNode;
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
}
bool DeQueue_L(LinkQueue &Q,int &e)
{
	LNode *p;
	if(Q.front==Q.rear)return false;
	p=Q.front->next;
	Q.front->next=p->next;
	e=p->data;
	if(Q.rear==p)
	Q.rear=Q.front;
	delete p;
	return true;
}
