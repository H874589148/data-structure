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
	//���Ϊ T �ı����� n ������ֱ�Ϊ w[0],w[1], ...... ,w[n-1] ����Ʒ��
	//����� n����Ʒ�г�ȡ k ����ʹ�������֮��ǡ��Ϊ T ,������п��ܵĽ⡣
	//���㷨�У� T ��ʾ����װ����Ʒ��ʣ����ݻ�
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
