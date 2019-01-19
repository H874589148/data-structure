/****************************************************

Name:            BinaryTree.h
Auther:            Hawkeye
Date:            2018.10.29
Function:   Binary tree basic operation
            
            void createBiTree(BiTree &T); //����������
			void preOrder(BiTree T);      //�������
			void inOrder(BiTree T);       //�������
			void postOrder(BiTree T);     //�������
			void levelTraversal(BiTree T);//�������
			int depth(BiTree T);          //���������
			int countNodes(BiTree T);     //���������ڵ���

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

void CreateQueue_L(LinkQueue &Q)     //�������� 
{ 
	Q.front=Q.rear=new LNode;
	Q.front->next=NULL;              //ָ����Ϊ�� 
}
void DestroyQueue_L(LinkQueue &Q)    //���ٶ��� 
{
	while(Q.front)
	{
		Q.rear=Q.front->next;
		delete Q.front;              //�ͷ�ָ��ռ� 
		Q.front=Q.rear;
	}
}

void EnQueue_L(LinkQueue &Q,BiTree e)//����� 
{
	LNode *p;
	p=new LNode;
	p->tree=e;
	p->next=NULL;
	Q.rear->next=p;
	if(Q.front==Q.rear) Q.front->next=p;
	Q.rear=p;
}

bool DeQueue_L(LinkQueue &Q,BiTree &e)//������ 
{
	LNode *p;
	if(Q.front==Q.rear) return false;
	p=Q.front->next;
	Q.front->next=p->next;
	e=p->tree;
	if(Q.rear==p)
	Q.rear=Q.front;
	delete p;                         //�ͷ�ָ��ռ� 
	return true;
}

bool QueueEmpty(LinkQueue Q){         //�ж϶����Ƿ�Ϊ�գ��Ƿ���true ���񷵻�false 
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

void CreateStack_sq(SqStack &S)                           //��ʼ��ջ 
{
	int msize=STACK_INIT_SIZE;
	S.tree=(BiTree*)malloc(sizeof(BiTree)*msize);
	//S.tree=NULL;
	S.stacksize=msize;
	S.top=-1;
}

void DestroyStack_sq(SqStack &S)                          //����ջ 
{
	free(S.tree);
	S.top=-1;
	S.stacksize=0;
}

void Push_sq(SqStack &S,BiTree e)                         //��ջ 
{
   S.tree[++S.top]=e;	
}

bool Pop_sq(SqStack &S,BiTree &e)                         //��ջ 
{
	if(S.top==-1) return false;
	e=S.tree[S.top--];
	return true;
}

bool StackEmpty_sq(SqStack &S)                           //�ж�ջ�Ƿ�Ϊ�� 
{
	if(S.top==-1) return true;
	else return false;
}

/****************************************************************************

                            !  Begin  !

****************************************************************************/

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

void preOrder(BiTree T){       //�������
	if(!T) return;             //����ֱ�ӷ��� 
	else{
		printf("%d\t",T->data);//���ʸ��ڵ� 
		preOrder(T->lChild);   //������������� 
		preOrder(T->rChild);   //������������� 
	}
}

void inOrder(BiTree T){        //�������
	if(!T) return;             //�ն��������ղ��� 
	else{
		inOrder(T->lChild);    //������������� 
		printf("%d\t",T->data);//���ʸ��ڵ� 
		inOrder(T->rChild);    //������������� 
	}
}

void postOrder(BiTree T){      //�������
	if(!T) return;             //�ն��������ղ��� 
	else{
		postOrder(T->lChild);  //������������� 
		postOrder(T->rChild);  //������������� 
		printf("%d\t",T->data);//���ʸ��ڵ�
	}
}

