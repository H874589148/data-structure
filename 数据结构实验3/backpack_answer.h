/****************************************************

Name:            backpack_answer.h
Auther:            Hawkeye
Date:           2018.10.18
Function:    void Knapsack(int w[],int T,int n) ,
             complete backpack' answer
             test data :
			 w[6] = {2,8,6,5,1,4};T=11;n=6;

****************************************************/

//#include"Stack.h"

void Knapsack(int w[],int T,int n){
	//体积为 T 的背包和 n 个体积分别为 w[0],w[1], ...... ,w[n-1] 的物品，
	//任意从 n个物品中抽取 k 个，使得其体积之和恰好为 T ,输出所有可能的解。
	//在算法中， T 表示背包装入物品后剩余的容积
	Stack S;
	char c;
	S=CreatStack_sq(S);
	int k=0;
	do{
		while(T>0&&k<n){
			if(T-w[k]>=0){
				Push_sq(S,k);
			}
			k++;
		}
		if(T==0)
		c=StackTraverse_sq(S);
		c=StackEmpty_sq(S);
		if(!c){
			c=Pop_sq(S,k);
			T+=w[k];
			k++;
		}
	}while(!StackEmpty_sq(S)||k!=n);
	DestoryStack_sq(S);
}
