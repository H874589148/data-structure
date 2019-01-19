/****************************************************

Name:             huffman.h
Auther:            Hawkeye
Date:             2018.11.13
Function:  Huffman tree basic operation
			//建树
			void HuffmanTree(HuffTree &HT, WeightType *w, int n);
			//从哈夫曼树 HT 上求得叶子节点的哈夫曼编码并存入数组 HC 中，并打印出每个叶子节点对应的编码
			void HuffmanCoding(HuffTree HT,char * * &HC,int n);
			//哈夫曼译码，对已编码的字符数组进行译码， 并显示结果
			void HuffmanDecoding(HuffTree HT， int n);

****************************************************/

#define UINT_MAX 100
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define STACK_INIT_SIZE 100 
#include<iostream>
using namespace std;

typedef unsigned int WeightType;
typedef char TElemType;
//huffman 树
typedef struct {
	TElemType data;
	WeightType weight;                 //WeightType是权值类型 
	int parent,lchild,rchild;          //双亲、左孩子、右孩子 
}HTNode,*HuffmanTree;                  //huffman树节点类型 

typedef HTNode *HuffTree;              //存放huffman树的静态三叉链表类型 
const unsigned int MAX_WEIGHT = UINT_MAX;

void Select(HuffmanTree HT, int s, int &l, int &r) {
	// 本函数的作用是从HT[0..s]中找到权值最小的两个结点
	int i;
	WeightType WL = MAX_WEIGHT, WR = MAX_WEIGHT;
	for (i=1; i<=s-1 ; ++i) {
		if (HT[i].parent == 0) {
			if (HT[i].weight < WL) {
				WR = WL;
				WL = HT[i].weight;
				r=l; l=i;
			}
			else if (HT[i].weight < WR) {
				WR = HT[i].weight;
				r=i;
			}
		}
	}
}

void CreateHuffmanTree(HuffmanTree &HT, int n) {
	int i , s1 , s2 , m = 2*n-1; // 最终将得到2n-1个结点
	HT = new HTNode[m];
	for (i=0; i<n; ++i) {
		cin >> HT[i].data >> HT[i].weight;
		HT[i].lchild = HT[i].rchild = HT[i].parent = -1;
	}
	for (i=n; i<m; ++i) {
		Select(HT, i-1, s1, s2); HT[s1].parent=HT[s2].parent=i;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
		HT[i].lchild=s1; HT[i].rchild=s2; HT[i].parent = -1;
	}
}

void SetHuffmanTree(HuffmanTree &HT,WeightType *w,int n){
	//根据给定的n个权值，构造huffman树。*w是存放n个权值的数组
	int m,i,s1,s2;
	m = n * 2 - 1;                                //计算huffman树结点总数m
	HT = (HuffTree)malloc(sizeof(HTNode)*(m+1));  //分配HT数组空间，0号单元空闲不用 
	for(i=1;i<=m;i++){                            //初始化数组HT[]
		HT[i].weight=i<=n?w[i]:0;
		HT[i].lchild=HT[i].rchild=HT[i].parent=0; 
	} 
	for(i=n+1;i<=m;i++){                          //主循环，完成n-1次合并 
		Select(HT,i,s1,s2);
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
		HT[s1].parent=HT[s2].parent=i;
	}
}

/****************************************************

             Stack.h文件(顺序栈)

****************************************************/

typedef char ElementType;
typedef struct{
	ElementType *elem;
	int stacksize;
	int top;
}Stack; 
void InitStack(Stack &S)
{
	int msize=STACK_INIT_SIZE;
	S.elem=(ElementType *)malloc(sizeof(char)*msize);
	S.stacksize=msize;
	S.top=-1;
}

void DestroyStack_sq(Stack &S)
{
	free(S.elem);
	S.top=-1;
	S.stacksize=0;
}

void push(Stack &S,ElementType e)
{
   S.elem[++S.top]=e;	
}

bool pop(Stack &S,ElementType &e)
{
	if(S.top==-1) return false;
	e=S.elem[S.top--];
	return true;
}

/****************************************************

                END Stack.h文件
                  哈夫曼编码 

****************************************************/

void Coding(HuffTree HT,char * * HC,int root,Stack &S){
	//先序遍历huffman树HT,求得每个叶子结点的编码字符串，存入数组HC
	//S是一个顺序栈，用来记录遍历路径
	//root 是huffman树数组HT 中根节点的位置下标
	char ch;
	if(root){
		if(!HT[root].lchild){
			push(S,'\0');
			HC[root]=(char *)malloc(S.stacksize);//分配存放huffman编码字符串的空间
			strcpy(HC[root],S.elem);             //复制叶子的编码
			pop(S,ch);                           //字符串结束标志‘\0’出栈 
		}
		push(S,'0');                             //左转，‘0’进栈
		Coding(HT,HC,HT[root].lchild,S);         //遍历左子树
		pop(S,ch);
		push(S,'1');                             //右转，‘1’进栈 
		Coding(HT,HC,HT[root].rchild,S);         //遍历右子树
		pop(S,ch);
	}
}

void HuffmanCoding(HuffTree HT,char * * &HC,int n){
	//从huffman树上求得n个叶子结点的huffman编码并存入数组HC中
	Stack S;                                      //S是一个字符型的顺序栈
	InitStack(S);                                 //初始化栈S 
	HC=(char * *)malloc(sizeof(char *)*(n+1));    //分配数组HC的空间
	Coding(HT,HC,2*n-1,S);                        //huffman树根结点下标为2n-1 
}

//void HuffmanDecoding(HuffTree HT， int n){}
/*Huffman解码函数 
*HT:Huffman树，w[]:权值数组(从下标0开始)，code[]:要解码的串 

void HuffmanDecode(HuffmanTree HT, int w[], char code[])  
{
	char *ch = code;
	int i,k; 
	k = 0;
	int m = n * 2 - 1;                                //计算huffman树结点总数m
	while( *ch != '\0' ){
		//解码一个结点每次都从树根m开始  
		for(i=m; HT[i].lchild !=0 && HT[i].rchild != 0;){  
			if( *ch == '0' )  
				i = HT[i].lchild;  
			else if( *ch == '1' )  
				i = HT[i].rchild;
				++ch;  
		}  
		hDecode[k] = i-1;
		k++;
	}
} */

void DeCode(HuffTree HT,int n,char *p){
	int i;
	int flag;
	i=2*n-1;
	char *q=p;
	while(*q!='\0'){
		if(*q=='0')
			i=HT[i].lchild;
		else if(*q=='1')
			i=HT[i].rchild;
/*		else{
			printf("\nOnly 0 or 1 is permited!\n");
			return ;
		}
*/		flag=0;
		if(!HT[i].lchild){
			printf("%c\t",'A'+i-1);
			i=2*n-1;
			flag=1;
		}
		++q;
	}
	printf("\n");
	if(!flag)
		printf("The code is not complete!\n");
	return ;
}
