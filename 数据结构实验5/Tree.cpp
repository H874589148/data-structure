/****************************************************

Name:              Tree.cpp 
Auther:            Hawkeye
Date:            2018.10.30
Function:  1.Binary tree basic operation
             test data (preorder) :
             6 4 2 3 # # # # 5 1 # # 7 # #
                        6
                      4  5
                    2 # 1 7
                  3  # ## ##
                # #
            6 4 2 3 -1 -1 -1 -1 5 1 -1 -1 7 -1 -1
            
           2. 采用非递归的方法求出树的先序、中序、后序遍历。
                   void preOrder(BiTree T); //先序遍历
                   void inOrder(BiTree T); //中序遍历
                   void postOrder(BiTree T); //后序遍历

           3. 利用递归的方式求解二叉树第 K 层节点的个数
                   int GetNumBitree(BiTNode* T,int k)

           4.（附加题） 判断二叉树是否为完全二叉树。

            若设二叉树的深度为 h，除第 h 层外，其它各层 (1～h-1) 的结点数都达到最大个数，
		    第 h 层所有的结点都连续集中在最左边，这就是完全二叉树。
            test data: (preorder , # present nil node)
              a) 非完全二叉树： 6 4 2 3 # # # # 5 1 # # 7 # #
              b) 完全二叉树： 6 4 2 3 # # # 6# # 5 1 # # 7 # #

****************************************************/

#include"BinaryTree.h"

int main(){
	BiTree T;
	int lev;
	createBiTree(T);
	writeBiTree(T);
	printf("\n\nThe Binary Tree create just now's  preorder is ---\n");
	preOrder(T);
	printf("\n\nThe Binary Tree create just now's  inorder  is ---\n");
	inOrder(T);
	printf("\n\nThe Binary Tree create just now's postorder is ---\n");
	postOrder(T);
	printf("\n\nThe Binary Tree create just now's lev-order is ---\n");
	levelTraversal(T);
	printf("\n\nThe Binary Tree create just now's  <depth>  is --- %d .\n",depth(T));
	printf("\nThe Binary Tree create just now have %d node .",countNodes(T));
	printf("\n\nThe Binary Tree create just now's  preorder is (not recursion)---\n");
	SpreOrder(T);
	printf("\n\nThe Binary Tree create just now's  inorder  is (not recursion)---\n");
	SinOrder(T);
	printf("\n\nThe Binary Tree create just now's postorder is (not recursion)---\n");
	SpostOrder(T);
	printf("\n\nPlease input the level:\n");
	scanf("%d",&lev);
	if(lev<=0 || lev>4) printf("Error!");
	printf("\nThe number of node of the %d lines is %d .\n",lev,NodeNumber(T,lev));
	
	if(JudgeCompleteTree(T)==1) printf("Yes!");
	else printf("No!");
	return 0;
}
