/****************************************************

Name:            BinaryTree.h
Auther:            Hawkeye
Date:            2018.11.12
Function:   Binary tree basic operation
            
            void createBiTree(BiTree &T); //创建二叉树
			void preOrder(BiTree T);      //先序遍历
			void Mirror(BiTree &T);       //先序遍历镜像二叉树 

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

void createBiTree(BiTree &T){   //创建二叉树
	T=(struct BiTNode*)malloc(sizeof(struct BiTNode));
	T->lChild=(struct BiTNode*)malloc(sizeof(struct BiTNode));//为左右支树指针申请空间
	T->rChild=(struct BiTNode*)malloc(sizeof(struct BiTNode));
	T->lChild=T->rChild=NULL;                                 //左右支树指针初始化 
	T->maxlenleft=T->maxlenright=0;
}

void writeBiTree(BiTree &T){    //先序遍历对二叉树进行赋值 
	int treetype;
	printf("\nPlease type in the next node( '-1' present nil node)\n");
	scanf("%d",&treetype);      //读入data元素，#键入结束
	printf("\ndata is - %d\n",treetype);
	if(treetype==-1)            //读入data元素，#键入结束
		T=NULL;                 //建立一个空二叉树
	else{                       //若 T 存在，则继续建立左右子树
		T->data=treetype;       //typetree赋值给data
		createBiTree(T->lChild);//生成一个节点
		writeBiTree(T->lChild); //先序遍历对左子树进行赋值 
		createBiTree(T->rChild);//生成一个节点
		writeBiTree(T->rChild); //先序遍历对右子树进行赋值
	}
	//treetype='#';
	return;
}

void preOrder(BiTree T){       //先序遍历
	if(!T) return;             //空树直接返回 
	else{
		printf("%d\t",T->data);//访问根节点 
		preOrder(T->lChild);   //先序遍历左子树 
		preOrder(T->rChild);   //先序遍历右子树 
	}
}

void Mirror(BiTree &T){       //先序遍历镜像二叉树 
	BiTree p;
	if(!T) return;             //空树直接返回 
	else{
		p=T->lChild;
		T->lChild=T->rChild;
		T->rChild=p;
		Mirror(T->lChild);   //先序遍历镜像左子树 
		Mirror(T->rChild);   //先序遍历镜像右子树 
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

void CalculateMaxlen(BiTree T){//先序遍历找到具有最长链子的节点 
	if(!T) return;             //空树直接返回 
	else{
		if(T->maxlenleft+T->maxlenright>nMaxlen) nMaxlen=T->maxlenleft+T->maxlenright;
		CalculateMaxlen(T);    //先序遍历计算左子树 
		CalculateMaxlen(T);    //先序遍历计算右子树 
	}
}
