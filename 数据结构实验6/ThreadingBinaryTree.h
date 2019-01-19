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
	TElemType data;                         //������ 
	BiThrNode *lchild, *rchild;             //����ָ���� 
	bool ltag, rtag;                        //���ұ�־�� 
}BiThrNode,*BiThrTree;

/*
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
}*/

void createBiThrTree(BiThrTree &T){                               //����������
	T=(struct BiThrNode*)malloc(sizeof(struct BiThrNode));
	T->lchild=(struct BiThrNode*)malloc(sizeof(struct BiThrNode));//Ϊ����֧��ָ������ռ�
	T->rchild=(struct BiThrNode*)malloc(sizeof(struct BiThrNode));
	T->lchild=T->rchild=NULL;                                     //����֧��ָ���ʼ�� 
	T->ltag=false;
	T->rtag=false;
}

void writeBiThrTree(BiThrTree &T){          //��������Զ��������и�ֵ 
	char treetype;
	printf("\nPlease type in the next node( '#' present nil node)\n");
	//scanf("%c",&treetype);
	treetype=getchar();                     //����dataԪ�أ�#�������
	printf("\ndata is - %c\n",treetype);
	if(treetype=='#')                       //����dataԪ�أ�#�������
		T=NULL;                             //����һ���ն�����
	else{                                   //�� T ���ڣ������������������
		T->data=treetype;                   //typetree��ֵ��data
		createBiThrTree(T->lchild);         //����һ���ڵ�
		writeBiThrTree(T->lchild);          //������������������и�ֵ 
		createBiThrTree(T->rchild);         //����һ���ڵ�
		writeBiThrTree(T->rchild);          //������������������и�ֵ
	}
	//treetype='#';
	return;
}

void preOrder(BiThrTree T){                 //�������
	if(!T) return;                          //����ֱ�ӷ��� 
	else{
		printf("%c\t",T->data);             //���ʸ��ڵ� 
		preOrder(T->lchild);                //������������� 
		preOrder(T->rchild);                //������������� 
	}
}

/*void inOrder(BiThrTree T){                  //�������
	if(!T) return;                          //�ն��������ղ��� 
	else{
		inOrder(T->lchild);                 //������������� 
		printf("%c\t",T->data);             //���ʸ��ڵ� 
		inOrder(T->rchild);                 //������������� 
	}
}*/

BiThrTree pre = NULL;                       //pre ��ȫ�ֱ��� 
void InThreading(BiThrTree T) {             //���������������� T ���� T ��ÿ���ڵ��ltag ��rtag �ĳ�ֵ�� 0 
	if (!T) return;
	InThreading(T->lchild);                 //���������������� T �������� 
	if (!T->lchild) {
		T->ltag = true; T->lchild = pre;    //��д T �����־�������� 
	}
	if (pre && !pre->rchild) {
		pre->rtag = true; pre->rchild = T;  //��д pre ���ұ�־�������� 
	}
	pre = T;                                //���� pre ָ�� T ������ǰ�� 
	InThreading(T->rchild);                 //���������������� T ��������
}

BiThrTree GetNext(BiThrTree p) {            //�����������������Ͻ�� *p ��ֱ�Ӻ��ָ�� 
	if (p->rtag) return p->rchild;          //ֱ�ӷ��� p �������� 
	BiThrTree q = p->rchild;                //�����ָ�� q ָ�� p ������������ 
	if(q)
	while (!(q->ltag)) q = q->lchild;       //�����������¡���� 
	return q;                               //���� p �������������½��ָ�� 
}

void Visit(TElemType ele){
	printf("%c\t",ele);
}

void InOrderTraverse(BiThrTree T) {
//void InOrderTraverse(BiThrTree T, void (*Visit)(TElemType)) {
	//��������������������������� 
	if (T) {
		BiThrTree p = T;
		while (!p->ltag) p = p->lchild;     //���������еĵ�һ����� 
		do {
			printf("%c\t",p->data);
			//Visit(p->data);               //���� p; 
			p = GetNext(p);                 //p ���������� 
		} while (p);
	}
}

bool IsInTree(BiThrTree T, BiThrTree R){    //����������ҽ�� R �Ƿ��ڶ����� T ��
	if(!T) return false;                    //����ֱ�ӷ���
	while(T){
		if(T->data == R->data) return true; //���ʸ��ڵ�
		else return( IsInTree(T->lchild,R) || IsInTree(T->rchild,R) ); 
	}
}

BiThrTree search(BiThrTree T, char ele){    //����������,����ele,���ظýڵ��ָ��
	BiThrTree R;
	if(!T) return NULL;                     //����ֱ�ӷ��� 
	else{
		if(T->data == ele) return T;        //���ʸ��ڵ� 
		R=search(T->lchild,ele);            //���������� 
		if(R) return R;
		R=search(T->rchild,ele);            //���������� 
		if(R) return R;
	}
}

void FindParent(BiThrTree T,BiThrTree R,BiThrTree &S){//�ҵ�ĳ���ڵ��˫�� 
	/*if (T) {
		BiThrTree p = T;
		while (!p->ltag) p = p->lchild;     //���������еĵ�һ����� 
		do {
			if(p->lchild == R || p->rchild == R) return p;
			p = GetNext(p);                 //p ���������� 
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
		FindParent(T->lchild,R,S);                 //������������� 
		FindParent(T->rchild,R,S);
	}
}

BiThrTree GetLastParent(BiThrTree pRoot, BiThrTree P1, BiThrTree P2){
	//��������������ڵ����͹������Ƚڵ�
	BiThrTree R;
	createBiThrTree(R);
	FindParent(pRoot,P1,R);
	while(!IsInTree(R,P2)){
		FindParent(pRoot,R,R);
	}
	return R;
}
