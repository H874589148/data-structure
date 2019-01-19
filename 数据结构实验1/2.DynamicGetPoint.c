/****************************************************

Name:             DynamicGetPoint.c
Auther:            Hawkeye
Date:           2018.9.25
Function:    calculate the special point of a square matrix
             special point is a point which is the maximum in row;the smallest in column;
             a matrix may non-existent
Edition:     GetPoint.c - 2.0
History:     Dynamic
Rewrite:     add dynamic array so can find out special point for any kind of matrix
             dynamic distribute array space
Review:       *(a+i*column+j)
              row    ��
			  column �� 
test:
1 2 3 4 5 6 7 8 9 0
1 2 3 4 5 6 7 8 9 0

1 2 3 4 5 6 7 8 9 10
11 12 13 14 15 16 17 18 19 20

5 4 3 2 1 4 5 3 2 1
2 3 4 5 6 6 7 8 9 0

****************************************************/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void GetPoint(int *a,int row,int column);
int Judgeminimum(int *a,int row,int column,int m,int i);
int FindMost(int *a,int column,int r);

void main(){
	int row,column,/*b[4][5],*/i,j,**a;
	/*int *a;
	a=&b[0][0];*/
	printf("Please input the Matrix row-----\n");
	scanf("%d",&row);
	printf("Please input the Matrix column-----\n");
	scanf("%d",&column);
	a=(int **)malloc(row*sizeof(int *));
	if(a==NULL){
		printf("save wrong!");exit(1);
	}
	for(i=0;i<row;i++){
		a[i]=(int **)malloc(column*sizeof(int *));
		if(a==NULL){
			printf("save wrong!");exit(1);
		}
	}
	 
//	a=b;
//	printf("Please input the area of Matrix-----\n");
//	scanf("%d%d",row,column);
	printf("Please input a %d*%d Matrix-----\n",row,column);
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			scanf("%d",&*(a+i*column+j));
		}
	}
	printf("The Matrix you typed in is-----\n");
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			printf("%3d %c",*(a+i*column+j),j+1-column?' ':'\n');
		}
	} 
	GetPoint(a,row,column);
	free(*a);
} 

int FindMost(int *a,int column,int r){   //������󣬾����������Լ����ǵڼ��У���ӡ���������ֵ�Լ����ֵ�ľ������� 
                                         //����ֵ������ 
	int m,n=0,i;
	m=*(a+r*column+0);
//		printf("2");

	for(i=1;i<column;i++){
		if(*(a+r*column+i)>m) {
		m=*(a+r*column+i);
		n=i;
		}
	}
	printf("%d%d\n",m,n);
	return(n);
}

int Judgeminimum(int *a,int row,int column,int m,int i){      //��������������������������� 
                                                              //�жϸ��е����ֵ�Ƿ�Ϊ���е���Сֵ 
	int j,judge=1,t;
	t=*(a+i*column+m);
	printf("\n%d\n",i);                                       //��ӡ���� 
	for(j=0;j<row;j++){
		//m+=(j-i)*column;
		printf("\t%d\t",*(a+j*column+m));
		if(t>*(a+j*column+m)){
			judge=0;
		}
	}
	//printf("judge=%d",judge); 
	return(judge);
}

void GetPoint(int *a,int row,int column){   //��һ��������ά�����еİ��㣬����λ���ϵ�Ԫ���ڸ���������ڸ�������С
                                           //����Ҳ����û�а��㣡�����βηֱ���������ַ��������������
	int m[15],i,hurui=0;
	for(i=0;i<row;i++){
//		printf("1");
		m[i]=FindMost(a,column,i); 
		printf("win");
		printf("%d\n",m[i]);
	}
	for(i=0;i<row;i++){
		if(Judgeminimum(a,row,column,m[i],i)){
			printf("\n\nSpecial point in row %d column %d.\n\nThe number is %d\n\n",i+1,m[i]+1,*(a+i*column+m[i]));
			hurui++;
		}
	}
	if(!hurui) printf("\nNot exist!");
}
