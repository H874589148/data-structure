//6423####51##7##;

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
typedef struct Node {
    struct Node *pleft;     //����
    struct Node *pright;    //�Һ���
    char chValue;           //�ýڵ��ֵ
    int leftMaxValue;       //�����������
    int rightMaxValue;      //�����������
}LNode, *BinTree;

void findMaxLen(BinTree root, int *maxLen) {
    //������Ҷ�ӽ�㣬����
    if(root == NULL)
        return;
    //���������Ϊ�գ���ô�ýڵ���������Ϊ0
    if(root->pleft == NULL)
        root->leftMaxValue = 0;
    //���������Ϊ�գ���ô�ýڵ��ұ������Ϊ0
    if(root->pright == NULL)
        root->rightMaxValue = 0;
    //�����������Ϊ�գ��ݹ�Ѱ�������������
    if(root->pleft != NULL)
        findMaxLen(root->pleft, maxLen);
    //�����������Ϊ�գ��ݹ�Ѱ�������������
    if(root->pright != NULL)
        findMaxLen(root->pright, maxLen);
    //�����������о�����ڵ�������
    if(root->pleft != NULL) {
        if(root->pleft->leftMaxValue > root->pleft->rightMaxValue)
            root->leftMaxValue = root->pleft->leftMaxValue + 1;
        else
            root->leftMaxValue = root->pleft->rightMaxValue + 1;
    }
    //�����������о�����ڵ�������
    if(root->pright != NULL) {
        if(root->pright->leftMaxValue > root->pright->rightMaxValue)
            root->rightMaxValue = root->pright->leftMaxValue + 1;
        else
            root->rightMaxValue = root->pright->rightMaxValue + 1;
    }
    //���������
    if(root->leftMaxValue + root->rightMaxValue > *maxLen)
        *maxLen = root->leftMaxValue + root->rightMaxValue;
}
//����������
void buildBinTree(BinTree *root)
{
    char ch;
    scanf("%c", &ch);    //����һ��Ԫ��
    //fpurge(stdin);
    if(ch == '#')        //��������ǿո��������������Ϊ�գ���*rootΪNULL
        *root = NULL;
    else {               //������Ĳ��ǿո�����򽫸�ֵ��ֵ�����ڵ��chValue, �ݹ齨����������������
        *root = (BinTree)malloc(sizeof(LNode));
        (*root)->chValue = ch;
        (*root)->leftMaxValue = 0;
        (*root)->rightMaxValue = 0;
        buildBinTree(&(*root)->pleft);
		buildBinTree(&(*root)->pright);
    }
}
//���ٶ��������ͷ��ڴ�
void destroyBinTree(BinTree *root)
{
    if(*root != NULL) {
        destroyBinTree(&(*root)->pleft);
        destroyBinTree(&(*root)->pright);
        free(*root);
        *root = NULL;
    }
} 
//ǰ�����������
void preOrderTraverse(BinTree root)
{
    if(root != NULL) {
        preOrderTraverse(root->pleft);
        printf("%c\t", root->chValue);
        preOrderTraverse(root->pright);
    }
}
int main() {
    BinTree root;
    printf("\nPlease type in a binary tree ( '#' present nil node)\n");
    buildBinTree(&root);
    printf("\n\nThe Binary Tree create just now's preorder is ---\n");
    preOrderTraverse(root);
    printf("\n");
    int maxLen = 0;
    findMaxLen(root, &maxLen);
    printf("\n\nmaxLen = %d\n", maxLen);
    destroyBinTree(&root);
}
