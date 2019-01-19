#include<stdio.h>
#define MAX_SIZE 1000
#define MAXM 100
int rpos[MAXM];
typedef struct{
	int i,j;
	int e;
}Triple; 
typedef struct{
	Triple data[MAX_SIZE];
	int mu,nu,tu;    //对应矩阵的行、列和非零元的个数 
}TSMatrix;
int main()
{
	void createrpos(TSMatrix M); 
	void TRansposeTS(TSMatrix M,TSMatrix &T);
	int a[6][7]={{0,12,9,0,0,0,0},{0,0,0,0,0,0,0},{3,0,0,0,0,14,0},{0,0,24,0,0,0,0},{0,18,0,0,0,0,0},{15,0,0,7,0,0,0}};
	int i,j,t=0;
	int b[7][6];
	TSMatrix M,T;
	M.tu=0;M.mu=6;M.nu=7;
	for(i=0;i<6;i++)
	  for(j=0;j<7;j++)
	    if(a[i][j])
	    {
	    	M.tu++;
	    	M.data[t].i=i;
	    	M.data[t].j=j;
	    	M.data[t].e=a[i][j];
	    	t++;
		}
	printf("\nMatrix before change is：\n");
	for(i=0;i<6;i++) 
	{
		for(j=0;j<7;j++)
		 printf("%-3d",a[i][j]);
		 putchar('\n');
	}
	printf("\n\nThree group before change is ：\n");
	for(i=0;i<M.tu;i++)
	 printf("%-3d",M.data[i].e);
	TRansposeTS(M,T);
	putchar('\n');
	printf("\n\nThree group after change T is：\n");
	for(i=0;i<T.tu;i++)
	 printf("%-3d",T.data[i].e);
    for(i=0;i<T.tu;i++)
	  b[T.data[i].i][T.data[i].j]=T.data[i].e;
	  putchar('\n');
	printf("\n\nMatrix after change is：\n");
	for(i=0;i<7;i++) 
	{
		for(j=0;j<6;j++)
		 printf("%-3d",b[i][j]);
		 putchar('\n');
	}	
    return 0;	
}
void createrpos(TSMatrix M)
{
int col,t;
int num[MAXM];
for(col=0;col<M.nu;col++) num[col]=0;
for(t=0;t<M.tu;t++)
++num[M.data[t].j];
rpos[0]=0;
for(col=1;col<M.nu;col++)
   rpos[col]=rpos[col-1]+num[col-1];
}
void TRansposeTS(TSMatrix M,TSMatrix &T)
{
	int p,q,col;
	T.mu=M.nu;T.nu=M.mu;T.tu=M.tu;
	if(!M.tu) return;
	createrpos(M);
	for(p=0;p<M.tu;p++)
	{
		col=M.data[p].j;
		q=rpos[col];
		T.data[q].i=M.data[p].j;
		T.data[q].j=M.data[p].i;
		T.data[q].e=M.data[p].e;
		++rpos[col];
	}
}
