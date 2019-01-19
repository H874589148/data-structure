/****************************************************

Name:            BinaryTree.h
Auther:            Hawkeye
Date:            2018.10.29
Function:   Binary tree basic operation
            
            void createBiTree(BiTree &T); //创建二叉树
			void preOrder(BiTree T);      //先序遍历
			void inOrder(BiTree T);       //中序遍历
			void postOrder(BiTree T);     //后序遍历
			void levelTraversal(BiTree T);//层序遍历
			int depth(BiTree T);          //求树的深度
			int countNodes(BiTree T);     //后序遍历求节点数

****************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#define STACK_INIT_SIZE 100

typedef int TElemType;

typedef struct BiTNode{
TElemType data;
struct BiTNode *lChild,*rChild;
}BiTNode,*BiTree;

/****************************************************

Name:              queue.h
Auther:            Hawkeye
Date:            2018.10.30
Function:   queue basic operation

****************************************************/

typedef struct LNode{
	BiTree tree;
	struct LNode *next;
}LNode,*LinkList; 

typedef LinkList Queueptr;

typedef struct{
	Queueptr front;
	Queueptr rear;
}LinkQueue;

void CreateQueue_L(LinkQueue &Q)     //创建队列 
{ 
	Q.front=Q.rear=new LNode;
	Q.front->next=NULL;              //指针置为空 
}
void DestroyQueue_L(LinkQueue &Q)    //销毁队列 
{
	while(Q.front)
	{
		Q.rear=Q.front->next;
		delete Q.front;              //释放指针空间 
		Q.front=Q.rear;
	}
}

void EnQueue_L(LinkQueue &Q,BiTree e)//入队列 
{
	LNode *p;
	p=new LNode;
	p->tree=e;
	p->next=NULL;
	Q.rear->next=p;
	if(Q.front==Q.rear) Q.front->next=p;
	Q.rear=p;
}

bool DeQueue_L(LinkQueue &Q,BiTree &e)//出队列 
{
	LNode *p;
	if(Q.front==Q.rear) return false;
	p=Q.front->next;
	Q.front->next=p->next;
	e=p->tree;
	if(Q.rear==p)
	Q.rear=Q.front;
	delete p;                         //释放指针空间 
	return true;
}

bool QueueEmpty(LinkQueue Q){         //判断队列是否为空，是返回true ，否返回false 
	if(Q.front==NULL && Q.rear==NULL && Q.front->next==NULL) return true;
	else return false;
}

/****************************************************

Name:              stack.h
Auther:            Hawkeye
Date:            2018.10.31
Function:   stack basic operation

****************************************************/

typedef struct{
	BiTree *tree;
	int stacksize;
	int top;
}SqStack;

void CreateStack_sq(SqStack &S)                           //初始化栈 
{
	int msize=STACK_INIT_SIZE;
	S.tree=(BiTree*)malloc(sizeof(BiTree)*msize);
	//S.tree=NULL;
	S.stacksize=msize;
	S.top=-1;
}

void DestroyStack_sq(SqStack &S)                          //销毁栈 
{
	free(S.tree);
	S.top=-1;
	S.stacksize=0;
}

void Push_sq(SqStack &S,BiTree e)                         //进栈 
{
   S.tree[++S.top]=e;	
}

bool Pop_sq(SqStack &S,BiTree &e)                         //出栈 
{
	if(S.top==-1) return false;
	e=S.tree[S.top--];
	return true;
}

bool StackEmpty_sq(SqStack &S)                           //判断栈是否为空 
{
	if(S.top==-1) return true;
	else return false;
}

/****************************************************************************

                            !  Begin  !

****************************************************************************/

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

void preOrder(BiTree T){       //先序遍历
	if(!T) return;             //空树直接返回 
	else{
		printf("%d\t",T->data);//访问根节点 
		preOrder(T->lChild);   //先序遍历左子树 
		preOrder(T->rChild);   //先序遍历右子树 
	}
}

void inOrder(BiTree T){        //中序遍历
	if(!T) return;             //空二叉树，空操作 
	else{
		inOrder(T->lChild);    //中序遍历左子树 
		printf("%d\t",T->data);//访问根节点 
		inOrder(T->rChild);    //中序遍历右子树 
	}
}

