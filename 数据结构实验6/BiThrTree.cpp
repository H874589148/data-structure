/****************************************************

Name:           BiThrTree.cpp 
Auther:            Hawkeye
Date:             2018.11.4
Function:  Thread binary tree basic operation
             test data (preorder) :
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
	BiThrTree T,R,P1,P2,S;
	char ele;
	bool judge;
	createBiThrTree(T);
	writeBiThrTree(T);
	printf("\n\nThe Binary Tree create just now's  preorder is ---\n");
	preOrder(T);                                 //先序打印 
	InThreading(T);                              //中序线索化 
	printf("\n\nThe Binary Tree create just now's  inorder  is ---\n");
	/*inOrder(T);                                //中序打印 
	printf("\n\nThreading Binary Tree - inorder ---\n");
	InOrderTraverse(T,*Visit);*/
	InOrderTraverse(T);
	/*printf("Please input the element you want to search ---\n");
	ele=getchar();
	createBiThrTree(R);
	//writeBiThrTree(R);
	R->data=ele;
	R->lchild=R->rchild=NULL;
	R->ltag=R->rtag=false;
	//end writeBiThrTree
	judge=IsInTree(T,R);
	if(judge) printf("Exist!");
	else printf("Not exist!");
	printf("Please input P1 ---\n");
	ele=getchar();
	P1=search(T,ele);
	printf("Please input P2 ---\n");
	ele=getchar();
	P2=search(T,ele);
	S=GetLastParent(T,P1,P2);
	*/
	return 0;
}
