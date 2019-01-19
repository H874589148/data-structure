/****************************************************

Name:           BiTreeMirror.cpp
Auther:            Hawkeye
Date:             2018.11.12
Function:      Binary tree mirror
             test data (preorder) :
             
			  input : 8 6 5 -1 -1 7 -1 -1 10 9 -1 -1 11 -1 -1
			 
			 output : 8 10 11 -1 -1 9 -1 -1 6 7 -1 -1 5 -1 -1
			 ("-1"means nil)

****************************************************/

#include"BinaryTree.h"

int main(){
	BiTree T;
	createBiTree(T);
	writeBiTree(T);
	printf("\n\nThe Binary Tree before mirror's preorder is ---\n");
	preOrder(T);
	Mirror(T);
	printf("\n\nThe Binary Tree  after mirror's preorder is ---\n");
	preOrder(T);
	return 0;
}
