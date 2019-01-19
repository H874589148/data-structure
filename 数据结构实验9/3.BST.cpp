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

void createBiTree(BiTree &T); //创建二叉树
BiTree BinearySearchTreeMax(BiTree T); //二叉检索树的最大值
BiTree BinearySearchTreeMin(BiTree T); //二叉检索树的最小值
bool InsertBST(BiTree &T, KeyType key); //二叉检索树插入特定节点
bool DeleteBST(BiTree &T, KeyType key);//二叉检索树删除特定节点

void createBiTree(BiTree &T){   //创建二叉树
	T=(struct BiTNode*)malloc(sizeof(struct BiTNode));
	T->lChild=(struct BiTNode*)malloc(sizeof(struct BiTNode));//为左右支树指针申请空间
	T->rChild=(struct BiTNode*)malloc(sizeof(struct BiTNode));
	T->lChild=T->rChild=NULL;                                 //左右支树指针初始化 
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

void inOrder(BiTree T){        //中序遍历
	if(!T) return;             //空二叉树，空操作 
	else{
		inOrder(T->lChild);    //中序遍历左子树 
		printf("%d\t",T->data);//访问根节点 
		inOrder(T->rChild);    //中序遍历右子树 
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
	// 若查找到key，则返回true，此时p指向等于key的结点，f是p的双亲（若p等于根结点，则f为NULL）
	// 若查找不到key，则返回false，此时p为NULL，f指向查找过程中最后一个比较的结点
	f = NULL; p = T;
	while (p && key != p->data) {
		f = p;
		if (key < p->data) p = p->lChild;
		else p = p->rChild;
	}
	if (!p) return false;
	else return true;
}

BiTree BinearySearchTreeMin(BiTree T)//二叉检索树的最小值
{
	if(T == NULL)
		return NULL;
	else if(T->lChild == NULL)
		return T;
	return BinearySearchTreeMin(T->lChild);     //递归查找 
}

BiTree BinearySearchTreeMax(BiTree T)//二叉检索树的最大值
{
	if(T!= NULL)                   //非递归查找 
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
	U=BinearySearchTreeMax(T); //二叉检索树的最大值
	printf("\n\nThe max number is %d .\n",U->data);
	U=BinearySearchTreeMin(T); //二叉检索树的最小值
	printf("\nThe min number is %d .\n",U->data);
	printf("\nPlease input the number you want to insert : ");
	scanf("%d",&u);
	if(InsertBST(T,u)){//二叉检索树插入特定节点
		printf("\nInsert successfully!");
		printf("\n\nThe Binary Tree after insert 's  inorder  is ---\n");
		inOrder(T);
	}
	else printf("\nFALSE!\n");
	printf("\n\nPlease input the number you want to delete : ");
	scanf("%d",&v);
	if(DeleteBST(T,v)){//二叉检索树删除特定节点
		printf("\nDelete successfully!");
		printf("\n\nThe Binary Tree after delete 's  inorder  is ---\n");
		inOrder(T);
	}
	return 0;
}