void postOrder(BiTree T){      //后序遍历
	if(!T) return;             //空二叉树，空操作 
	else{
		postOrder(T->lChild);  //后序遍历左子树 
		postOrder(T->rChild);  //后序遍历右子树 
		printf("%d\t",T->data);//访问根节点
	}
}

void levelTraversal(BiTree T){ //层序遍历
	LinkQueue Q;
	CreateQueue_L(Q);          //初始化一个空队列 
	if(T) EnQueue_L(Q,T);      //非空根指针入队列 
	struct BiTNode*p;
	p=(struct BiTNode*)malloc(sizeof(struct BiTNode));
	//while(!QueueEmpty){
	while(Q.front!=Q.rear){
		DeQueue_L(Q,p);
		printf("%d\t",p->data);
		if(p->lChild) EnQueue_L(Q,p->lChild);
		if(p->rChild) EnQueue_L(Q,p->rChild);
		//free(p);
	}
	//free(p);
	DestroyQueue_L(Q);
}

int depth(BiTree T){           //求树的深度
	int hl,hr;
	if(!T)
		return 0;              //空二叉树深度为0 
	else{
		hl=depth(T->lChild);   //计算左子树深度 
		hr=depth(T->rChild);   //计算右子树深度 
		return(hl>hr?hl+1:hr+1);
	}
}

int countNodes(BiTree T){        //后序遍历求节点数
	int nl,nr;
	if(!T) return 0;
	else{
		nl=countNodes(T->lChild);//统计左子树 
		nr=countNodes(T->rChild);//统计右子树 
	}
	return (1+nl+nr);
}

                             //第二题 
/****************************************************************************

                            !  Begin  !
                              非递归 
                void SpreOrder(BiTree T);  //非递归先序遍历
				void SinOrder(BiTree T);   //非递归中序遍历
				void SpostOrder(BiTree T); //非递归后序遍历

****************************************************************************/

void SpreOrder(BiTree T){                        //先序遍历二叉树的非递归算法， T 是二叉树的根指针 
	SqStack S;
	CreateStack_sq(S);                           //初始化一个空栈
	while(T || !StackEmpty_sq(S)){               //遍历结束的条件是栈为空且 T 为空 
		while(T){
			printf("%d\t",T->data);              //访问指针 T 指向的结点 
			Push_sq(S,T);                        // T 进栈 
			T=T->lChild;                         //向左转，继续遍历 T 的左子树 
		}
		if(!StackEmpty_sq(S)){
			//printf("%d",T->data);              //访问指针 T 指向的结点 
			Pop_sq(S,T);                         //弹出栈顶指针 T 
			T=T->rChild;                         //向右转，继续遍历 T 的左子树 
		}
		//printf("0");
	}
	DestroyStack_sq(S);                          //销毁栈 
}

void SinOrder(BiTree T){                         //中序遍历二叉树的非递归算法， T 是二叉树的根指针
	SqStack S;
	CreateStack_sq(S);                           //初始化一个空栈
	while(T || !StackEmpty_sq(S)){               //遍历结束的条件是栈为空且 T 为空 
		while(T){
			Push_sq(S,T);                        // T 进栈 
			T=T->lChild;                         //向左转，继续遍历 T 的左子树 
		}
		if(!StackEmpty_sq(S)){
			Pop_sq(S,T);                         //弹出栈顶指针 T 
			printf("%d\t",T->data);              //访问指针 T 指向的结点 
			T=T->rChild;                         //向右转，继续遍历 T 的左子树 
		}
	}
	DestroyStack_sq(S);                          //销毁栈 
}

typedef struct NodePost{
	BiTree tree;
	char tag;
}NodePost;

typedef struct{
	NodePost *elem;
	int stacksize;
	int top;
}SqStack1; 

