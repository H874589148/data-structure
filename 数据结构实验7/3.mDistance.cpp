/****************************************************

Name:           MaxDistance.cpp 
Auther:            Hawkeye
Date:             2018.11.12
Function:  In binary tree calculate longest distance
             test data (preorder) :
             6 4 2 3 # # # # 5 1 # # 7 # #
                        6
                      4  5
                    2 # 1 7
                  3  # ## ##
                # #
            6 4 2 3 -1 -1 -1 -1 5 1 -1 -1 7 -1 -1
			6423####51##7##
			output: 5

****************************************************/

#include"BinaryTree.h"

int main(){
	BiTree T;
	createBiTree(T);
	writeBiTree(T);
	printf("\n\nThe Binary Tree create just now's preorder is ---\n");
	preOrder(T);
	FindMaxlen(T);
	CalculateMaxlen(T);
	printf("\n\nThe longest distance in Binary Tree is %d.",nMaxlen);
	return 0;
}
