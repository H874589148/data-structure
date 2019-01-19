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
            
           2. ���÷ǵݹ�ķ�����������������򡢺��������
                   void preOrder(BiTree T); //�������
                   void inOrder(BiTree T); //�������
                   void postOrder(BiTree T); //�������

           3. ���õݹ�ķ�ʽ���������� K ��ڵ�ĸ���
                   int GetNumBitree(BiTNode* T,int k)

           4.�������⣩ �ж϶������Ƿ�Ϊ��ȫ��������

            ��������������Ϊ h������ h ���⣬�������� (1��h-1) �Ľ�������ﵽ��������
		    �� h �����еĽ�㶼��������������ߣ��������ȫ��������
            test data: (preorder , # present nil node)
              a) ����ȫ�������� 6 4 2 3 # # # # 5 1 # # 7 # #
              b) ��ȫ�������� 6 4 2 3 # # # 6# # 5 1 # # 7 # #

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