void SpostOrder(BiTree T)                        //后序遍历二叉树的非递归算法， T 是二叉树的根指针
//void PostOrder(BiTree T)
{
	SqStack1 S;
	int msize=STACK_INIT_SIZE;
	S.elem=(NodePost *)malloc(sizeof(NodePost)*msize);
	S.stacksize=msize;
	S.top=-1;
	while(T||S.top!=-1)
	{
		while(T)
		{
			NodePost bp;
			bp.tree=T;
			bp.tag='L';
			S.elem[++S.top]=bp;	
			T=T->lChild;
		}
		while(S.top!=-1&&S.elem[S.top].tag=='R')
		{
			printf("%d\t",S.elem[S.top].tree->data);
			S.top--;
		}
		if(S.top!=-1&&S.elem[S.top].tag=='L')
		{
			S.elem[S.top].tag='R';
			T=S.elem[S.top].tree->rChild;
		}
	}
}
	/*int i,flag[20];
	BiTree p;
	SqStack S;
	CreateStack_sq(S);                           //初始化一个空栈
	//p=T;
	while(T||(S.top!=-1)){
		if(T){
			Push_sq(S,T);
			flag[S.top]=0;
			T=T->lChild;
		}
		else{
			while(flag[S.top]==1){
				Pop_sq(S,T);
				printf("%d\t",T->data);
			}
			Pop_sq(S,T);
			T=T->rChild;
			flag[S.top]=1;
		}
	}
}*/
/*	while(T || !StackEmpty_sq(S)){               //遍历结束的条件是栈为空且 T 为空 
		while(T){
			Push_sq(S,T);                        // T 进栈 
			while(T->lChild || T->rChild){
				Push_sq(S,T);
			}
			T=T->lChild;                         //向左转，继续遍历 T 的左子树 
			printf("%d\t",T->data);              //访问指针 T 指向的结点
			if(flag>0) {
				Pop_sq(S,T);
				printf("%d\t",T->data);
				flag--;
			}
		}
		if(!StackEmpty_sq(S)){
			Pop_sq(S,T);                         //弹出栈顶指针 T
			T=T->rChild;                         //向右转，继续遍历 T 的右子树 
			flag++;
			//Pop_sq(S,T);
			//printf("%d\t",T->data);
		}
	}
	DestroyStack_sq(S);                          //销毁栈 
}*/

int NodeNumber(BiTree T,int lev){                //利用递归的方式求解二叉树第 lev 层节点的个数
	//lev--;                                     //根节点为第一层 
	//int count=0;
	if(!T || lev<0) 
		return 0;                                //若为空树或 lev 不合法，则返回 0 
	/*else if(!lev)
		count++;                                 //当前节点计数 
	else{
		count+=NodeNumber(T->lChild,lev-1);      //左子树向下计数 
		count+=NodeNumber(T->rChild,lev-1);      //右子树向下计数 
	}
	return count;
	*/
	if(lev==1) return 1;
	int nl,nr;
	nl=NodeNumber(T->lChild,lev-1);              //左子树向下计数 
	nr=NodeNumber(T->rChild,lev-1);              //右子树向下计数 
	return (nl+nr);
}

int JudgeCompleteTree(BiTree T){
	int i,dep,flag1=0,flag2=0,fflag=1;
	dep=depth(T);
	for(i=1;i<dep;i++){
		if(NodeNumber(T,i)!=pow(2,i-1)) fflag=0;
	}
	/*LinkQueue Q;
	CreateQueue_L(Q);          //初始化一个空队列 
	if(T) EnQueue_L(Q,T);      //非空根指针入队列 
	struct BiTNode*p;
	p=(struct BiTNode*)malloc(sizeof(struct BiTNode));
	//while(!QueueEmpty){
	while(Q.front!=Q.rear){
		DeQueue_L(Q,p);
		if(!p) flag1=1;
		while(flag1==1){
			if(p) fflag=0;
		}
		//printf("%d\t",p->data);
		if(p->lChild || p->rChild) {
			EnQueue_L(Q,p->lChild);
			EnQueue_L(Q,p->rChild);
		}
		//free(p);
	}
	//free(p);
	DestroyQueue_L(Q);
	//if(flag>=2) fflag=0;
	*/
	if((countNodes(T)-NodeNumber(T,dep))!=pow(2,dep-1)-1) fflag=0;
	return fflag;
}

/* 
非完全二叉树 
6 4 2 3 -1 -1 -1 -1 5 1 -1 -1 7 -1 -1 
完全二叉树 
6 4 2 3 -1 -1 -1 6 -1 -1 5 1 -1 -1 7 -1 -1 
*/ 

