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
�ú������� List L������ֱ���޸�����Ľڵ㣬���鷵��ֵΪ int �� void ���ͣ�����ΪList ���ͣ� 3�� 4 ��ͬ��
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

     ��д���� InsertNodeByIdx(List &L, Node nd)��������²�����
�����д���� InsertNodeByIdx(List &L, Node *pnd)��������²�������
�������� Node *pnd���� Node nd ��Ϊ������������ InsertNodeByIdx�� nd �����ܱ��޸ģ�
      �������������޸� nd.next�����贴���µĽڵ�� nd �� idx �� age ��ֵ���½ڵ㡣��

3.1 ��(idx,age)=(6,23)����������֤����� idx ��Ϊ���򣬴�ӡ����
3.2 ��(idx,age)=(1,25)����������֤����� idx ��Ϊ���򣬴�ӡ����

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

/*������ 
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
