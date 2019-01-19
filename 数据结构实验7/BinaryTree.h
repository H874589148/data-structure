/****************************************************

Name:            BinaryTree.h
Auther:            Hawkeye
Date:            2018.11.12
Function:   Binary tree basic operation
            
            void createBiTree(BiTree &T); //����������
			void preOrder(BiTree T);      //�������
			void Mirror(BiTree &T);       //���������������� 

****************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h> 

typedef int TElemType;

typedef struct BiTNode{
TElemType data;
struct BiTNode *lChild,*rChild;
int maxlenleft,maxlenright;
}BiTNode,*BiTree;

void createBiTree(BiTree &T){   //����������
	T=(struct BiTNode*)malloc(sizeof(struct BiTNode));
	T->lChild=(struct BiTNode*)malloc(sizeof(struct BiTNode));//Ϊ����֧��ָ������ռ�
	T->rChild=(struct BiTNode*)malloc(sizeof(struct BiTNode));
	T->lChild=T->rChild=NULL;                                 //����֧��ָ���ʼ�� 
	T->maxlenleft=T->maxlenright=0;
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

void preOrder(BiTree T){       //�������
	if(!T) return;             //����ֱ�ӷ��� 
	else{
		printf("%d\t",T->data);//���ʸ��ڵ� 
		preOrder(T->lChild);   //������������� 
		preOrder(T->rChild);   //������������� 
	}
}

void Mirror(BiTree &T){       //���������������� 
	BiTree p;
	if(!T) return;             //����ֱ�ӷ��� 
	else{
		p=T->lChild;
		T->lChild=T->rChild;
		T->rChild=p;
		Mirror(T->lChild);   //����������������� 
		Mirror(T->rChild);   //����������������� 
	}
}

int Max(int a,int b){
	if(a>b) return a;
	else return b;
}

int nMaxlen=3;

void FindMaxlen(BiTree &T){
	if(!T->lChild){
		T->maxlenleft=0;
		FindMaxlen(T->rChild);
		return;
	}
	if(!T->rChild){
		T->maxlenright=0;
		FindMaxlen(T->lChild);
		return;
	}
	if(T && T->lChild && T->rChild){
		T->maxlenleft =1+Max(T->lChild->maxlenleft , T->lChild->maxlenright);
		T->maxlenright=1+Max(T->rChild->maxlenleft , T->rChild->maxlenright);
		FindMaxlen(T->lChild);
		FindMaxlen(T->rChild);
		return;
	}
	if(!T){
		printf("Error!");
		return;
	}
}

void CalculateMaxlen(BiTree T){//��������ҵ���������ӵĽڵ� 
	if(!T) return;             //����ֱ�ӷ��� 
	else{
		if(T->maxlenleft+T->maxlenright>nMaxlen) nMaxlen=T->maxlenleft+T->maxlenright;
		CalculateMaxlen(T);    //����������������� 
		CalculateMaxlen(T);    //����������������� 
	}
}
