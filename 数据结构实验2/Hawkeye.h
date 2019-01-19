#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct node {
int idx;
int age;
struct node* next;
}Node, *List;

/****************************************************

Name:            ArrayCreateList.h
Auther:            Hawkeye
Date:           2018.10.8
Function:    Create a linear list from an array

int idx[8] = {1,2,3,4,5,6,7,8};
int age[8] = {15,18,13,22,50,18,30,20};
List CreatList(int idx[], int age[],int len){}
int PrintList(List L){}

****************************************************/

List CreateList(int idx[],int age[],int len){
	//printf("1\n");
	int i=0;
	struct node*head = NULL;
	struct node*rear = NULL;
	struct node*p;
	head=NULL;
	while(i<len){
		p=(struct node*)malloc(sizeof(struct node));
		p->idx=idx[i];
		p->age=age[i];
		//head=p;
		if(head==NULL) head=p;
		else rear->next=p;
		rear=p;
		i++;
	}
	if(rear!=NULL)
		rear->next=NULL;
	return head;
}

void PrintList(List L)
{
	struct node*p=L;
	printf("idx  age\n");
	while(p!=NULL){
		printf("%3d  %3d\n",p->idx,p->age);
		p=p->next;
	}
}

/****************************************************

Name:            ModifyList.c
Auther:            Hawkeye
Date:           2018.10.8
Function:    Modify or delete a list

DeleteNode(List &L, int delete_age)
int DeleteNodeAge(List &L, int delete_age){}
该函数传入 List L，可以直接修改链表的节点，建议返回值为 int 或 void 类型，无需为List 类型， 3， 4 题同上
2.1 Delete age==18 person,print list;
2.2 Delete age==20 person,print list;
2.3 Delete age==15 person,print list;
2.4 Delete age==21 person(not exist! return error! ) , print list;

****************************************************/

List DeleteNodeAge(List L, int delete_age)
{
	struct node*p,*q;
	if(L->age==delete_age){
		p=L;
		L=p->next;
		free(p);
		return L;
	}
	q=p=L;
	while(p!=NULL&&p->age!=delete_age){
		q=p;
		p=p->next;
	}
	if(p!=NULL){
		q->next=p->next;
		free(p);
		return L;
	}
	printf("Not Found!\n");
	return L;
}

/****************************************************

Name:            InsertList.c
Auther:            Hawkeye
Date:           2018.10.8
Function:       Insert list

     编写函数 InsertNodeByIdx(List &L, Node nd)，完成以下操作。
（或编写函数 InsertNodeByIdx(List &L, Node *pnd)，完成以下操作。）
（建议用 Node *pnd，因 Node nd 作为参数传给函数 InsertNodeByIdx， nd 本身不能被修改，
      而插入链表需修改 nd.next，故需创建新的节点把 nd 的 idx 和 age 赋值给新节点。）

3.1 将(idx,age)=(6,23)插入链表，保证链表的 idx 仍为升序，打印链表。
3.2 将(idx,age)=(1,25)插入链表，保证链表的 idx 仍为升序，打印链表。

****************************************************/

//InsertNodeByIdx(List L,Node *pnd){
List InsertNodeByIdx(List L,Node *pnd){
	//printf("1");
	struct node*p,*q;
	if(L==NULL){
		L=pnd;printf("%3d  %3d\n",L->idx,L->age);
		return L;
	} 
	if(L->idx>pnd->idx){
		pnd->next=L;
		L=pnd;
		return L;
	}
	p=q=L;
	//printf("2");
	while(p!=NULL && p->idx<pnd->idx){
		q=p;
		p=p->next;
	}
	q->next=pnd;
	pnd->next=p;
	return L;
}

void DestoryList(List L)
{
	struct node*p=L;
	//printf("idx  age\n");
	while(p!=NULL){
		free(p);
		p=p->next;
	}
}

/*第四题 
*/

List InsertNodeByAge(List L, Node *pnd){
	struct node*p,*q,*pm,*pn;
	int del=50;
	if(L==NULL){
		L=pnd;printf("%3d  %3d\n",L->idx,L->age);
		return L;
	} 
	if(L->age>pnd->age){
		del=L->age-pnd->age;
		pnd->next=L;
		L=pnd;
		return L;
	}
	//printf("2");
	p=q=L;
	//pm=L;
	while(p!=NULL){
		if((pnd->age)<(p->age) && (p->age)-(pnd->age)<del){
			del=(p->age)-(pnd->age);
			pm=p;
		}
		q=p;
		p=p->next;
	}
	pm->next=pnd;
	pnd->next=pm->next;
	return L;
} 
