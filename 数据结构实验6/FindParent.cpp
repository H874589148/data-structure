/****************************************************

Name:           FindParent.cpp 
Auther:            Hawkeye
Date:             2018.11.4
Function:    test data (preorder) :
             6 4 2 3 # # # # 5 1 # # 7 # #
                        6
                      4  5
                    2 # 1 7
                  3  # ## ##
                # #
            6 4 2 3 -1 -1 -1 -1 5 1 -1 -1 7 -1 -1 
			6423####51##7##

****************************************************/

#include"ThreadingBinaryTree.h"

int main(){
	BiThrTree T,R,P1,P2,T1,T2,S;
	char ele;
	bool judge;
	createBiThrTree(T);
	writeBiThrTree(T);
	printf("\n\nThe Binary Tree create just now's  preorder is ---\n");
	preOrder(T);                                 //先序打印 
	//InThreading(T);                            //中序线索化 
	printf("\n\nPlease input the element you want to search ---\n");
	fflush(stdin);
	ele=getchar();
	fflush(stdin);
	putchar(ele);
	createBiThrTree(R);
	//writeBiThrTree(R);
	R->data=ele;
	R->lchild=R->rchild=NULL;
	//end writeBiThrTree
	judge=IsInTree(T,R);
	if(judge)
	{
		createBiThrTree(T1);
		//createBiThrTree(T2);
		FindParent(T,R,T1);
		printf("\nExist!\nits parent is %c\n",T1->data);
	}
	else printf("\nNot exist!");
	printf("\nPlease input P1 ---\n");
	fflush(stdin);
	ele=getchar();
	P1=search(T,ele);
	printf("\nP1=%c\n",P1->data);
	printf("\nPlease input P2 ---\n");
	fflush(stdin);
	ele=getchar();
	fflush(stdin);
	P2=search(T,ele);
	printf("\nP2=%c\n",P2->data);
	S=GetLastParent(T,P1,P2);
	printf("\nCommon parent is %c",S->data);
	return 0;
}
