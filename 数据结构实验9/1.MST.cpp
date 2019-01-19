/****************************************************

Name:              1.MST.h
Auther:            Hawkeye
Date:            2018.11.24
Function:   Minimum - cost Spanning Tree
			Algorithm :
			Prim      普里姆算法
			Kruskal   克鲁斯卡尔算法
			test data :
			3 7 11
			abcdefg
			ab7bc8ad5bd9be7ce5de15df6ef8eg9fg11

****************************************************/

#include"Graph.h"
#include <iomanip>

void MinEdge(int a[],int v,int parent[],int &k,int p[],int num){
	int i,j,min=INFINITY,flag,c;
    for(i=0;i<num;i++){
    	for(j=0;j<v;j++){
    		flag=1;
    		for(c=0;c<num;c++){
    			if(j==p[c]) flag=0;
			}
			if(flag){
		          if(parent[j]==p[i]){
			        if(a[j]<min && j!=p[i]){
			          min=a[j];
			          k=j;
		            }
		          }
			}
		}
		//printf("k=%dbugs away\n",k);
	}
}

void Prim(MGraph G, int v0, int adjvex[]) {
	//从序号为 v0 的顶点出发，构造连通网 G 的最小生成树 
	//adjvex[]用来存放最小生成树的边集 
	// 用于存储F集合的两个数组：邻接顶点和最小边
	int i;
	int lowcost[MAX_VERTEX_NUM];                        //定义辅助数组
	for (int j=0; j<G.vexnum; j++) {                    //用邻接矩阵的 v0 行初始化lowcost 
		if (j!=v0){
			lowcost[j] = G.arcs[v0][j];
			adjvex[j] = v0;
		}
		/*else{
			lowcost[j]=0;
		}*/
	}
	adjvex[v0]=v0;
	lowcost[v0] = 0;                                  //将 v0 标记为红点
	/*for(i=0;i<G.vexnum;i++) printf("%c\t",adjvex[i]+65);printf("\n");
	for(i=0;i<G.vexnum;i++) {
		if(lowcost[i]<999999) 
		printf("%d\t",lowcost[i]);
		else printf("∞\t");
	}*/
	//printf("\nBeginning\n");
	int num=0,p[G.vexnum];
	int k;
	p[num++]=v0;
/*	MinEdge(lowcost,G.vexnum,adjvex,k,p);
	p[1]=k;
	num=2;
	printf("(%c, %c): %d\n", adjvex[k]+65, k+65,lowcost[k]);
		//lowcost[k] = 0;
	for(int m=0;m<G.vexnum;m++) printf("%c\t",adjvex[m]+65);
	printf("\n");
	for(int m=0;m<G.vexnum;m++) {
	    if(lowcost[m]<999999) 
		   printf("%d\t",lowcost[m]);
		else printf("∞\t");
    }
	printf("\n");*/
	for (int i=0; i<G.vexnum-1; i++){                  // 循环n-1次 
	    MinEdge(lowcost, G.vexnum,adjvex,k,p,num);
	    p[num++]=k;
		//printf("(%c, %c): %d\n", adjvex[k]+65,k+65, lowcost[k]);
		//更改输出：
		printf(">%c%c-", adjvex[k]+65,k+65);
		
		//lowcost[k] = 0;
		for (int j=0; j<G.vexnum; j++){
			if (G.arcs[k][j]<lowcost[j]&&k!=j){
				adjvex[j]=k;
				lowcost[j]=G.arcs[k][j];
			}
		}
		/*for(int m=0;m<G.vexnum;m++) printf("%c\t",adjvex[m]+65);
		printf("\n");
		for(int m=0;m<G.vexnum;m++) {
			if(lowcost[m]<999999) 
			printf("%d\t",lowcost[m]);
			else printf("∞\t");
		}
		printf("\n");*/
	}
}

//克鲁斯卡尔算法
void Kruskal(MGraph &G, VertexType u)    //普里姆算法从顶点u出发构造G的最小生成树T，输出T的各条边。
{
	int set[MAX_VERTEX_NUM],i,j;
	int k=0,a=0,b=0,min=INFINITY;
	for(i=0;i<G.vexnum;i++)
		set[i]=i;
	while(k<G.vexnum-1)
	{
		for(i=0;i<G.vexnum;++i)
		for(j=i+1;j<G.vexnum;++j)
			if(G.arcs[i][j]<min)
			{
				min=G.arcs[i][j];
				a=i;
				b=j;
			}
		min=G.arcs[a][b]=INFINITY;
		if(set[a]!=set[b])
		{
		//cout<<G.vexs[a]<<"  "<<G.vexs[b]<<G.arcs[b][a]<<endl;
		printf("(%c,%c)  %d\n",G.vexs[a]+'A'-'a',G.vexs[b]+'A'-'a',G.arcs[b][a]);
		k++;
		for(i=0;i<G.vexnum;i++)
		{
			if(set[i]==set[b] && i!=b)    //i!=b，set[b]不能变为set[a],如果变了后面的和set[b]一样的就变不了
				set[i]=set[a];
		}
		set[b]=set[a];    //其它的都变了之后，再改变set[b]
		}
	}
}//MiniSpanTree_Kruskal

int main(){
	MGraph G;
	int i,j,wkind,v0;
	VertexType begin;
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
	printf("\nChoose begin from which node :\n");
	int adjvex[G.vexnum];
	for(i=0;i<G.vexnum;i++){
		adjvex[i]=0;
	}
	cin >> begin;
	v0=LocateVex(G,begin);
	//printf("Bugs away%d\n",v0);
	printf("\nPrim algorithm :");
	printf("\n>");
	Prim(G,v0,adjvex);
	printf("\n\nKruskal algorithm :\n");
	Kruskal(G,begin);
	return 0;
}
