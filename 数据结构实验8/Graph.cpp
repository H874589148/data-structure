/****************************************************

Name:             Graph.cpp
Auther:            Hawkeye
Date:            2018.11.12
Function:          图和网 

test data:       0 5 7 abcde
            ab ba be ed da ac cd

****************************************************/
#include"arcMatrix.h"

int main(){
	MGraph G;
	int i,j,wkind;
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
	printf("\nOutput Matrix ---\n\nG.vexs   ");
	for(i=0;i<G.vexnum;i++) printf("%d\t",i);
	printf("\n         ");
	for(i=0;i<G.vexnum;i++) printf("%c\t",G.vexs[i]);
	printf("\n\nG.arcs :\n");
	for(i=0;i<G.vexnum;i++) printf("%d\t",i);
	printf("\n");
	for(i=0;i<G.vexnum;i++){
		for(j=0;j<G.vexnum;j++){
			printf("%d%c",G.arcs[i][j],j+1-G.vexnum?'\t':'\n');
		}
	}
	printf("\n\nDepth First Search Traversal\n\n");
	DFSTraverse(G);
	printf("\nBreadth First Search Traversal\n\n");
	BFSTraverse(G);
	return 0;
}

