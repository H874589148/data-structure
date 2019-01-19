#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct BiThrNode{
	char data;
	struct BiThrNode *lchild,*rchild;
	int ltag,rtag;
}BiThrNode,*BiThrTree;
BiThrTree pre=NULL;
int main()
{
	void createBiThrTree(BiThrTree &T);
	void InThreading(BiThrTree T);
	BiThrTree GetNext(BiThrTree p);
	void InOrder(BiThrTree T);
	void InOrderThreading(BiThrTree &p,BiThrTree T);
	BiThrTree T,p;
	createBiThrTree(T);
	InOrderThreading(p,T);
	InOrder(p);
	return 0;
}
void createBiThrTree(BiThrTree &T)
{
	char e; 
	scanf("%c",&e);
	if(e=='#')
	  T=NULL;
	else
	{
		T=(BiThrTree)malloc(sizeof(BiThrNode));
		T->data=e;
		T->ltag=0;
		T->rtag=0;
		createBiThrTree(T->lchild);
		createBiThrTree(T->rchild);
	}
   	
}
void InThreading(BiThrTree T)
{
	if(T)
	{
		InThreading(T->lchild);
		if(!T->lchild)
		{
			T->ltag=1;
			T->lchild=pre;
		}
		if(!pre->rchild)
		{
			pre->rtag=1;
			pre->rchild=T;
		}
		pre=T;
		InThreading(T->rchild);
	}
}
BiThrTree GetNext(BiThrTree p)
{
	BiThrTree q;
	if(p->rtag==1)
	return p->rchild;
	else
	{
		q=p->rchild;
		while(q->ltag==0) q=q->lchild;
		return q;
	}
}
void InOrder(BiThrTree T)
{
	BiThrTree p;
	p=T->lchild;
	while(p!=T)
	{
		while(p->ltag==0)
		  p=p->lchild;
		printf("%c",p->data);
		while(p->rtag==1&&p->rchild!=T)
		{
			p=p->rchild;
			printf("%c",p->data);
		}
		p=p->rchild;
	}
	
}
void InOrderThreading(BiThrTree &p,BiThrTree T)
{
	p=(BiThrTree)malloc(sizeof(BiThrNode));
	p->ltag=0;
	p->rtag=1;
	p->rchild=p;
	if(!T)
	 p->lchild=p;
	else
	{
		p->lchild=T;
		pre=p;
		InThreading(T);
		pre->rchild=p;
		pre->rtag=1;
		p->rchild=pre;
	}
}


















































































