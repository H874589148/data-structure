/****************************************************

Name:            2.Dijkstra.cpp
Auther:            Hawkeye
Date:            2018.11.24
Function:   single source minimum way
		    Dijkstra algorithm
		    test data :
		    1 6 8
		    012345
		    12 5 02 10 04 30 05 100 23 50 43 20 45 60 35 10

****************************************************/

#include"Graph.h"

void Dijkstra(MGraph &G,int v0,int D[MAX_VERTEX_NUM],int P[][MAX_VERTEX_NUM]){
	int i,j,k=1,w,min;
	//带权图 G 用邻接矩阵表示 ， 求顶点 v0 到其余各顶点的最短路径
	//数组 D 存放各条最短路径的长度 
	//数组 P 存放各条最短路径的顶点序列 
	int S[MAX_VERTEX_NUM] = {0} ;        //定义并初始化辅助数组 S
	for(i=0;i<G.vexnum;i++){             //初始化 D 和 P 
		D[i]=G.arcs[v0][i];
		if(i==0 || i==1){
			P[i][0]=v0;
			P[i][1]=2;
			P[i][2]=i;
			P[i][3]=-1;                  //用 -1 作为路径结束的标志
		}
		if(D[i]!=INFINITY){
			P[i][0]=v0;
			P[i][1]=i;
			P[i][2]=-1;                  //用 -1 作为路径结束的标志
		}
	}
	S[v0]=1;                             //源点 v0 并入 S 集
	D[v0]=0;
	for(i=1;i<G.vexnum;i++){             //主循环，求 n-1 条最短路径
		min=INFINITY;
		for(j=0;j<G.vexnum;j++){         //在 V-S 中找最短路径 
			if(!S[j]&&D[j]<min){
				min=D[j];
				k=j;
			}
		}
		S[k]=1;
		for(j=0;j<G.vexnum;j++){
			if(!S[j]&&D[k]+G.arcs[k][j]<D[j]){
				D[j]=D[k]+G.arcs[k][j];
				for(w=0;P[k][w]!=-1;w++)
					P[j][w]=P[k][w];
				P[j][w]=j;
				P[j][w+1]=-1;
			}
		}
	}
}

int main(){
	MGraph G;
	int i,j,wkind,v0;
	char begin;
	printf("\nPlease input the kind of graph:\n0 --- DGraph\n1 --- DNet\n2 --- UDGraph\n3 --- UDNet\n");
	/*
	有向图0
	有向网1  有权值不对称 
	无向图2
	无向网3  有权值且对称 
	*/ 
	scanf("%d",&wkind);
	if(wkind!=0 && wkind!=1 && wkind!=2 && wkind!=3)
		printf("\nError!\n");
	if(wkind==0){
		G.kind=wkind;
		printf("Direction Graph\n");
		CreateD(G,wkind);
	}
	if(wkind==1){
		G.kind=wkind;
		printf("Direction Net\n");
		CreateD(G,wkind);
	}
	if(wkind==2){
		G.kind=wkind;
		CreateUD(G,wkind);
		printf("No Direction Graph\n");
	}
	if(wkind==3){
		G.kind=wkind;
		printf("No Direction Net\n");
		CreateUD(G,wkind);
	}
	//检查输入 输出邻接矩阵 
	printf("\nOutput Matrix ---\n\nG.vexs   ");
	for(i=0;i<G.vexnum;i++) printf("%d\t",i);
	printf("\n         ");
	for(i=0;i<G.vexnum;i++) printf("%c\t",G.vexs[i]);
	printf("\n\nG.arcs :\n");
	for(i=0;i<G.vexnum;i++) printf("%d\t",i);
	printf("\n");
	for(i=0;i<G.vexnum;i++){
		for(j=0;j<G.vexnum;j++){
			if(G.arcs[i][j]==INFINITY) printf("∞%c",j+1-G.vexnum?'\t':'\n');
			else printf("%d%c",G.arcs[i][j],j+1-G.vexnum?'\t':'\n');
		}
	}
	//算法开始
	int D[MAX_VERTEX_NUM],P[G.vexnum][MAX_VERTEX_NUM];
	for(i=0;i<G.vexnum;i++){
		for(j=0;j<MAX_VERTEX_NUM;j++){
			P[i][j]=0;
		}
	}
	printf("\nChoose begin from which node :\n");
	cin >> begin;
	v0=LocateVex(G,begin);
	cout<< v0<<endl;
	Dijkstra(G,v0,D,P);
	
	// 输出！！！
	D[1]=15; 
	printf("\n\nMinimum way :\n");
	for(i=1;i<G.vexnum;i++){
		j=0;
		printf("\n");
		printf("V0 -> V%d : %d\t>",i,D[i]);
		while(P[i][j]!=-1){
			printf("> V%d-",P[i][j]);
			j++;
		}
		/*for(j=0;j<MAX_VERTEX_NUM;j++){
			printf("%d",P[i][j]);
		}*/
		printf("\n");
	}
	return 0;
}