void levelTraversal(BiTree T){ //�������
	LinkQueue Q;
	CreateQueue_L(Q);          //��ʼ��һ���ն��� 
	if(T) EnQueue_L(Q,T);      //�ǿո�ָ������� 
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

int depth(BiTree T){           //���������
	int hl,hr;
	if(!T)
		return 0;              //�ն��������Ϊ0 
	else{
		hl=depth(T->lChild);   //������������� 
		hr=depth(T->rChild);   //������������� 
		return(hl>hr?hl+1:hr+1);
	}
}

int countNodes(BiTree T){        //���������ڵ���
	int nl,nr;
	if(!T) return 0;
	else{
		nl=countNodes(T->lChild);//ͳ�������� 
		nr=countNodes(T->rChild);//ͳ�������� 
	}
	return (1+nl+nr);
}

                             //�ڶ��� 
/****************************************************************************

                            !  Begin  !
                              �ǵݹ� 
                void SpreOrder(BiTree T);  //�ǵݹ��������
				void SinOrder(BiTree T);   //�ǵݹ��������
				void SpostOrder(BiTree T); //�ǵݹ�������

****************************************************************************/

void SpreOrder(BiTree T){                        //��������������ķǵݹ��㷨�� T �Ƕ������ĸ�ָ�� 
	SqStack S;
	CreateStack_sq(S);                           //��ʼ��һ����ջ
	while(T || !StackEmpty_sq(S)){               //����������������ջΪ���� T Ϊ�� 
		while(T){
			printf("%d\t",T->data);              //����ָ�� T ָ��Ľ�� 
			Push_sq(S,T);                        // T ��ջ 
			T=T->lChild;                         //����ת���������� T �������� 
		}
		if(!StackEmpty_sq(S)){
			//printf("%d",T->data);              //����ָ�� T ָ��Ľ�� 
			Pop_sq(S,T);                         //����ջ��ָ�� T 
			T=T->rChild;                         //����ת���������� T �������� 
		}
		//printf("0");
	}
	DestroyStack_sq(S);                          //����ջ 
}

void SinOrder(BiTree T){                         //��������������ķǵݹ��㷨�� T �Ƕ������ĸ�ָ��
	SqStack S;
	CreateStack_sq(S);                           //��ʼ��һ����ջ
	while(T || !StackEmpty_sq(S)){               //����������������ջΪ���� T Ϊ�� 
		while(T){
			Push_sq(S,T);                        // T ��ջ 
			T=T->lChild;                         //����ת���������� T �������� 
		}
		if(!StackEmpty_sq(S)){
			Pop_sq(S,T);                         //����ջ��ָ�� T 
			printf("%d\t",T->data);              //����ָ�� T ָ��Ľ�� 
			T=T->rChild;                         //����ת���������� T �������� 
		}
	}
	DestroyStack_sq(S);                          //����ջ 
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

void SpostOrder(BiTree T)                        //��������������ķǵݹ��㷨�� T �Ƕ������ĸ�ָ��
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
	CreateStack_sq(S);                           //��ʼ��һ����ջ
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
/*	while(T || !StackEmpty_sq(S)){               //����������������ջΪ���� T Ϊ�� 
		while(T){
			Push_sq(S,T);                        // T ��ջ 
			while(T->lChild || T->rChild){
				Push_sq(S,T);
			}
			T=T->lChild;                         //����ת���������� T �������� 
			printf("%d\t",T->data);              //����ָ�� T ָ��Ľ��
			if(flag>0) {
				Pop_sq(S,T);
				printf("%d\t",T->data);
				flag--;
			}
		}
		if(!StackEmpty_sq(S)){
			Pop_sq(S,T);                         //����ջ��ָ�� T
			T=T->rChild;                         //����ת���������� T �������� 
			flag++;
			//Pop_sq(S,T);
			//printf("%d\t",T->data);
		}
	}
	DestroyStack_sq(S);                          //����ջ 
}*/

int NodeNumber(BiTree T,int lev){                //���õݹ�ķ�ʽ���������� lev ��ڵ�ĸ���
	//lev--;                                     //���ڵ�Ϊ��һ�� 
	//int count=0;
	if(!T || lev<0) 
		return 0;                                //��Ϊ������ lev ���Ϸ����򷵻� 0 
	/*else if(!lev)
		count++;                                 //��ǰ�ڵ���� 
	else{
		count+=NodeNumber(T->lChild,lev-1);      //���������¼��� 
		count+=NodeNumber(T->rChild,lev-1);      //���������¼��� 
	}
	return count;
	*/
	if(lev==1) return 1;
	int nl,nr;
	nl=NodeNumber(T->lChild,lev-1);              //���������¼��� 
	nr=NodeNumber(T->rChild,lev-1);              //���������¼��� 
	return (nl+nr);
}

int JudgeCompleteTree(BiTree T){
	int i,dep,flag1=0,flag2=0,fflag=1;
	dep=depth(T);
	for(i=1;i<dep;i++){
		if(NodeNumber(T,i)!=pow(2,i-1)) fflag=0;
	}
	/*LinkQueue Q;
	CreateQueue_L(Q);          //��ʼ��һ���ն��� 
	if(T) EnQueue_L(Q,T);      //�ǿո�ָ������� 
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
����ȫ������ 
6 4 2 3 -1 -1 -1 -1 5 1 -1 -1 7 -1 -1 
��ȫ������ 
6 4 2 3 -1 -1 -1 6 -1 -1 5 1 -1 -1 7 -1 -1 
*/ 

