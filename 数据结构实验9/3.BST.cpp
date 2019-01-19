/****************************************************

Name:             3.BST.cpp
Auther:            Hawkeye
Date:            2018.11.24
Function:     Binary Search Tree 
test data:    5 3 1 -1 -1 4 -1 -1 7 6 -1 -1 8 -1 -1

****************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#define STACK_INIT_SIZE 100

typedef int ElemType;
typedef int KeyType;

typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lChild ,*rChild;
	struct BiTNode *parent;
}BiTNode,*BiTree;

void createBiTree(BiTree &T); //����������
BiTree BinearySearchTreeMax(BiTree T); //��������������ֵ
BiTree BinearySearchTreeMin(BiTree T); //�������������Сֵ
bool InsertBST(BiTree &T, KeyType key); //��������������ض��ڵ�
bool DeleteBST(BiTree &T, KeyType key);//���������ɾ���ض��ڵ�

void createBiTree(BiTree &T){   //����������
	T=(struct BiTNode*)malloc(sizeof(struct BiTNode));
	T->lChild=(struct BiTNode*)malloc(sizeof(struct BiTNode));//Ϊ����֧��ָ������ռ�
	T->rChild=(struct BiTNode*)malloc(sizeof(struct BiTNode));
	T->lChild=T->rChild=NULL;                                 //����֧��ָ���ʼ�� 
}

void writeBiTree(BiTree &T){    //��������Զ��������и�ֵ 
	int treetype;
	printf("\nPlease type in the next node( '-1' present nil node)\n");
	scanf("%d",&treetype);      //����dataԪ�أ�#�������
	printf("\ndata is - %d\n",treetype);
	if(treetype==-1)            //����dataԪ�أ�#�������
		T=NULL;                 //����һ���ն�����
	else{                       //�� T ���ڣ������������������
		T->data=treetype;       //typetree��ֵ��data
		createBiTree(T->lChild);//����һ���ڵ�
		writeBiTree(T->lChild); //������������������и�ֵ 
		createBiTree(T->rChild);//����һ���ڵ�
		writeBiTree(T->rChild); //������������������и�ֵ
	}
	//treetype='#';
	return;
}

void inOrder(BiTree T){        //�������
	if(!T) return;             //�ն��������ղ��� 
	else{
		inOrder(T->lChild);    //������������� 
		printf("%d\t",T->data);//���ʸ��ڵ� 
		inOrder(T->rChild);    //������������� 
	}
}

BiTree Search_BST(BiTree T, KeyType key) {
	if (!T || key == T->data)
		return T;
	else if (key < T->data)
		return Search_BST(T->lChild, key);
	else
		return Search_BST(T->rChild, key);
}

bool SearchBST(BiTree T, KeyType key, BiTree &p, BiTree &f) {
	// �����ҵ�key���򷵻�true����ʱpָ�����key�Ľ�㣬f��p��˫�ף���p���ڸ���㣬��fΪNULL��
	// �����Ҳ���key���򷵻�false����ʱpΪNULL��fָ����ҹ��������һ���ȽϵĽ��
	f = NULL; p = T;
	while (p && key != p->data) {
		f = p;
		if (key < p->data) p = p->lChild;
		else p = p->rChild;
	}
	if (!p) return false;
	else return true;
}

BiTree BinearySearchTreeMin(BiTree T)//�������������Сֵ
{
	if(T == NULL)
		return NULL;
	else if(T->lChild == NULL)
		return T;
	return BinearySearchTreeMin(T->lChild);     //�ݹ���� 
}

BiTree BinearySearchTreeMax(BiTree T)//��������������ֵ
{
	if(T!= NULL)                   //�ǵݹ���� 
		while(T->rChild != NULL)
			T = T->rChild;
	return T;
}

bool InsertBST(BiTree &T, KeyType key) {
	BiTree p, f;
	bool found = SearchBST(T, key, p, f);
	if (found)
		return false;
	BiTree t = new BiTNode;
	t->data = key;
	t->lChild = t->rChild = NULL;
	if (!f)
		T = t;
	else if (key < f->data)
		f->lChild = t;
	else f->rChild = t;
	return true;
}

bool DeleteBST(BiTree &T, KeyType key) {
	BiTree p, f;
	bool found = SearchBST(T, key, p, f);
	if (!found)
		return false;
	if (p->lChild && p->rChild) {
		BiTree q = p, t = p->rChild;
		while (t->lChild){
			q = t;
			t = t->lChild;
		}
		p->data = t->data;
		if (q != p)
		q->lChild = t->rChild;
		else q->rChild = t->rChild;
		delete t;
	}
	else {
		BiTree q = p->lChild ? p->lChild : p->rChild;
		if (!f)
			T = q;
		else if (p == f->lChild)
			f->lChild = q;
		else
			f->rChild = q;
			delete p;
	}
	return true;
}


int main(){
	BiTree T,U;
	int u,v;
	createBiTree(T);
	createBiTree(U);
	writeBiTree(T);
	printf("\n\nThe Binary Tree create just now's  inorder  is ---\n");
	inOrder(T);
	//
	U=BinearySearchTreeMax(T); //��������������ֵ
	printf("\n\nThe max number is %d .\n",U->data);
	U=BinearySearchTreeMin(T); //�������������Сֵ
	printf("\nThe min number is %d .\n",U->data);
	printf("\nPlease input the number you want to insert : ");
	scanf("%d",&u);
	if(InsertBST(T,u)){//��������������ض��ڵ�
		printf("\nInsert successfully!");
		printf("\n\nThe Binary Tree after insert 's  inorder  is ---\n");
		inOrder(T);
	}
	else printf("\nFALSE!\n");
	printf("\n\nPlease input the number you want to delete : ");
	scanf("%d",&v);
	if(DeleteBST(T,v)){//���������ɾ���ض��ڵ�
		printf("\nDelete successfully!");
		printf("\n\nThe Binary Tree after delete 's  inorder  is ---\n");
		inOrder(T);
	}
	return 0;
}
