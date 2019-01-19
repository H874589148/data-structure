/****************************************************

Name:             arcList.cpp
Auther:            Hawkeye
Date:            2018.11.19
Function:          邻接表 

test data:    6 8 2 abcdef abacbcadaecfdfef

****************************************************/

#include<iostream> 
#include<stdlib.h>
using namespace std;
#define MAX_VERTEX_NUM 20                            //图中顶点数的最大值 
typedef int WeightType;
typedef int GraphKind;
typedef char VertexType;
typedef struct ArcNode {                             //邻接表法的实现 
	int adjvex;
	WeightType weight;
	struct ArcNode *nextarc;
}ArcNode;
typedef struct VertexNode{
	VertexType data;
	ArcNode *firstarc;
} VertexNode, AdjList[MAX_VERTEX_NUM];
typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
	GraphKind kind;
} ALGraph;

int LocateVex(ALGraph G, VertexType v) {                     // 查找顶点 
	for (int i=0; i<G.vexnum; i++)
		if (G.vertices[i].data == v) return i;
	return -1;
}

void CreateGraph(ALGraph &G) {                           //使用邻接表构造无向网 
	//G.kind = UDN;
	printf("Please input the number of node , edge and graph kind:  ");
	cin >> G.vexnum >> G.arcnum >> G.kind;
	int i,j,k;
	printf("\nPlease input every node:\n");
	for (i=0; i<G.vexnum; i++) {
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}
	printf("\nPlease input every edge:\n");
	for (k=0; k<G.arcnum; k++) {
		VertexType vi, vj;
		//WeightType w;
		cin >> vi >> vj ;//>> w;
		i = LocateVex(G, vi);
		j = LocateVex(G, vj);
		ArcNode *p = new ArcNode;
		p->adjvex = j;
		//p->weight = w;
		p->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p;
		if(G.kind==2){
			p=(ArcNode*)malloc(sizeof(ArcNode));
			p->adjvex=i;
			p->nextarc=G.vertices[j].firstarc;
			G.vertices[j].firstarc=p;
		}
	}
}

void PRINT(ALGraph G){
	int i,j,k;
	printf("\n  data firstarc");
	for(i=0;i<G.vexnum;i++){
		printf("\n%d  %c    ->    ",i,G.vertices[i].data);
		ArcNode *p = new ArcNode;
		p=G.vertices[i].firstarc;
		while(p){
			printf("%d->",p->adjvex);
			p=p->nextarc;
		}
	}
}

int main(){
	ALGraph G;
	CreateGraph(G);
	PRINT(G);
	return 0;
}
