/****************************************************

Name:             huffman.h
Auther:            Hawkeye
Date:             2018.11.13
Function:  Huffman tree basic operation
			//����
			void HuffmanTree(HuffTree &HT, WeightType *w, int n);
			//�ӹ������� HT �����Ҷ�ӽڵ�Ĺ��������벢�������� HC �У�����ӡ��ÿ��Ҷ�ӽڵ��Ӧ�ı���
			void HuffmanCoding(HuffTree HT,char * * &HC,int n);
			//���������룬���ѱ�����ַ�����������룬 ����ʾ���
			void HuffmanDecoding(HuffTree HT�� int n);

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
//huffman ��
typedef struct {
	TElemType data;
	WeightType weight;                 //WeightType��Ȩֵ���� 
	int parent,lchild,rchild;          //˫�ס����ӡ��Һ��� 
}HTNode,*HuffmanTree;                  //huffman���ڵ����� 

typedef HTNode *HuffTree;              //���huffman���ľ�̬������������ 
const unsigned int MAX_WEIGHT = UINT_MAX;

void Select(HuffmanTree HT, int s, int &l, int &r) {
	// �������������Ǵ�HT[0..s]���ҵ�Ȩֵ��С���������
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
	int i , s1 , s2 , m = 2*n-1; // ���ս��õ�2n-1�����
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
	//���ݸ�����n��Ȩֵ������huffman����*w�Ǵ��n��Ȩֵ������
	int m,i,s1,s2;
	m = n * 2 - 1;                                //����huffman���������m
	HT = (HuffTree)malloc(sizeof(HTNode)*(m+1));  //����HT����ռ䣬0�ŵ�Ԫ���в��� 
	for(i=1;i<=m;i++){                            //��ʼ������HT[]
		HT[i].weight=i<=n?w[i]:0;
		HT[i].lchild=HT[i].rchild=HT[i].parent=0; 
	} 
	for(i=n+1;i<=m;i++){                          //��ѭ�������n-1�κϲ� 
		Select(HT,i,s1,s2);
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
		HT[s1].parent=HT[s2].parent=i;
	}
}

/****************************************************

             Stack.h�ļ�(˳��ջ)

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

                END Stack.h�ļ�
                  ���������� 

****************************************************/

void Coding(HuffTree HT,char * * HC,int root,Stack &S){
	//�������huffman��HT,���ÿ��Ҷ�ӽ��ı����ַ�������������HC
	//S��һ��˳��ջ��������¼����·��
	//root ��huffman������HT �и��ڵ��λ���±�
	char ch;
	if(root){
		if(!HT[root].lchild){
			push(S,'\0');
			HC[root]=(char *)malloc(S.stacksize);//������huffman�����ַ����Ŀռ�
			strcpy(HC[root],S.elem);             //����Ҷ�ӵı���
			pop(S,ch);                           //�ַ���������־��\0����ջ 
		}
		push(S,'0');                             //��ת����0����ջ
		Coding(HT,HC,HT[root].lchild,S);         //����������
		pop(S,ch);
		push(S,'1');                             //��ת����1����ջ 
		Coding(HT,HC,HT[root].rchild,S);         //����������
		pop(S,ch);
	}
}

void HuffmanCoding(HuffTree HT,char * * &HC,int n){
	//��huffman�������n��Ҷ�ӽ���huffman���벢��������HC��
	Stack S;                                      //S��һ���ַ��͵�˳��ջ
	InitStack(S);                                 //��ʼ��ջS 
	HC=(char * *)malloc(sizeof(char *)*(n+1));    //��������HC�Ŀռ�
	Coding(HT,HC,2*n-1,S);                        //huffman��������±�Ϊ2n-1 
}

//void HuffmanDecoding(HuffTree HT�� int n){}
/*Huffman���뺯�� 
*HT:Huffman����w[]:Ȩֵ����(���±�0��ʼ)��code[]:Ҫ����Ĵ� 

void HuffmanDecode(HuffmanTree HT, int w[], char code[])  
{
	char *ch = code;
	int i,k; 
	k = 0;
	int m = n * 2 - 1;                                //����huffman���������m
	while( *ch != '\0' ){
		//����һ�����ÿ�ζ�������m��ʼ  
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
