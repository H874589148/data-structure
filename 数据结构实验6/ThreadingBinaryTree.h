/****************************************************

Name:      ThreadingBinaryTree.h
Auther:            Hawkeye
Date:            2018.11.4
Function:   Threading binary tree basic operation
            
            void InThreading(BiThrTree T)
			BiThrTree GetNext(BiThrTree P)
			void InOrder(BiThrTree T)

****************************************************/

#include<stdio.h>
#include<stdlib.h>

/*typedef struct BiThrNode{
TElemType data;
struct BiThrNode *lChild,*rChild;
unsigned char ltag,rtag;
}BiThrNode,*BiThrTree;*/

typedef char TElemType;
typedef struct BiThrNode {
	TElemType data;                         //数据域 
	BiThrNode *lchild, *rchild;             //左右指针域 
	bool ltag, rtag;                        //左右标志域 
}BiThrNode,*BiThrTree;

/*
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
}*/

void createBiThrTree(BiThrTree &T){                               //创建二叉树
	T=(struct BiThrNode*)malloc(sizeof(struct BiThrNode));
	T->lchild=(struct BiThrNode*)malloc(sizeof(struct BiThrNode));//为左右支树指针申请空间
	T->rchild=(struct BiThrNode*)malloc(sizeof(struct BiThrNode));
	T->lchild=T->rchild=NULL;                                     //左右支树指针初始化 
	T->ltag=false;
	T->rtag=false;
}

void writeBiThrTree(BiThrTree &T){          //先序遍历对二叉树进行赋值 
	char treetype;
	printf("\nPlease type in the next node( '#' present nil node)\n");
	//scanf("%c",&treetype);
	treetype=getchar();                     //读入data元素，#键入结束
	printf("\ndata is - %c\n",treetype);
	if(treetype=='#')                       //读入data元素，#键入结束
		T=NULL;                             //建立一个空二叉树
	else{                                   //若 T 存在，则继续建立左右子树
		T->data=treetype;                   //typetree赋值给data
		createBiThrTree(T->lchild);         //生成一个节点
		writeBiThrTree(T->lchild);          //先序遍历对左子树进行赋值 
		createBiThrTree(T->rchild);         //生成一个节点
		writeBiThrTree(T->rchild);          //先序遍历对右子树进行赋值
	}
	//treetype='#';
	return;
}

void preOrder(BiThrTree T){                 //先序遍历
	if(!T) return;                          //空树直接返回 
	else{
		printf("%c\t",T->data);             //访问根节点 
		preOrder(T->lchild);                //先序遍历左子树 
		preOrder(T->rchild);                //先序遍历右子树 
	}
}

/*void inOrder(BiThrTree T){                  //中序遍历
	if(!T) return;                          //空二叉树，空操作 
	else{
		inOrder(T->lchild);                 //中序遍历左子树 
		printf("%c\t",T->data);             //访问根节点 
		inOrder(T->rchild);                 //中序遍历右子树 
	}
}*/

BiThrTree pre = NULL;                       //pre 是全局变量 
void InThreading(BiThrTree T) {             //中序线索化二叉树 T ，设 T 中每个节点的ltag 和rtag 的初值是 0 
	if (!T) return;
	InThreading(T->lchild);                 //中序线索化二叉树 T 的左子树 
	if (!T->lchild) {
		T->ltag = true; T->lchild = pre;    //填写 T 的左标志和左线索 
	}
	if (pre && !pre->rchild) {
		pre->rtag = true; pre->rchild = T;  //填写 pre 的右标志和右线索 
	}
	pre = T;                                //保持 pre 指向 T 的中序前驱 
	InThreading(T->rchild);                 //中序线索化二叉树 T 的右子树
}

BiThrTree GetNext(BiThrTree p) {            //返回中序线索链表上结点 *p 的直接后继指针 
	if (p->rtag) return p->rchild;          //直接返回 p 的右线索 
	BiThrTree q = p->rchild;                //先令辅助指针 q 指向 p 的右子树树根 
	if(q)
	while (!(q->ltag)) q = q->lchild;       //搜索“最左下”结点 
	return q;                               //返回 p 右子树上最左下结点指针 
}

void Visit(TElemType ele){
	printf("%c\t",ele);
}

void InOrderTraverse(BiThrTree T) {
//void InOrderTraverse(BiThrTree T, void (*Visit)(TElemType)) {
	//利用中序线索来中序遍历二叉树 
	if (T) {
		BiThrTree p = T;
		while (!p->ltag) p = p->lchild;     //找中序序列的第一个结点 
		do {
			printf("%c\t",p->data);
			//Visit(p->data);               //访问 p; 
			p = GetNext(p);                 //p 移至中序后继 
		} while (p);
	}
}

bool IsInTree(BiThrTree T, BiThrTree R){    //中序遍历查找结点 R 是否在二叉树 T 中
	if(!T) return false;                    //空树直接返回
	while(T){
		if(T->data == R->data) return true; //访问根节点
		else return( IsInTree(T->lchild,R) || IsInTree(T->rchild,R) ); 
	}
}

BiThrTree search(BiThrTree T, char ele){    //遍历二叉树,查找ele,返回该节点的指针
	BiThrTree R;
	if(!T) return NULL;                     //空树直接返回 
	else{
		if(T->data == ele) return T;        //访问根节点 
		R=search(T->lchild,ele);            //遍历左子树 
		if(R) return R;
		R=search(T->rchild,ele);            //遍历右子树 
		if(R) return R;
	}
}

void FindParent(BiThrTree T,BiThrTree R,BiThrTree &S){//找到某个节点的双亲 
	/*if (T) {
		BiThrTree p = T;
		while (!p->ltag) p = p->lchild;     //找中序序列的第一个结点 
		do {
			if(p->lchild == R || p->rchild == R) return p;
			p = GetNext(p);                 //p 移至中序后继 
		} while (p);
	}*/
	
	if(!T) return;
	else{
		//if( T==R ) return;
		if( T->lchild!=NULL && T->lchild->data==R->data )
		{
			S=T;
			//printf("Find parent %c",S->data);
		}
		if( T->rchild!=NULL && T->rchild->data==R->data )
		{
			S=T;
			//printf("Find parent %c",S->data);
		}
		FindParent(T->lchild,R,S);                 //先序遍历左子树 
		FindParent(T->rchild,R,S);
	}
}

BiThrTree GetLastParent(BiThrTree pRoot, BiThrTree P1, BiThrTree P2){
	//求二叉树中两个节点的最低公共祖先节点
	BiThrTree R;
	createBiThrTree(R);
	FindParent(pRoot,P1,R);
	while(!IsInTree(R,P2)){
		FindParent(pRoot,R,R);
	}
	return R;
}
