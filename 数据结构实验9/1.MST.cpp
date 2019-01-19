/****************************************************

Name:              1.MST.h
Auther:            Hawkeye
Date:            2018.11.24
Function:   Minimum - cost Spanning Tree
			Algorithm :
			Prim      ����ķ�㷨
			Kruskal   ��³˹�����㷨
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
	//�����Ϊ v0 �Ķ��������������ͨ�� G ����С������ 
	//adjvex[]���������С�������ı߼� 
	// ���ڴ洢F���ϵ��������飺�ڽӶ������С��
	int i;
	int lowcost[MAX_VERTEX_NUM];                        //���帨������
	for (int j=0; j<G.vexnum; j++) {                    //���ڽӾ���� v0 �г�ʼ��lowcost 
		if (j!=v0){
			lowcost[j] = G.arcs[v0][j];
			adjvex[j] = v0;
		}
		/*else{
			lowcost[j]=0;
		}*/
	}
	adjvex[v0]=v0;
	lowcost[v0] = 0;                                  //�� v0 ���Ϊ���
	/*for(i=0;i<G.vexnum;i++) printf("%c\t",adjvex[i]+65);printf("\n");
	for(i=0;i<G.vexnum;i++) {
		if(lowcost[i]<999999) 
		printf("%d\t",lowcost[i]);
		else printf("��\t");
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
		else printf("��\t");
    }
	printf("\n");*/
	for (int i=0; i<G.vexnum-1; i++){                  // ѭ��n-1�� 
	    MinEdge(lowcost, G.vexnum,adjvex,k,p,num);
	    p[num++]=k;
		//printf("(%c, %c): %d\n", adjvex[k]+65,k+65, lowcost[k]);
		//���������
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
			else printf("��\t");
		}
		printf("\n");*/
	}
}

//��³˹�����㷨
void Kruskal(MGraph &G, VertexType u)    //����ķ�㷨�Ӷ���u��������G����С������T�����T�ĸ����ߡ�
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
			if(set[i]==set[b] && i!=b)    //i!=b��set[b]���ܱ�Ϊset[a],������˺���ĺ�set[b]һ���ľͱ䲻��
				set[i]=set[a];
		}
		set[b]=set[a];    //�����Ķ�����֮���ٸı�set[b]
		}
	}
}//MiniSpanTree_Kruskal

int main(){
	MGraph G;
	int i,j,wkind,v0;
	VertexType begin;
	printf("\nPlease input the kind of graph:\n0 --- DGraph\n1 --- DNet\n2 --- UDGraph\n3 --- UDNet\n");
	/*
	����ͼ0
	������1  ��Ȩֵ���Գ� 
	����ͼ2
	������3  ��Ȩֵ�ҶԳ� 
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
	//������� ����ڽӾ��� 
	printf("\nOutput Matrix ---\n\nG.vexs   ");
	for(i=0;i<G.vexnum;i++) printf("%d\t",i);
	printf("\n         ");
	for(i=0;i<G.vexnum;i++) printf("%c\t",G.vexs[i]);
	printf("\n\nG.arcs :\n");
	for(i=0;i<G.vexnum;i++) printf("%d\t",i);
	printf("\n");
	for(i=0;i<G.vexnum;i++){
		for(j=0;j<G.vexnum;j++){
			if(G.arcs[i][j]==INFINITY) printf("��%c",j+1-G.vexnum?'\t':'\n');
			else printf("%d%c",G.arcs[i][j],j+1-G.vexnum?'\t':'\n');
		}
	}
	//�㷨��ʼ 
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
